/*
 function: string search, tree, table
 */
#define NEED_FILE
#define KEY_WORD
#include "0head.c"

/* --- wordcount --- */
void wordcount(FILE *fp)
{
	int nc, nw, nl, state;
	int c;

	nc = nw = nl = state = 0;
	while ((c = fgetc(fp)) != EOF)
	{
		nc++;
		if (c == '\n')
			nl++;
		if (Isspace(c))
			state = 0;
		else if (state == 0)
		{
			nw++;
			state = 1;
		}
	}
	printf("char: %3d, word: %3d, line: %3d\n", nc, nw, nl);
}

/* ---- String search --- */
int searchstr(const char *x, const char *v[], int n)
{
	int low, high, mid;
	int r;

	low = 0;
	high = n;
	while (low < high)
	{
		mid = low + (high - low) / 2;
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

#define BUF_S 100
void file_key(FILE *fp, const char *key[], int nkey)
{
	char buf[BUF_S];
	int count[nkey];
	int i, r;

	for (i = 0; i < nkey; i++)
		count[i] = 0;
	while (Getword(fp, buf, nkey) != EOF)
		if (Isalpha(buf[0]))
		{
			r = searchstr(buf, key, nkey);
			if (r != -1)
				count[r]++;
		}
	for (i = 0; i < nkey; i++)
		if (count[i] > 0)
			printf("Key: %3d: %s\n", count[i], key[i]);
}

/* --- tree --- */
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
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		r = Strcmp(root->word, word);
		if (r > 0)
			root->left = trupd(root->left, word);
		else if (r < 0)
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
		printf("tree: %3d: %s\n", root->count, root->word);
		trprint(root->right);
	}
}

void file_tree(FILE *fp)
{
	char buf[BUF_S];
	struct tree *root;

	root = NULL;
	while (Getword(fp, buf, BUF_S) != EOF)
		if (Isalpha(buf[0]))
			root = trupd(root, buf);
	trprint(root);
}
#define TREE_OK

/* --- table --- */
struct table
{
	char *word, *def;
	int count;
	struct table *next;
};

unsigned tbhash(char *word, int tsize)
{
	unsigned val;

	for (val = 0; *word != '\0'; word++)
		val = 31 *val + *word;
	return val % tsize;
}

struct table *tbseek(struct table *tlist[], int tsize, char *word)
{
	struct table *p;

	for (p = tlist[tbhash(word, tsize)]; p != NULL; p = p->next)
		if (Strcmp(p->word, word) == 0)
			return p;
	return NULL;
}

struct table *tbupd(struct table *tlist[], int tsize, char *word, char *def)
{
	struct table *p;
	unsigned hval;

	p = tbseek(tlist, tsize, word);
	if (p == NULL)
	{
		p = (struct table *) malloc(sizeof(*p));
		if (p == NULL || (p->word = Strdup(word)) == NULL)
			return NULL;
		p->count = 1;
		hval = tbhash(word, tsize);
		p->next = tlist[hval];
		tlist[hval] = p;
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

void tbprint(struct table *tlist[], int tsize)
{
	struct table *p;
	int i;

	for (i = 0; i < tsize; i++)
		for (p = tlist[i]; p != NULL; p = p->next)
			if (p->count > 0)
				printf("table: %3d: %s\n", p->count, p->word);
}

#define TAB_S 101
void file_table(FILE *fp)
{
	struct table *tlist[TAB_S];
	char buf[BUF_S];
	int i;

	for (i = 0; i < TAB_S; i++)
		tlist[i] = NULL;
	while (Getword(fp, buf, BUF_S) != EOF)
		if (Isalpha(buf[0]))
			tbupd(tlist, TAB_S, buf, "define");
	tbprint(tlist, TAB_S);
}
#define TABLE_OK

	
/*------- test -------*/
void test_search(void)
{
	const char *s[] = 
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
	
	PRN_FUN(searchstr("a", s, n), d);
	PRN_FUN(searchstr("eee", s, n), d);
	PRN_FUN(searchstr("hh", s, n), d);
	PRN_FUN(searchstr("abc", s, n), d);
}
	
void test_keycount(int argc, char *argv[])
{
	FILE *fp;
	extern const char *keyword[];
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
