/* test.c */
#include <stdio.h>  // printf(), fgetc(), fopen()
#include <stdlib.h> // malloc(), free()

void swap(int v[], int i, int j) {
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void quicksort(int v[], int left, int right) {
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
void qksort(int v[], int n){
	quicksort(v, 0, n - 1);
}
int binsearch(int x, int v[], int n){
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
int Isspace(int c) {
	return (c == ' ' || c == '\t' || c == '\n');
}
int Isalpha(int c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int Isdigit(int c) {
	return (c >= '0' && c <= '9');
}
int Isalnum(int c){
	return Isalpha(c) || Isdigit(c);
}
size_t Strlen(const char *s) {
	size_t i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}
char *Strcpy(char *dest, const char *src){
	char *p = dest;

	while ((*dest++ = *src++) != '\0')
		;
	return p;
}
char *Strrev(char *s) {
	char *p, *q, c;

	p = q = s;
	s += Strlen(s);
	for (--s; s > p; --s, ++p)
	{
		c = *s;
		*s = *p;
		*p = c;
	}
	return q;
}
char *Strdup(const char *s) {
	char *p;

	p = (char *) malloc(Strlen(s) + 1);
	if (p == NULL)
		return NULL;
	return Strcpy(p, s);
}
int Strcmp(const char *s, const char *t) {
	for ( ; *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
int Getword(FILE *fp, char *buf, int bsize) {
	int c;
	char *p = buf;

	if (bsize < 2)
		return EOF;
	while (Isspace(c = fgetc(fp)))
		;
	if (c != EOF)
		*buf++ = c;
	if (!Isalpha(c))
	{
		*buf = '\0';
		return c;
	}
	for ( ; --bsize > 1; ++buf)
	{
		*buf = fgetc(fp);
		if (!(Isalnum(*buf) && *buf != '_')) {
			ungetc(*buf, fp);
			break;
		}
	}
	*buf = '\0';
	return *p;
}

struct table {
	char *word, *def;
	int count;
	struct table *next;
};
unsigned Hash(const char *word, int range) {
	unsigned val;

	for (val = 0; *word != '\0'; ++word)
		val = 31 * val + *word;
	return val % range;
}
struct table *tab_seek(struct table *list[], int nlist, const char *word) {
	struct table *p;
	unsigned h = Hash(word, nlist);

	for (p = list[h]; p != NULL; p = p->next)
		if (Strcmp(p->word, word) == 0)
			return p;
	return NULL;
}
struct table *tab_upd(struct table *list[], int nlist, const char *word, const char *def) {
	unsigned h;
	struct table *p;

	p = tab_seek(list, nlist, word);
	if (p == NULL)
	{
		p = (struct table *) malloc(sizeof(*p));
		if (p == NULL || (p->word = Strdup(word)) == NULL)
			return NULL;
		p->count = 1;
		h = Hash(word, nlist);
		p->next = list[h];
		list[h] = p;
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
			printf("Pos:%3d-%d, Count:%3d, Word: %-30s, Def: %s\n", i, j, p->count, p->word, p->def);
}
void tab_free(struct table *list[], int nlist){
	return ;
}
void file_table(FILE *fp) {
	char buf[300];
	int bsize = sizeof(buf) / sizeof(*buf);
	struct table *list[199];
	int nlist = sizeof(list) / sizeof(*list);
	int i;

	for (i = 0; i < nlist; ++i)
		list[i] = NULL;
	while (Getword(fp, buf, bsize) != EOF)
		if (Isalpha(*buf))
			tab_upd(list, nlist, buf, "001122");
	tab_prn(list, nlist);
}
int main(int argc, char *argv[]) {
	FILE *fp;

	if (argc < 2) {
		printf("Usage: command + filename\n");
		return 1;
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Can not open file: %s\n", argv[1]);
		return 2;
	}
	file_table(fp);
	fclose(fp);
	return 0;
}
