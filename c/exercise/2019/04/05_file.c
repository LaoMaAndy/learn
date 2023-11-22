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
	char *p = buf;
	int c;

	while (--size > 0 && (c = fgetc(fp)) != EOF)
		if ((*buf++ = c) == '\n')
			break;
	*buf = '\0';
	if (c == EOF || buf == p)
		return NULL;
	return p;
}
int Fgets2(char *buf, int size, FILE *fp)
{
	buf = Fgets(buf, size, fp);
	return (buf == NULL) ? 0 : Strlen(buf);
}
int Fputs(char *buf, FILE *fp)
{
	int c;

	while ((c = *buf++) != '\0')
		fputc(c, fp);
	return ferror(fp) ? EOF : 1;
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
	double dval;
	char *sval;
	const char *p;

	va_start(ap, fmt);
	for (p = fmt; *p != '\0'; ++p)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch(*++p)
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