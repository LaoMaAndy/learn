#include "template/head.h"

int Getchar(FILE *fp)
{
	static char buf[4096];
	static char *bufp = buf;
	static int n = 0;

	if (n == 0)
	{
		n = read(fp, buf, sizeof(buf));
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
int Getchar2(FILE *fp)
{
	char c;

	return (read(fp, &c, 1) == 1) ? (unsigned char) c : EOF;
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
int Fputs(char *s, FILE *fp)
{
	int c;

	while (c = *s++)
		putc(c, fp);
	return ferror(fp) ? EOF : 1;
}
int Getline2(char *line, int max, FILE *fp)
{
	if (fgets(line, max, fp) == NULL)
		return 0;
	else
		return strlen(line);
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
		Filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				fprintf(stderr, "%s: Can't open %s\n", p, *argv);
				return ;
			}
			else
			{
				Filecopy(fp, stdout);
				fclose(fp);
			}
	if (ferror(stdout))
		fprintf(stderr, "%s: error writing stdout\n", p);
	return ;
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
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}
