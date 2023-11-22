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
char *Fgets(char *line, int n, FILE *fp)
{
	int c;
	char *p = line;

	while (--n > 0 && (c = fgetc(fp)) != EOF)
		if ((*line++ = c) == '\n')
			break;
	*line = '\0';
	return (c == EOF && line == p) ? NULL : p;
}
int Fgets2(char *s, int n, FILE *fp)
{
	if (Fgets(s, n, fp) == NULL)
		return 0;
	return Strlen(s);
}
int Fputs(char *s, FILE *fp)
{
	int c;

	while ((c = *s++) != '\0')
		putc(c, fp);
	return ferror(fp) ? EOF : 1;
}
void Filecopy(FILE *in, FILE *out)
{
	int c;

	while ((c = fgetc(in)) != EOF)
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
					putchar(*p);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}