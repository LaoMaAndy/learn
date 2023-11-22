/* word.c */
#include "template/head.h"

int Getline(FILE *fp, char *buf, size_t bsize)
{
	int c = 0;
	char *p = buf;

	if (bsize < 1)
		return 0;
	while (--bsize > 0 && (c = fgetc(fp)) != EOF && c != '\n')
		*buf++ = c;
	if (c == '\n' || buf > p)
		*buf++ = '\n';
	*buf = '\0';
	return buf - p;
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
		if (!Isalnum(*buf = fgetc(fp)))
		{
			ungetc(*buf, fp);
			break;
		}
	*buf = '\0';
	return *p;
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
	printf("Word count. Char: %3d, word: %3d, line: %3d\n", nc, nw, nl);
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
void file_key(FILE *fp, char *key[], int nkey)
{
	char buf[300];
	int bsize = sizeof(buf) / sizeof(*buf);
	int count[nkey];
	int i;

	for (i = 0; i < nkey; ++i)
		count[i] = 0;
	while (Getword(fp, buf, bsize) != EOF)
		if (Isalpha(buf[0]))
		{
			i = Strsearch(buf, key, nkey);
			if (i != -1)
				++count[i];
		}
	for (i = 0; i < nkey; ++i)
		if (count[i] > 0)
			printf("count: %3d, key_word: %s\n", count[i], key[i]);
}


		
