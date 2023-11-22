#define NEED_FILE_FUNCTION
#define KEY_TABLE
#include "1head.c"

#define WORD_SIZE 100
void wordcount(FILE *fp);

struct kword *keyseek(char *word, struct kword *tab, int n);
void keycount(FILE *fp);

struct tree 
{
	char *word;
	int count;
	struct tree *left;
	struct tree *right;
};
struct tree *tralloc(void);
struct tree *tradd(struct tree *p, char *w);
void trprint(struct tree *p);

struct table
{
	struct table *next;
	char *name;
	char *defn;
	int count;
};
#define HASHSIZE 101
static struct table *hashtab[HASHSIZE];
unsigned Hash(char *s);
struct table *tabseek(char *s);
struct table *tabins(char *name, char *defn);
void tabprint(struct table *p[], int n);

void wordcount(FILE *fp)
{
	int nc, nw, nl, inword;
	int c;

	nc = nw = nl = inword = 0;
	while ((c = fgetc(fp)) != EOF)
	{
		nc++;
		if (c == '\n')
			nl++;
		if (Ispace(c))
			inword = 0;
		else if (inword == 0)
		{
			inword = 1;
			++nw;
		}
	}
	printf("char: %d, word: %d, line: %d\n", nc, nw, nl);
}

struct kword *keyseek(char *word, struct kword *tab, int n)
{
	int cond;
	struct kword *low = &tab[0];
	struct kword *high = &tab[n];
	struct kword *mid;

	while (low < high)
	{
		mid = low + (high - low) / 2;
		if ((cond = Strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return NULL;
}

void keycount(FILE *fp)
{
	char word[WORD_SIZE];
	int n = sizeof(word) / sizeof(word[0]);
	struct kword *p;

	while (Getword(fp, word, n) != EOF)
		if (Isalpha(word[0]))
			if ((p = keyseek(word, keytab, KEY_COUNT)) != NULL)
				p->count++;
	for (p = keytab; p < keytab + KEY_COUNT; p++)
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
}

struct tree *tralloc(void)
{
	return (struct tree *) malloc (sizeof(struct tree));
}

struct tree *tradd(struct tree *p, char *w)
{
	int cond;

	if (p == NULL)
	{
		p = tralloc();
		p->word = Strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} 
	else if ((cond = Strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = tradd(p->left, w);
	else
		p->right = tradd(p->right, w);
	return p;
}

void trprint(struct tree *p)
{
	if (p != NULL)
	{
		trprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		trprint(p->right);
	}
}

unsigned Hash(char *s)
{
	unsigned val;

	for (val = 0; *s != '\0'; s++)
		val = *s + 31 * val;
	return val % HASHSIZE;
}

struct table *tabseek(char *s)
{
	struct table *np;

	for (np = hashtab[Hash(s)]; np != NULL; np = np->next)
		if (Strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

struct table *tabins(char *name, char *defn)
{
	struct table *np;
	unsigned hashval;

	if ((np = tabseek(name)) == NULL)
	{
		np = (struct table *) malloc(sizeof(*np));
		if (np == NULL || (np->name = Strdup(name)) == NULL)
			return NULL;
		hashval = Hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else
	{
		np->count++;
		free((void *) np->defn);
	}
	if ((np->defn = Strdup(defn)) == NULL)
		return NULL;
	return np;
}

void tabprint(struct table *p[], int n)
{
	struct table *t;
	struct table *s;
	int i, j;

	for (i = 0; i < n; i++)
	{
		t = p[i];
		if (t == NULL)
			continue;
		for (s = t, j = 0; s != NULL; s = s->next, j++)
			printf(" (%3d:%2d) %4d : %s\n",i, j, s->count, s->name);
	}
}

void file_table(FILE *fp)
{
	char word[WORD_SIZE];
	int n = sizeof(word) / sizeof(word[0]);

	while (Getword(fp, word, n) != EOF)
		if (Isalpha(word[0]))
			tabins(word, "abc");
	tabprint(hashtab, HASHSIZE);
}

void file_tree(FILE *fp)
{
	char word[WORD_SIZE];
	int n = sizeof(word) / sizeof(word[0]);
	struct tree *root;

	root = NULL;
	while (Getword(fp, word, n) != EOF)
		if (Isalpha(word[0]))
			root = tradd(root, word);
	trprint(root);
}

/*
 * test these function
 */
void test_file(int argc, char *argv[])
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
	printf("---- word count ----\n");
	wordcount(fp);
	
	printf("---- search key word ----\n");
	fseek(fp, 0, SEEK_SET);
	keycount(fp);
	
	printf("---- file tree ----\n");
	fseek(fp, 0, SEEK_SET);
	file_tree(fp);
	
	printf("---- file table ----\n");
	fseek(fp, 0, SEEK_SET);
	file_table(fp);

	fclose(fp);
}

/*
 * Main function.
 */

int main(int argc, char *argv[])
{
	test_file(argc, argv);
	return 0;
}

