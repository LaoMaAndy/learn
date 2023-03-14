/* 
 functions of string search, tree, table
 */
#define NEED_FILE
#define KEY_WORD
#include "0head.c"

void wordcount(FILE *fp)
{
	int nc, nw, nl, state;
	int c;

	nc = nw = nl = state = 0;

	while ((c = fgetc(fp)) != EOF && c != '\n')
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

int Strsearch(const char *s, const char *list[], int n)
{
	int low, high, mid;
	int r;

	low = 0; 
	high = n;
	while (low < high)
	{
		mid = (low + high) / 2;
		r = Strcmp(list[mid], s);
		if (r > 0)
			high = mid;
		else if (r < 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

#define WORD_SIZE 100
void file_key(FILE *fp, const char *list[], int n)
{
	int val[n];
	char buf[WORD_SIZE];
	int i;

	for (i = 0; i < n; i++)
		val[i] = 0;
	while (Getword(fp, buf, WORD_SIZE) != EOF)
		if (Isalpha(buf[0]))
			if((i = Strsearch(buf, list, n)) != -1)
				val[i]++;
	for (i = 0; i < n; i++)
		if (val[i] > 0)
			printf("%3d: %s\n", val[i], list[i]);
}

/*------- tree ------*/
struct tree
{
	char *word;
	int count;
	struct tree *left, *right;
};

struct tree *trupd(struct tree *t, char *word)
{
	int r;

	if (t == NULL)
	{
		t = (struct tree *) malloc(sizeof(*t));
		if (t == NULL)
			return t;
		t->word = Strdup(word);
		if (t->word == NULL)
			return t;
		t->count = 1;
		t->left = t->right = NULL;
	}
	else
	{
		r = Strcmp(word, t->word);
		if (r == 0)
			t->count++;
		else if (r < 0)
			t->left = trupd(t->left, word);
		else
			t->right = trupd(t->right, word);
	}
	return t;
}

void trprint(struct tree *t)
{
	if (t != NULL)
	{
		trprint(t->right);
		printf("%3d: %s\n", t->count, t->word);
		trprint(t->left);
	}
}

void file_tree(FILE *fp)
{
	char buf[WORD_SIZE];
	struct tree *root = NULL;

	while (Getword(fp, buf, WORD_SIZE) != EOF)
		if (Isalpha(buf[0]))
			root = trupd(root, buf);
	trprint(root);
}
#define TREE_OK

/*------- table -------*/
struct table
{
	char *word, *def;
	int count;
	struct table *next;
};

unsigned tbhash(char *str, int size)
{
	unsigned val;

	for (val = 0; *str != '\0'; str++)
		val = val * 31 + *str;
	return val % size;
}

struct table *tbseek(struct table *list[], int size, char *word)
{
	struct table *p;

	for (p = list[tbhash(word, size)]; p != NULL; p = p->next)
		if (Strcmp(p->word, word) == 0)
			return p;
	return NULL;
}

struct table *tbupd(struct table *list[], int size, char *word, char *def)
{
	struct table *p;
	unsigned hval;

	if ((p = tbseek(list, size, word)) == NULL)
	{
		p = (struct table *) malloc(sizeof(*p));
		if (p == NULL || (p->word = Strdup(word)) == NULL)
			return NULL;
		hval = tbhash(word, size);
		p->count = 1;
		p->next = list[hval];
		list[hval] = p;
	}
	else
	{
		p->count++;
		free(p->def);
	}
	p->def = Strdup(def);
	return p;
}

void tbprint(struct table *list[], int size)
{
	int i;
	struct table *p;

	for (i = 0; i < size; i++)
		for (p = list[i]; p != NULL; p = p->next)
			if (p->count > 0)
				printf("%3d: %s\n", p->count, p->word);			
}

#define H_SIZE 100
void file_table(FILE *fp)
{
	struct table *list[H_SIZE];
	char buf[WORD_SIZE];
	int i;

	for (i = 0; i < H_SIZE; i++)
		list[i] = NULL;
	while (Getword(fp, buf, WORD_SIZE) != EOF)
		if (Isalpha(buf[0]))
			tbupd(list, H_SIZE, buf, "test");
	tbprint(list, H_SIZE);
}
#define TABLE_OK


/*------- test -------*/
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
		exit(0);
	}
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
	test_keycount(argc, argv);

	#if defined(TREE_OK)
	test_tree(argc, argv);
	#endif

	#if defined(TABLE_OK)
	//test_table(argc, argv);
	#endif
	return 0;
}
