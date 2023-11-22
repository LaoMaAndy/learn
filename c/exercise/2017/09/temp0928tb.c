/*
 * table. count word
 */
#include "000string.c"

/* duplicate a string , use malloc() */
char *strdup(char *s)
{
	char *p;

	p = (char *) malloc(Strlen(s) + 1);
	if (p != NULL)
		Strcpy(p, s);
	return p;
}
struct nlist
{
	struct nlist *next;
	char *name;
	char *defn;
	int count;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned Hash(char *s)
{
	unsigned val;

	for (val = 0; *s != '\0'; s++)
		val = *s + 31 * val;
	return val % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[Hash(s)]; np != NULL; np = np->next)
		if (Strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL)
	{
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
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
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

void printtab(struct nlist *p[], int n)
{
	struct nlist *t;
	struct nlist *s;
	int i, j;

	for (i = 0; i < n; i++)
	{
		t = p[i];
		if (t == NULL)
			continue;
		for (s = t, j = 0; s != NULL; s = s->next, j++)
			printf("[%3d: %3d] %5d : %s\n",i, j, s->count, s->name);
	}
}
#define MAXWORD 101
int main(int argc, char *argv[])
{
	char word[MAXWORD];

	if (argc == 1)
	{
		printf("usage: command + argument.\n");
		return 0;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Can't open file: %s\n", argv[1]);
		return 0;
	}
	while (Getword(fp, word, MAXWORD) != EOF)
		if (Isalpha(word[0]))
			install(word, "abc");
	printtab(hashtab, HASHSIZE);
	return 0;
}
