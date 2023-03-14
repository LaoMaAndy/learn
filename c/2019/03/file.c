/* file.c */
#include "template/head.h"

int Getchar(void)
{
	static char buf[4096];
	static char *bufp = buf;
	static int n = 0;

	if (n == 0)
	{
		n = read(0, buf, sizeof(buf));
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int Getchar2(void)
{
	char c;

	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
char *Fgets(char *s, int n, FILE *fp)
{
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(fp)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}
int Getline(char *s, int n, FILE *fp)
{
	int c = 0;
	char *p = s;

	while (--n > 0 && (c = fgetc(fp)) != EOF)
		if ((*s++ = c) == '\n')
			break;
	*s = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}
int Getline2(char *line, int max)
{
	if (fgets(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
}
int Fputs(char *s, FILE *fp)
{
	int c;

	while (c = *s++)
		putc(c, fp);
	return ferror(fp) ? EOF : 1;
}
void Filecopy(FILE *in, FILE *out)
{
	int c;

	while ((c = getc(in)) != EOF)
		putc(c, out);
}
void Printf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
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
		default :
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}