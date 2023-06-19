/* word.c */
#include "template/head.h"

int Getline(FILE *fp, char *buf, size_t bsize)
{
	int c = 0;
	char *p = buf;

	if (bsize == 0)
		return 0;
	while (--bsize > 0 && (c = fgetc(fp)) != EOF && c != '\n')
		*buf++ = c;
	if (c == '\n' || buf > p)
		*buf++ = '\n';
	*buf = '\0';
	return p - buf;
}
int Getword(FILE *fp, char *buf, size_t bsize)
{
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
	for ( ; --bsize > 0; ++buf)
	{
		*buf = c = fgetc(fp);
		if (!Isalnum(c))
		{
			ungetc(c, fp);
			break;
		}
	}
	*buf = '\0';
	return *p;
}
int Strsearch(const char *x, char *v[], int n)
{
	int low, high, mid;
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
			state = 1;
			++nw;
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
	while(Getword(fp, buf, bsize) != EOF)
		if (Isalpha(*buf))
			if ((i = Strsearch(buf, key, nkey)) != -1)
				++count[i];
	for (i = 0; i < nkey; ++i)
		if (count[i] > 0)
			printf("Count: %3d, Key word: %s\n", count[i], key[i]);
}

