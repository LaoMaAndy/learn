/*
 string search, tree, table
 */
#define NEED_FILE
#define KEY_WORD
#include "0head.c"

/* ------ word count ------*/
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

/* ------ String search -----*/
int searchstr(const char *word, const char *list[], int n)
{
	int low, high, mid;
	int r;

	low = 0;
	high = n;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		r = Strcmp(list[mid], word);
		if (r > 0)
			high = mid;
		else if (r < 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

#define BU_SIZE 100
void file_key(FILE *fp, const char *list[], int nlist)
{
	int count[nlist];
	int i;
	char buf[BU_SIZE];
	
	for (i = 0; i < nlist; i++)
		count[i] = 0;
	while (Getword(fp, buf, BU_SIZE) != EOF)
		if (Isalpha(buf[0]))
		{
			i = searchstr(buf, list, nlist);
			if (i != -1)
				count[i]++;
		}
	for (i = 0; i < nlist; i++)
		if (count[i] > 0)
			printf("%3d: %s\n", count[i], list[i]);
}

/* ------- tree ------- */
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
		if (root == NULL)
			return NULL;
		root->word = Strdup(word);
		if (root->word == NULL)
			return NULL;
		root->count = 1;
	}
	else
	{
		r = Strcmp(word, root->word);
		if (r == 0)
			root->count++;
		else if (r > 0)
			root->right = trupd(root->right, word);
		else
			root->left = trupd(root->left, word);
	}
	return root;
}

void trprint(struct tree *root)
{
	if (root != NULL)
	{
		trprint(root->left);
		printf("%3d: %s\n", root->count, root->word);
		trprint(root->right);
	}
}

void file_tree(FILE *fp)
{
	char buf[BU_SIZE];
	struct tree *root;

	root = NULL;
	while (Getword(fp, buf, BU_SIZE) != EOF)
		if (Isalpha(buf[0]))
			root = trupd(root, buf);
	trprint(root);
}
#define TREE_OK

/* ------- table ------*/
struct table
{
	char *word;
	char *def;
	int count;
	struct table *next;
};

unsigned tbhash(char *w, int hsize)
{
	unsigned val;

	for (val = 0; *w != '\0'; w++)
		val = val * 31 + *w;
	return val % hsize;
}

struct table *tbseek(struct table *tlist[], int nlist, char *w)
{
	struct table *p;

	for (p = tlist[tbhash(w, nlist)]; p != NULL; p = p->next)
		if (Strcmp(p->word, w) == 0)
			return p;
	return NULL;
}

struct table *tbupd(struct table *tlist[], int nlist, char *word, char *def)
{
	unsigned h;
	struct table *p;

	p = tbseek(tlist, nlist, word);
	if (p == NULL)
	{
		p = (struct table *) malloc(sizeof(*p));
		if (p == NULL || (p->word = Strdup(word)) == NULL)
			return NULL;
		p->count = 1;
		h = tbhash(word, nlist);
		p->next = tlist[h];
		tlist[h] = p;
	}
	else
	{
		p->count++;
		free(p->def);
	}
	p->def = Strdup(def);
	if (p->def == NULL)
		return NULL;
	return p;
}

void tbprint(struct table *tlist[], int nlist)
{
	int n;
	struct table *p;

	for (n = 0; n < nlist; n++)
		for (p = tlist[n]; p != NULL; p = p->next)
			printf("%3d: %s, %s\n", p->count, p->def, p->word);
}

#define TB_SIZE 101
void file_table(FILE *fp)
{
	char buf[BU_SIZE];
	struct table *tlist[TB_SIZE];
	int i;

	for (i = 0; i < TB_SIZE; i++)
		tlist[i] = NULL;
	while (Getword(fp, buf, BU_SIZE) != EOF)
		if (Isalpha(buf[0]))
			tbupd(tlist, TB_SIZE, buf, "define");
	tbprint(tlist, TB_SIZE);
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
