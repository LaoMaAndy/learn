/* word.c */
#include "template/head.h"

int Getline(FILE *fp, char *s, size_t n)
{
	char *p = s;
	int c = 0;

	if (n == 0)
		return 0;
	while (--n != 0 && (c = fgetc(fp)) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n' || s != p)
		*s++ = '\n';
	*s = '\0';
	return s - p;
}
int Getline2(FILE *fp, char *buf, size_t n)
{
	size_t i;
	int c = 0;

	if (n == 0)
		return 0;
	for (i = 0; i < n - 1 && (c = fgetc(fp)) != EOF && c != '\n'; ++i)
		buf[i] = c;
	if (c == '\n' || i != 0)
		buf[i++] = '\n';
	buf[i] = '\0';
	return buf[0];
}
int Getword(FILE *fp, char *s, size_t n)
{
	char *p = s;
	int c;

	if (n < 2)
		return EOF;
	while (Isspace(c = fgetc(fp)))
		;
	if (c != EOF)
		*s++ = c;
	if (!Isalpha(c))
	{
		*s = '\0';
		return c;
	}
	for ( ; --n > 0; ++s)
		if (!Isalnum(*s = fgetc(fp)))
		{
			ungetc(*s, fp);
			break;
		}
	*s = '\0';
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
	printf("Wordcount. Char: %4d, Word; %3d, Line: %3d\n", nc, nw, nl);
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
	char buf[200];
	int bsize = sizeof(buf) / sizeof(*buf);
	int count[nkey];
	int i;

	for (i = 0; i < nkey; ++i)
		count[i] = 0;
	while (Getword(fp, buf, bsize) != EOF)
		if (Isalpha(buf[0]))
		{
			i = Strsearch(buf, key, nkey);
			if(i != -1)
				++count[i];
		}
	printf("Key word count.\n");
	for (i = 0; i < nkey; ++i)
		if (count[i] > 0)
			printf("%3d: %s\n", count[i], key[i]);
}


