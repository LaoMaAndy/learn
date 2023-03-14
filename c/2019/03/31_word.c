/* word.c */
#include "template/head.h"

int Getline(FILE *fp, char *buf, int bsize)
{
	int c;
	char *p = buf;

	while (--bsize > 0 && (c = fgetc(fp)) != EOF && c != '\n')
		*buf++ = c;
	if (c == '\n')
		*buf++ = c;
	*buf = '\0';
	return buf - p;
}
int Getword(FILE *fp, char *buf, int bsize)
{
	int c;
	char *p = buf;

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
		c = fgetc(fp);
		if (c != '_' && !(Isalnum(c)))
		{
			ungetc(c, fp);
			break;
		}
		*buf = c;
	}
	*buf = '\0';
	return *p;
}
int Strsearch(const char *x, char *v[], int n)
{
	int high, low, mid;
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
static void Strswap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void Strsort(char *v[], int left, int right, int (*comp)(const char *, const char *))
{
	int i, last;

	if (left >= right)
		return;
	Strswap(v, left, left + (right - left) / 2);
	last = left;
	for (i = left + 1; i <= right; ++i)
		if ((*comp)(v[i], v[left]) < 0)
			Strswap(v, ++last, i);
	Strswap(v, left, last);
	Strsort(v, left, last - 1, comp);
	Strsort(v, last + 1, right, comp);
}
void Wordcount(FILE *fp)
{
	int nc, nw, nl, state;
	int c;

	nc = nw = nl = state = 0;
	while ((c = fgetc(fp)) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (Isspace(c))
			state = 0;
		else if (state == 0)
		{
			++nw;
			state = 0;
		}
	}
	printf("Word Count. Char: %3d, Word: %3d, Line: %3d\n", nc, nw, nl);
}
void file_key(FILE *fp, char *key[], int nkey)
{
	char buf[300];
	int bsize = sizeof(buf) / sizeof(*buf);
	int count[nkey];
	int i;

	for (i = 0; i < nkey; ++i)
		count[i] = 0;
	while (Getword(fp, buf, bsize) != EOF)
		if (Isalpha(*buf))
			if ((i = Strsearch(buf, key, nkey)) != -1)
				++count[i];
	for (i = 0; i < nkey; ++i)
		if (count[i] > 0)
			printf("count: %3d, Key word: %s\n", count[i], key[i]);
}
