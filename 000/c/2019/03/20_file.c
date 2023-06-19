/* file.c */
#include "template/head.h"
void (*Signal(int sig, void (*handle)(int)))(int);

int Getchar(int fd)
{
	static char buf[4096];
	static char *p = buf;
	static int n = 0;

	if (n == 0)
	{
		n = read(fd, buf, sizeof(buf));
		p = buf;
	}
	return (--n >= 0) ? (unsigned char) *p++ : EOF;
}
int Getchar2(int fd)
{
	char c;

	return (read(fd, &c, 1) == 1) ? (unsigned char) c : EOF;
}
char *Fgets(char *buf, int bsize, FILE *fp)
{
	register int c;
	register char *p;

	p = buf;
	while (--bsize > 0 && (c = getc(fp)) != EOF)
		if((*p++ = c) == '\n')
			break;
	*p = '\0';
	return (c == EOF && p == buf) ? NULL : buf;
}
int Fgets2(char *line, int max, FILE *fp)
{
	if (Fgets(line, max, fp) == NULL)
		return 0;
	else
		return strlen(line);
}
int Fputs(char *s, FILE *fp)
{
	int c;

	while((c = *s++) != '\0')
		putc(c, fp);
	return ferror(fp) ? EOF : 1;
}
void Filecopy(FILE *in, FILE *out)
{
	register int c;

	while ((c = getc(in)) != EOF)
		putc(c, out);
}
void Filecat(int argc, char **argv)
{
	FILE *fp;
	char *p = argv[0];

	if (argc == 1)
	{
		//Filecopy(stdin, stdout);
		printf("FileCat: command + filename + ...\n");
	}
	else
	{
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				fprintf(stderr, "%s: Can't open %s\n", p, *argv);
				return;
			}
			else
			{
				Filecopy(fp, stdout);
				fclose(fp);
			}
	}
	if (ferror(stdout))
		fprintf(stderr, "%s: error writing stdout\n", p);
	return;
}
void Printf(char *fmt, ...)
{
	va_list ap;
	const char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p != '\0'; ++p)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch (*++p)
		{
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval != '\0'; ++sval)
					putchar(*sval);
				break;
			default: 
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}
