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
	printf("char: %3d, word: %3d, line: %3d\n", nc, nw, nl);
}

/*---- String search ----*/
int searchs(const char *dest, const char *list[], int n)
{
	int low, high, mid;
	int r;

	low = 0; 
	high = n;
	while (low < high)
	{
		mid = (low + high) / 2;
		r = Strcmp(list[mid], dest);
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
void file_kword(FILE *fp, const char *list[], int n)
{
	char buf[WORD_SIZE];
	int count[n];
	int i;

	for (i = 0; i < n; i++)
		count[i] = 0;
	while (Getword(fp, buf, WORD_SIZE) != EOF)
		if (Isalpha(buf[0]))
		{
			i = searchs(buf, list, n);
			if (i != -1)
				count[i]++;
		}
	for (i = 0; i < n; i++)
		if (count[i] > 0)
			printf("%3d: %s\n", count[i], list[i]);
}

/* ---- tree ------- */
struct tree
{
	char *word;
	int count;
	struct tree *left, *right;
};

struct tree *trupd(char *word, struct tree *t)
{
	int r;

	if (t == NULL)
	{
		t = (struct tree *) malloc(sizeof(*t));
		if (t == NULL)
			return t;
		t->word = Strdup(word);
		t->count = 1;
		t->left = t->right = NULL;
		printf("new node: %s\n", t->word);
	}
	else
	{
		r = Strcmp(word, t->word);
		if (r == 0)
		{
			printf("Exist node: %s\n", t->word);
			t->count++;
		}
		else if (r < 0)
			t->left = trupd(word, t->left);
		else
			t->right = trupd(word, t->right);
	}
	return t;
}

void trprint(struct tree *t)
{
	if (t != NULL)
	{
		trprint(t->left);
		printf("%3d: %s\n", t->count, t->word);
		trprint(t->right);
	}
}

void file_tree(FILE *fp)
{
	char buf[WORD_SIZE];
	struct tree *t = NULL;

	while (Getword(fp, buf, WORD_SIZE) != EOF)
		if (Isalpha(buf[0]))
			t = trupd(buf, t);
	trprint(t);
}

/* ------- table -------*/
struct table
{
	char *name, *def;
	struct table *next;
	int count;
};

unsigned tbhash(char *s, int tbsize)
{
	unsigned val;
	
	for (val = 0; *s != '\0'; s++)
		val = val * 31 + *s;
	return val % tbsize;
}

struct table *tbseek(char *s, struct table *list[], int size)
{
	struct table *t;

	for (t = list[tbhash(s, size)]; t != NULL; t = t->next)
		if (Strcmp(s, t->name) == 0)
			return t;
	return NULL;
}

struct table *tbupd(char *name, char *def, struct table *list[], int size)
{
	struct table *t;
	unsigned hval;

	t = tbseek(name, list, size);
	if (t == NULL)
	{
		t = (struct table *) malloc(sizeof(*t));
		if (t == NULL || (t->name = Strdup(name)) == NULL)
			return NULL;
		hval = tbhash(name, size);
		t->next = list[hval];
		t->count = 1;
		list[hval] = t;
	}
	else
	{
		t->count++;
		free((void *) t->def);
	}
	t->def = Strdup(def);
	return t;
}

void tbprint(struct table *list[], int size)
{
	int i;
	struct table *s;

	for (i = 0; i < size; i++)
		for (s = list[i]; s != NULL; s = s->next)
			printf("%3d: %s\n", s->count, s->name);
}

#define TB_SIZE 100

void file_table(FILE *fp)
{
	struct table *list[TB_SIZE];
	char buf[WORD_SIZE];
	struct table *p;
	int i;

	for (i = 0; i < TB_SIZE; i++)
		list[i] = NULL;
	while (Getword(fp, buf, WORD_SIZE) != EOF)
		if (Isalpha(buf[0]))
			tbupd(buf, "abc", list, TB_SIZE);
	tbprint(list, TB_SIZE);
}	
	
/* ---------- test -------- */
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
	file_kword(fp, keyword, n);
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
	//test_tree(argc, argv);
	test_table(argc, argv);
	return 0;
}
