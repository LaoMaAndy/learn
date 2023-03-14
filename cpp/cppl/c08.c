// Chapter 8: The UNIX System Interface

// 8.1 File Descriptors

// 8.2 Low Level I/O -- Read and Write

//#include <syscalls.h>  --this is for unix
#include <unistd.h>		// --this is for linux
#include <stdio.h>
int copyin(void)		/* copy input to output */
{
	char buf[BUFSIZ];
	int n;

	while ((n = read(0, buf, BUFSIZ)) > 0)
		write(1, buf, n);
	return 0;
}

/* getchar: unbuffered single character input */
int get_char(void)
{
	char c;

	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int put_char(int c)
{
	return (write(1, &c, 1) == 1) ? 1 : EOF;
}

/* getchar: simple buffered version */
int get_char_buf(void)
{
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;

	if (n == 0)				/* buffer is empty */
	{
		n = read(0, buf, sizeof buf);
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

void test_getchar(void)
{
	int c;

	while ((c = get_char_buf()) != EOF)
		put_char(c);
}

// 8.3 Open, Creat, Close, Unlink
#include <fcntl.h>
#define PERMS 0666		/* RW for owner, group, others */
void myerror(char *, ...);
int mycp(int argc, char *argv[])		/* cp: copy f1 to f2 */
{
	int f1, f2, n;
	char buf[BUFSIZ];

	if (argc != 3)
		myerror("Usage: cp from to");
	if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
		myerror("cp: can't open %s", argv[1]);
	if((f2 = creat(argv[2], PERMS)) == -1)
		myerror("cp: can't create %s, mode %03o", argv[2], PERMS);
	while ((n = read(f1, buf, BUFSIZ)) > 0)
		if (write(f2, buf, n) != n)
			myerror("cp: write error on file %s", argv[2]);
	return 0;
}

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/* error: print an error message and die */
void myerror(char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}

// 8.4 Random Access -- Lseek
/* my_get: read n bytes from position pos */
int get(int fd, long pos, char *buf, int n)
{
	if (lseek(fd, pos, 0) >= 0) 		/* get to pos */
		return read(fd, buf, n);
	else
		return -1;
}

// 8.5 Example--An Implementation of Fopen and Getc


#define TEST(func) printf("Testing function "#func"\n");func()
int main(int argc, char *argv[])
{
	printf("BUFSIZ:\t%d\n", BUFSIZ);
	printf("FOPEN_MAX:\t%d\n", FOPEN_MAX);
	printf("1024 hexdecimal is %x\n", 1024);
	printf("1024k hexdecimal is %x\n", 1024 * 1024);
	//mycp(argc, argv);
	//TEST(test_getchar);
	//TEST(copyin);

	return 0;
}
