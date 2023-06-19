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
	return (--n >= 0) ? (unsigned char) *p++ : EOF;
}
int Getchar2(void)
{
	char c;

	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
char *Fgets(char *buf, int size, FILE *fp)
{
	int c;
	char *p = buf;

	while (--size > 0 && (c = fgetc(fp)) != EOF)
		if ((*buf++ = c) == '\n')
			break;
	*buf = '\0';
	return (c == EOF && p == buf) ? NULL : p;
}
int Fgets2(char *buf, int size, FILE *fp)
{
	if (Fgets(buf, size, fp) == NULL)
		return 0;
	return strlen(buf);
}
int Fputs(const char *s, FILE *fp)
{
	int c;

	while ((c = (unsigned char) *s++) != '\0')
		fputc(c, fp);
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
	int ival;
	double fval;
	const char *p, *sval;

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
				for (sval = va_arg(ap, const char *); *sval != '\0'; ++sval)
					putchar(*sval);
				break;
			default :
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}