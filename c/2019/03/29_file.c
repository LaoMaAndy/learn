/* file.c */
#include "template/head.h"

int Getchar(void)
{
	static char buf[4096];
	static char *p = buf;
	static int n = 0;

	if (n == 0)
	{
		n = read(0, buf, sizeof(buf));
		p = buf;
	}
	return (--n > 0) ? (unsigned char) *p++ : EOF;
}
int Getchar2(void)
{
	char c;

	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
