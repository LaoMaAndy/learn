/* file.c */
#include "template/head.h"

int Getchar(void)
{
	static unsigned char buf[4096];
	static unsigned char *p = buf;
	static int n = 0;

	if (n == 0)
	{
		n = read(0, buf, sizeof(buf));
		p = buf;
	}
	return (--n >= 0) ? *p++ : EOF;
}
int Getchar2(void)
{
	unsigned char c;

	return (read(0, &c, 1) == 1) ? c : EOF;
}
char *Fgets(char *buf, int size, FILE *fp)
{
	int c;
	char *p = buf;

	while (--size > 0 && (c = fgetc(fp)) != EOF)
		if ((*buf++ = c) == '\n')
			break;
	*buf = '\0';
	return (c == EOF && buf == p) ? NULL : p;
}
int Fgets2(char *buf, int size, FILE *fp)
{
	char *p = Fgets(buf, size, fp);

	return (p == NULL) ? 0 : strlen(p);
}
int Fputs(char *s, FILE *fp)
{
	unsigned char *p = (unsigned char *) s;
	for ( ; *p != '\0'; ++p)
		fputc(*p, fp);
	return (ferror(fp) == 0) ? 1 : EOF;
}
void Filecopy(FILE *in, FILE *out)
{
	int c;

	while ((c = fgetc(in)) != EOF)
		fputc(c, out);
}
void Printf(const char *fmt, ...)
{
	va_list ap;
	const char *p, *sval;
	int ival;
	double fval;

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
				fval = va_arg(ap, double);
				printf("%f", fval);
				break;
			case 's':
				sval = va_arg(ap, const char *);
				for ( ; *sval != '\0'; ++sval)
					putchar (*sval);
				break;
			default :
				putchar(*p);
		}
	}
	va_end(ap);
}