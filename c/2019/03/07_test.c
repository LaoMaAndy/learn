/* test.c */
#include <stdio.h> 			//printf(), io function
#include <stdlib.h> 		//malloc(), free()
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void quicksort(int v[], int left, int right)
{
	int last, i;

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; ++i)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	quicksort(v, left, last - 1);
	quicksort(v, last + 1, right);
}
void qksort(int v[], int n)
{
	quicksort(v, 0, n - 1);
}
int binsearch(int x, int v[], int n)
{
	int high, low, mid;
	int r;

	low = 0;
	high = n;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		r = v[mid] - x;
		if (r > 0)
			high = mid;
		else if (r < 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

/* functions in type.h */
int Isalpha(int c);
int Isspace(int c);
int Isdigit(int c);
int Isalnum(int c);

/* functions in string.h */
size_t Strlen(const char *s);
char *Strcpy(char *dest, const char *s);
int Strcmp(const char *s, const char *t);

#include <string.h>
#include <ctype.h>
/* define by yourself */
char *Strdup(const char *s)
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);
	if (p == NULL)
		return p;
	return strcpy(p, s);
}

int Getword(FILE *fp, char *buf, int bsize)
{
	int c;
	char *p = buf;

	if (bsize < 2)
		return EOF;
	while(isspace(c = fgetc(fp)))
		;
	if (c != EOF)
		*buf++ = c;
	if (!isalpha(c))
	{
		*buf = '\0';
		return c;
	}
	for (  ; --bsize > 1; ++buf)
	{
		*buf = fgetc(fp);
		if (!(isalnum(*buf) || *buf == '_'))
		{
			ungetc(*buf, fp);
			break;
		}
	}
	*buf = '\0';
	return *p;
}
char *Strtoup(char *s)
{
	char *p = s;

	for ( ; *s != '\0'; ++s)
		*s = toupper(*s);
	return p;
}

struct table 
{
	char *word, *def;
	int count;
	struct table *next;
} ;
//typedef struct table Tab;
unsigned Hash(const char *word, int size)
{
	unsigned val;

	for (val = 0; *word != '\0'; ++word)
		val = 31 * val + *word;
	return val % size;
}
struct table *tab_find(struct table *list[], int nlist, const char *word)
{
	unsigned h = Hash(word, nlist);
	struct table *p;

	for (p = list[h]; p != NULL; p = p->next)
		if (strcmp(p->word, word) == 0)
			return p;
	return NULL;
}
struct table *tab_upd(struct table *list[], int nlist, const char *word, const char *def)
{
	unsigned h;
	struct table *p;

	p = tab_find(list, nlist, word);
	if (p == NULL)
	{
		p = (struct table *) malloc(sizeof(*p));
		if (p == NULL || (p->word = Strdup(word)) == NULL)
			return NULL;
		h = Hash(word, nlist);
		p->next = list[h];
		list[h] = p;
		p->count = 1;
	}
	else
	{
		++p->count;
		free(p->def);
	}
	if ((p->def = Strdup(def)) == NULL)
		return NULL;
	return p;
}
void tab_prn(struct table *list[], int nlist)
{
	int i, j;
	struct table *p;

	for (i = 0; i < nlist; ++i)
		for (p = list[i], j = 1; p != NULL; p = p->next, ++j)
			printf("Pos:%3d-%d, Count: %3d, Word: %-30s, Def: %s\n", i, j, p->count, p->word, p->def);
}
void file_table(FILE *fp)
{
	char buf[300];
	int bsize = sizeof(buf) / sizeof(*buf);
	struct table *list[199];
	int nlist = sizeof(list) / sizeof(*list);
	int i;

	for (i = 0; i < nlist; ++i)
		list[i] = NULL;
	while (Getword(fp, buf, bsize) != EOF)
		if (isalpha(*buf))
			tab_upd(list, nlist, buf, Strtoup(Strdup(buf)));
	tab_prn(list, nlist);
}
// main function
int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
	{
		printf("Usage: Command + filename\n");
		return 1;
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Can not open file %s\n", argv[1]);
		return 2;
	}
	file_table(fp);
	return 0;
}

