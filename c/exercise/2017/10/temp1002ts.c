/*
 functions of binsearch, binary tree, hash table
 */
#define NEED_FILE
#define KEY_WORD
#include "0head.c"
/*------- word count ----------*/
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
			state = 1;
			nw++;
		}
	}
	printf("char: %d, word: %d, line: %d\n", nc, nw, nl);
}

/*------ word search ----------*/
int searchs(char *word, char *list[], int n)
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

#define WORD_SIZE 100
void keycount(FILE *fp, char *tab[], int n)
{
	char buf[WORD_SIZE]; 
	int count[n], i; 

	for (i = 0; i < n; i++)
		count[i] = 0;
	while ((Getword(fp, buf, WORD_SIZE)) != EOF)
		if (Isalpha(buf[0]))
			if ((i = searchs(buf, tab, n)) != -1)
				count[i]++;
	for (i = 0; i < n; i++)
		if (count[i] > 0)
			printf("%3d : %s\n", count[i], tab[i]);
}

/*-------- tree add, print --------*/
struct tree
{
	char *word;
	int count; 
	struct tree *left, *right; 
}; 

struct tree *tralloc(void) 
{
	return (struct tree *) malloc(sizeof(struct tree));
}

struct tree *trupd(struct tree *t, char *word)
{
	if (t == NULL)
	{
		t = tralloc();
		if (t == NULL)
			return t;
		t->word = Strdup(word);
		t->count = 1;
		t->left = t->right = NULL;
	}
	else
	{
		int r = Strcmp(word, t->word);
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
		trprint(t->left);
		printf("%4d: %s\n", t->count, t->word);
		trprint(t->right);
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

/*------- table ---------*/
struct table
{
	struct table *next;
	char *name;
	char *def;
	int count;
};
#define TB_SIZE 100

unsigned tbhash(char *s, int size) 
{ 
	unsigned val; 

	for (val = 0; *s != '\0'; s++)
		val = *s + 31 * val;
	return val % size;
}
	
struct table *tbseek(char *s, struct table *tab[], int tabsize)
{
	struct table *t;

	for (t = tab[tbhash(s, tabsize)]; t != NULL; t = t->next)
		if (Strcmp(s, t->name) == 0)
			return t;
	return NULL;
}

struct table *tbupd(char *name, char *def, struct table *tab[], int tabsize)
{
	struct table *t;
	unsigned hval;

	t = tbseek(name, tab, tabsize);
	if (t == NULL)
	{
		t = (struct table *) malloc(sizeof(*t));
		if (t == NULL || (t->name = Strdup(name)) == NULL)
			return NULL;
		hval = tbhash(name, tabsize);
		t->next = tab[hval];
		t->count = 1;
		tab[hval] = t;
	}
	else
	{
		t->count++;
		free((void *) t->def);
	}
	t->def = Strdup(def);
	return t;
}

void tbprint(struct table *tab[], int tabsize)
{
	struct table **p;
	struct table *s;

	for (p = tab; p - tab < tabsize; p++)
		for (s = *p; s != NULL; s = s->next)
			printf("%3d: %s\n", s->count, s->name);
}
		
void file_table(FILE *fp)
{
	struct table *tab[TB_SIZE];
	char buf[WORD_SIZE];
	struct table *p;
	int i;

	for (i = 0; i < TB_SIZE; i++)
		tab[i] = NULL;
	while (Getword(fp, buf, WORD_SIZE) != EOF)
		if (Isalpha(buf[0]))
			tbupd(buf, "abc", tab, TB_SIZE);
	tbprint(tab, TB_SIZE);
}

/* ---------- test -------- */
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
		exit(0);
	}
	printf("---- word count ----\n");
	wordcount(fp);
	
	printf("---- search key word ----\n");
	fseek(fp, 0, SEEK_SET);
	keycount(fp, keyword, n);
	fclose(fp);
}

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

int main(int argc, char *argv[])
{
	test_keycount(argc, argv);
	test_tree(argc, argv);
	test_table(argc, argv);
	return 0;
}
