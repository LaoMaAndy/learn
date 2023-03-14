/* word.c */
#include "template/head.h"

int Getline(FILE *fp, char *buf, int size)
{
	char *p = buf;
	int c;

	while (--size > 0 && (c = fgetc(fp)) != EOF)
		if ((*buf++ = c) == '\n')
			break;
	*buf = '\0';
	return buf - p;
}
int Getword(FILE *fp, char *buf, int size)
{
	char *p = buf;
	int c;

	while (Isspace(c = fgetc(fp)))
		;
	if (c != EOF)
		*buf++ = c;
	if (!Isalpha(c))
	{
		*buf = '\0';
		return c;
	}
	for ( ; --size > 1; ++buf)
	{
		c = *buf = fgetc(fp);
		if (!Isalnum(c) && (c != '_'))
		{
			ungetc(c, fp);
			break;
		}
	}
	*buf = '\0';
	return *p;
}
void Strswap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
int Strsearch(const char *x, char *v[], int n)
{
	int high, low, mid;
	int r;

	high = n;
	low = 0;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		r = strcmp(v[mid], x);
		if (r > 0)
			high = mid;
		else if (r < 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
void Strsort(char *v[], int left, int right)
{
	int last, i;

	if (left >= right)
		return;
	Strswap(v, left, (left / 2 + right / 2));
	last = left;
	for (i = left + 1; i <= right; ++i)
		if (strcmp(v[i], v[left]) < 0)
			Strswap(v, ++last, i);
	Strswap(v, last, left);
	Strsort(v, left, last - 1);
	Strsort(v, last + 1, right);
}
void file_key(FILE *fp, char *key[], int nkey)
{
	int i;
	int count[nkey];
	char buf[300];
	int size = sizeof(buf);

	for (i = 0; i < nkey; ++i)
		count[i] = 0;
	while (Getword(fp, buf, size) != EOF)
		if (Isalpha(*buf))
			if ((i = Strsearch(buf, key, nkey)) != -1)
				++count[i];
	for (i = 0; i < nkey; ++i)
		if (count[i] > 0)
			printf("count: %3d, key word: %s\n", count[i], key[i]);
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
			state = 1;
		}
	}
	printf("Word Count. Char: %3d, word: %3d, Line: %3d\n", nc, nw, nl);
}