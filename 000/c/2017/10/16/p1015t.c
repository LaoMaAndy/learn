/*
function: word count, word search, tree, table
*/
#define NEED_FILE
#define KEY_WORD
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
			state = 1;
			nw++;
		}
	}
	printf("count. char: %3d, word: %3d, line: %3d\n", nc, nw, nl);
}
/*** key word ***/
int strsearch(const char *x, char *v[], int n)
{
	int low, high, mid;
	int r;
	low = 0;
	high = n;
	while (low < high)
	{
		mid = (low + high) / 2;
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
void file_key(FILE *fp, char *key[], int nkey)
{
	char buf[100];
	int bsize = sizeof(buf) / sizeof(buf[0]);
	int count[nkey];
	int n;

	for (n = 0; n < nkey; n++)
		count[n] = 0;
	while (Getword(fp, buf, bsize) != EOF)
		if (Isalpha(buf[0]))
		{
			n = strsearch(buf, key, nkey);
			if (n != -1)
				count[n]++;
		}
	for (n = 0; n < nkey; n++)
		if (count[n] > 0)
			printf("Key %3d: %s\n", count[n], key[n]);
}
/*** tree ***/
struct tree
{
	char *word;
	int count;
	struct tree *left, *right;
};
struct tree *trupd(struct tree *root, char *word)
{
	int r;
	if (root == NULL)
	{
		root = (struct tree *) malloc(sizeof(*root));
		if (root == NULL || (root->word = Strdup(word)) == NULL)
			return NULL;
		root->count = 1;
		root->left = root->right = NULL;
	}
	else
	{
		r = Strcmp(word, root->word);
		if (r < 0)
			root->left = trupd(root->left, word);
		else if (r > 0)
			root->right = trupd(root->right, word);
		else
			root->count++;
	}
	return root;
}
void trprint(struct tree *root)
{
	if (root != NULL)
	{
		trprint(root->left);
		printf("tree %3d %s\n", root->count, root->word);
		trprint(root->right);
	}
}
void file_tree(FILE *fp)
{
	char buf[100];
	int bsize = sizeof(buf) / sizeof(buf[0]);
	struct tree *root = NULL;
	while(Getword(fp, buf, bsize) != EOF)
		if (Isalpha(buf[0]))
			root = trupd(root, buf);
	trprint(root);
}
#define TREE_OK
/*** table ***/
struct table
{
	char *word, *def;
	int count;
	struct table *next;
};
unsigned thash(char *word, int size)
{
	unsigned val;
	for (val = 0; *word != '\0'; word++)
		val = val * 31 + *word;
	return val % size;
}
struct table *tbseek(struct table *list[], int tsize, char *word)
{
	struct table *p;
	for (p = list[thash(word, tsize)]; p != NULL; p = p->next)
		if (Strcmp(p->word, word) == 0)
			return p;
	return NULL;
}
struct table *tbupd(struct table *list[], int tsize, char *word, char *def)
{
	struct table *p;
	unsigned hval;
	p = tbseek(list, tsize, word);
	if (p == NULL)
	{
		p = (struct table *) malloc(sizeof(*p));
		if (p == NULL || (p->word = Strdup(word)) == NULL)
			return NULL;
		p->count = 1;
		hval = thash(word, tsize);
		p->next = list[hval];
		list[hval] = p;
	}
	else
	{
		p->count++;
		free(p->def);
	}
	if ((p->def = Strdup(def)) == NULL)
		return NULL;
	return p;
}
void tbprint(struct table *list[], int tsize)
{
	int n, m;
	struct table *p;
	for (n = 0; n < tsize; n++)
		for (p = list[n], m = 1; p != NULL; p = p->next, m++)
			printf("table %3d: %s\n", p->count, p->word);
}
void file_table(FILE *fp)
{
	struct table *list[101];
	int tsize = sizeof(list) / sizeof(list[0]);
	char buf[100];
	char bsize = sizeof(buf) / sizeof(buf[0]);
	int n;
	for (n = 0; n < tsize; n++)
		list[n] = NULL;
	while (Getword(fp, buf, bsize) != EOF)
		if (Isalpha(buf[0]))
			tbupd(list, tsize, buf, "define");
	tbprint(list, tsize);
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