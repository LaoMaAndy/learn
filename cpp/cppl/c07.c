// Chapter 7: INput and Output

// 7.1 Standard Input and Output

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int lower(void)			/* lower: convert input to lower case */
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(tolower(c));
	return 0;
}

// 7.2 Formatted Output -- Printf

// 7.3 Variable-length Argument Lists
#include <stdarg.h>

/* minpritf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
	va_list ap; 		/* points to each unnamed arg in turn */
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);	/* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			putchar (*p);
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
				for (sval = va_arg(ap, char*); *sval; sval++)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);		/* clean up when done */
}

void test_minprintf(void)
{
	int d = 210;
	double f = 12.12;

	minprintf("%s: %d multi 12.12 is: %f\n", "Test minprintf", d, d * f);
}

// 7.4 Formatted Input -- Scanf
/* rudimentary calculator */
void rudi(void)
{
	double sum, v;

	sum = 0;
	while (scanf("%lf", &v) == 1)
		printf("\t%.2f\n", sum +=v);
}

// 7.5 File Access
/* cat: concatenate files, version 1 */
int cat_v1(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if (argc == 1)				/* no args; copy standard input */
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				printf("cat: can't open %s\n", *argv);
				return 1;
			}
			else
			{
				filecopy(fp, stdout);
				fclose(fp);
			}
	return 0;
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}

// 7.6 Error Handling -- Stderr and Exit
#include <stdlib.h>
/* cat: concatenate files, version 2 */
int cat_v2(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);
	char *prog = argv[0];		/* program name for errors */

	if (argc == 1)				/* no args; copy standard input */
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			}
			else
			{
				filecopy(fp, stdout);
				fclose(fp);
			}
	if (ferror(stdout))
	{
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}
	exit(0);
}

// 7.7 Line Input and Output
/* fgets: get at most n-1 chars, plus a null from iop */
char *fgets_my(char *s, int n, FILE *iop)
{
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

/* fputs: put string s on file iop */
int fputs_my(char *s, FILE *iop)
{
	int c;

	while (c = *s++)
		putc(c, iop);
	return ferror(iop) ? EOF : 1;
}

/*getline: read a line, return length */
int get_line(char *line, int max)
{
	if (fgets(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
}

// 7.8 Miscellaneous Functions
// 7.8.1 String OPerations
// 7.8.2 Character Class Testing and Conversion
// 7.8.3 Ungetc
// 7.8.4 Command Execution
// 7.8.5 Storage Management
// 7.8.6 Mathematical Functions
// 7.8.7 Random Number Generation

#define TEST(func) printf("Testing function "#func" :\n");func()
int main(int argc, char *argv[])
{
	cat_v2(argc, argv);
	//cat_v1(argc, argv);
	//TEST(rudi);
	//TEST(test_minprintf);
	//TEST(lower);
	return 0;
}

