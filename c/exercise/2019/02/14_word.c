/* word.c */
#include "template/head.h"

int Getline(FILE *fp, char *buf, size_t bsize)
{
	int c = 0;
	char *p = buf;

	if (bsize < 1)
		return 0;
	while (--bsize != 0 ||
