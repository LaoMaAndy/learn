#define NEED_FILE_FUNCTION
#define KEY_TABLE
#include "0head.c"

/*
 array search, binary tree, table
 */
void wordcount(FILE *fp);
struct kword *keyseek(char *word, struct kword *tab, int n);
void keycount(FILE *fp, struct kword *tab, int n);

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

struct tree *tradd(struct tree *p, char *word)
{
	int c;

	if (p == 0)
	{
		if ((p = tralloc()) == 0)
			return (struct tree *) 0;
		if (Strdup(p->word, word) == (char *) 0)
			return (struct tree *) 0;
		p->count += 1;
		p->left  = p->right = (Struct tree *) 0;
	}
	else if ((c = Strcmp(word, p->word)) == 0)
		p->count++;
	else if (c < 0)
		p->left = tradd(p->left, word);
	else
		p->right = tradd(p->right, word);
	return p;
}
		
void trprint(struct tree *p)
{
	if (p != (struct tree *) 0)
	{
		trprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		trprintf(p->right);
	}
}

void file_tree(FILE *fp)
{
}


struct table
{
	struct table *next;
	char *name;
	char *def;
	int count;
};
#define H_SIZE 101
static struct table *htab[H_SIZE];
unsigned hash(char *s);
struct table *tabseek(char *s);
struct table *tabins(char *name, char *def);
void tabprint(struct table *t[], int n);
void file_table(FILE *fp);

/*
 implementation
 */

void wordcount(FILE *fp)
{
	int nc, nw, nl, state;
	int c;

	nc = nw = nl = state = 0;
	while ((c = getc(fp)) != EOF)
	{
		nc++;
		if (c == '\n')
			nl++;
		if (Ispace(c))
			state = 1;
		else if (state == 0)
		{
			state = 1;
			nw++;
		}
	}
	printf("char: %3d, word: %3d, line: %3d\n", nc, nw, nl);
}

struct kword *keyseek(char *word, struct kword *tab, int n)
{
	struct kword *low, *high, *mid;
	int r;

	low = tab;
	high = tab + n;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (r = Strcmp(mid->word, word) > 0)
			high = mid;
		else if (r < 0)
			low = mid + 1;
		else
			return mid;
	}
	return (struct kword *) 0;
}

void keycount(FILE *fp, struct kword *tab, int n)
{
	char word[100];
	int i = sizeof(word) / sizeof(word[0]);
	struct kword *p;

	while (Getword(fp, word, i) != EOF)
		if (Isalpha(word[0]))
			if ((p = keyseek(word, tab, n)) != 0)
				p->count++;
	for (p = tab; p < tab + n; p++)
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
}

void test_keycount(int argc, char *argv[])
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
	keycount(fp, keytab, KEY_COUNT);
	fclose(fp);
}

/*
void test_tree_table(int argc, char *argv[])
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
*/

/*
 * Main function.
 */

int main(int argc, char *argv[])
{
	test_keycount(argc, argv);
	return 0;
}

