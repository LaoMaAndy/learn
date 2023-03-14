/*
 * word.c
 */
#include "template/head.h"

int Getline(char *buf, int size, FILE *fp)
{
	int c;
	char *p = buf;

	while (--size > 0 && (c = fgetc(fp)) != EOF)
		if ((*buf++ = c) == '\n')
			break;
	*buf = '\0';
	return buf - p;
}
int Getword(char *buf, int size, FILE *fp)
{
	char *p = buf;
	int c;

	while (isspace(c = fgetc(fp)))
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
		*buf = c = fgetc(fp);
		if ()
	}
}
