/* file.c */
#include "template/head.h"
void (*Signal(int sig, void (*handle)(int)))(int);

ing Getchar(int fd)
{
	static char buf[4096];
	static char *p = buf;
	static int n = 0;

	if (n == 0)
	{
		n = read(fd, buf, sizeof(buf));
		p = buf;
	}
	return (--n >= 0) ? (unsigned char ) *p++ : EOF;
}
