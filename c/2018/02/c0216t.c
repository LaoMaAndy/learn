/*
function: word count, file key word, file tree, file table 
*/
#define NEED_FILE
#include "0head.c"

void wordcount(FILE *fp)
{
	int nc, nw, nl, state;
	int c;

	nc = nw = nl = state = 0;
	while ((c = fgetc(fp)) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (Isspace(c))
			state = 0;
		else if (state == 0)
		{
			++nw;
			state = 1;
		}
	}
	printf("Word count. char: %3d, word: %3d, line: %3d\n", nc, nw, nl);
}
int strsearch(const char *x, char *v[], int n)
{
	int low, high, mid;
	int r;

	low = 0;
	high = n;
	while (low < high)
	{
		mid = (high + low) / 2;
		r = Strcmp(v[mid], x);
		if (r > 0)
			high = mid;
		else if (r < 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
#define BUF_SIZE 200
void file_key(FILE *fp, char *key[], int nkey)
{
	char buffer[BUF_SIZE];
	int nbuf = sizeof(buffer) / sizeof(*buffer);
	int count[nkey], i;

	for (i = 0; i < nkey; ++i)
		count[i] = 0;
	while (Getword(fp, buffer, nbuf) != EOF)
		if (Isalpha(buffer[0]))
			if ((i = strsearch(buffer, key, nkey)) != -1)
				++count[i];
	printf("File key word: \n");
	for (i = 0; i < nkey; ++i)
		printf("%3d: %s\n", count[i], key[i]);
}


/* file tree */
struct tree
{
	struct tree *left, *right;
	int count;
	char *word;
};
struct tree *trupd(struct tree *root, const char *word)
{
	int r;

	if (root == NULL)
	{
		root = (struct tree *) malloc(sizeof(*root));
		if (root == NULL || (root->word = Strdup(word)) == NULL)
			return NULL;
		root->left = root->right = NULL;
		root->count = 1;
	}
	else
	{
		r = Strcmp(word, root->word);
		if (r < 0)
			root->left = trupd(root->left, word);
		else if (r > 0)
			root->right = trupd(root->right, word);
		else
			++root->count;
	}
	return root;
}
void trprn(struct tree *root)
{
	if (root != NULL)
	{
		trprn(root->left);
		printf("file tree. %3d: %s\n", root->count, root->word);
		trprn(root->right);
	}
}
void file_tree(FILE *fp)
{
	char buffer[BUF_SIZE];
	int bsize = sizeof(buffer) / sizeof(*buffer);
	struct tree *root = NULL;
	
	while (Getword(fp, buffer, bsize) != EOF)
		if (Isalpha(buffer[0]))
			root = trupd(root, buffer);
	trprn(root);
}
#define TREE_OK

/* file table */
struct table 
{
	char *word, *def;
	struct table *next;
	int count;
};
unsigned hash(const char *word, int size)
{
	unsigned val;

	for (val = 0; *word != '\0'; ++word)
		val = 31 * val + *word;
	return val % size;
}	
struct table *tabseek(struct table *list[], int nlist, const char *word)
{
	struct table *p;

	for (p = list[hash(word, nlist)]; p != NULL; p = p->next)
		if (Strcmp(p->word, word) == 0)
			return p;
	return NULL;
}
struct table *tabupd(struct table *list[], int nlist, const char *word, const char *def)
{
	struct table *p;
	unsigned h;

	p = tabseek(list, nlist, word);
	if (p == NULL)
	{
		p = (struct table *) malloc(sizeof(*p));
		if (p == NULL || (p->word = Strdup(word)) == NULL)
			return NULL;
		p->count = 1;
		h = hash(word, nlist);
		p->next = list[h];
		list[h] = p;
	}
	else
	{
		free(p->def);
		++p->count;
	}
	if ((p->def = Strdup(def)) == NULL)
		return NULL;
	return p;
}
void tabprn(struct table *list[], int n)
{
	int i, j;
	struct table *p;

	for (i = 0; i < n; ++i)
		for (p = list[i], j = 1; p != NULL; p = p->next, ++j)
			printf("[%3d-%2d] %3d: %s\n", i, j, p->count, p->word);
}
void file_table(FILE *fp)
{
	struct table *list[199];
	int nlist = sizeof(list) / sizeof(*list);
	int i;
	char buffer[BUF_SIZE];
	int bsize = sizeof(buffer) / sizeof(*buffer);

	for (i = 0; i < nlist; ++i)
		list[i] = NULL;
	while (Getword(fp, buffer, bsize) != EOF)
		if (Isalpha(buffer[0]))
			tabupd(list, nlist, buffer, "define");
	tabprn(list, nlist);
}
#define TABLE_OK

/*------- test -------*/
void test_search(void)
{
	char *s[] = 
	{
		"a",
		"bbbbbb",
		"ccccccc",
		"dddd",
		"eee",
		"fff",
		"gg",
		"hh"
	};
	int n = sizeof(s) / sizeof(s[0]);
	int i;

	printf("String: \n");
	for (i = 0; i < n; i++)
		printf("%2d: %s\n", i, s[i]);
	
	PRN_FUN(strsearch("a", s, n), d);
	PRN_FUN(strsearch("eee", s, n), d);
	PRN_FUN(strsearch("hh", s, n), d);
	PRN_FUN(strsearch("abc", s, n), d);
}
	
void test_keycount(int argc, char *argv[])
{
	FILE *fp;
	extern char *keyword[];
	int n = sizeof(keyword) / sizeof(keyword[0]);

	if (argc == 1)
	{
		printf("usage: command + argument.\n");
		exit(0);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Can't open file: %s\n", argv[1]);
		exit(0); }
	printf("---- word count ----\n");
	wordcount(fp);
	
	printf("---- search key word ----\n");
	fseek(fp, 0, SEEK_SET);
	file_key(fp, keyword, n);
	fclose(fp);
}

#if defined(TREE_OK)
void test_tree(int argc, char *argv[])
{
	FILE *fp;

	if (argc == 1)
	{
		printf("usage: command + argument.\n");
		exit(0);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Can't open file: %s\n", argv[1]);
		exit(0);
	}
	printf("---- file tree ----\n");
	file_tree(fp);
	fclose(fp);
}
#endif
/* end of #if defined(TREE_OK) */

#if defined(TABLE_OK)
void test_table(int argc, char *argv[])
{
	FILE *fp;

	if (argc == 1)
	{
		printf("usage: command + argument.\n");
		exit(0);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Can't open file: %s\n", argv[1]);
		exit(0);
	}
	printf("---- file table ----\n");
	file_table(fp);
	fclose(fp);
}
#endif
/* end of #if defined(TABLE_OK) */

int main(int argc, char *argv[])
{
	test_search();
	test_keycount(argc, argv);

	#if defined(TREE_OK)
	test_tree(argc, argv);
	#endif

	#if defined(TABLE_OK)
	test_table(argc, argv);
	#endif

	return 0;
}
