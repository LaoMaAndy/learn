#include <stdio.h>
//
// Chapter 45: Pointers and Arrays
//
// 5.1 Pointers and Addresses
//
// 5.2 Pointers and Function Arguments
//
void swap(int *px, int *py) /* interchange *px and *py */
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}

void test_swap(void)
{
	int x = 53, y = 12;

	printf("x = %d, y = %d\n", x, y);
	printf("After swap:\n");
	swap(&x, &y);
	printf("x = %d, y = %d\n", x, y);
}

#include <ctype.h>
int getch(void);
void ungetch(int);

#define BUF_SIZE 100
char buffer[BUF_SIZE];
int bufp = 0;
int getch(void)
{
	return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUF_SIZE)
		printf("ungetch error: too many characters\n");
	else
		buffer[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch())) 		/* skip white space */
		;
	if (!isdigit(c) && c!= EOF && c != '+' && c != '-')
	{
		ungetch(c);						/* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);

	return c;
}

void test_getint(void)
{
	int i, r;

	printf("Input som intger: \n");
	while ((r = getint(&i)) != EOF)
		printf("Return value of getint is %d, input intger is : %d\n", r, i);
}

// 5.3 Pointer and Arrays

/* strlen: return length of string s */
int my_strlen(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}
void test_my_strlen(void)
{
	char *s = "1234567890";

	printf("String: %s\nLength: %d\n",s, my_strlen(s));
}

// 5.4 Address Arithmetic

#define ALLOCSIZE 1000	 			/* size of available space */

static char allocbuf[ALLOCSIZE]; 	/* storage for alloc */
static char *allocp = allocbuf;		/* next free position */

char *alloc(int n)					/* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n)		/* it fits */
	{
		allocp += n;
		return allocp - n;						/* old p */
	}
	else							/* not enough room */
		return 0;
}

void afree(char *p)					/* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

void test_alloc(void)
{
	char *p;
	int i = 1;

	while ((p = alloc(i)) != 0)
	{
		printf("Alloc memory: %d, ptr: %p\n", i, p);
		i += ALLOCSIZE / 10;
		afree(p);
	}
	printf("Alloc error. alloc memory size: %d\n", i);
}

/* strlen: return length of string s */
int my_strlen_v2(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;
	return p - s;
}

void test_my_strlen_v2(void)
{
	char *s = "1234567890";

	printf("string: %s \nlenght: %d\n", s, my_strlen_v2(s));
}

// 5.5 Character Pointer and Functions

/* strcpy: copy t to s; array subscript version */
void strcpy_a(char *s, char *t)
{
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}
void test_strcpy_a(void)
{
	char t[] = "1234567890";
	char s[sizeof(t)];

	printf("The t string is %s\n", t);
	printf("sizeof t is %ld\n", sizeof(t));
	printf("sizeof \"1...0\" is %ld\n", sizeof("1234567890"));
	strcpy_a(s, t);
	printf("The s string is %s\n", s);
}

/* strcpy: copy t to s; pointer version 1 */
void strcpy_p1(char *s, char *t)
{
	while ((*s = *t) != '\0')
	{
		s++;
		t++;
	}
}

/* strcpy: copy t to s; pointer version 2 */
void strcpy_p2(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}

/* strcpy: copy t to s; pointer version 3 */
void strcpy_p3(char *s, char *t)
{
	while (*s++ = *t++)
		;
}

void test_strcpy_p(void)
{
	char t[] = "0123456789";
	char s1[sizeof(t)], s2[sizeof(t)], s3[sizeof(t)];

	printf("The t string is: %s\n", t);
	strcpy_p1(s1, t);
	strcpy_p2(s2, t);
	strcpy_p3(s3, t);
	printf("The s1 string is: %s\n", s1);
	printf("The s2 string is: %s\n", s2);
	printf("The s3 string is: %s\n", s3);
}
/* strcmp: return <0 if s<t, 0 if s==t, >- if s>t */
int strcmp_a(char *s, char *t)
{
	int i;

	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp_p(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int my_gets(char *p, int n)
{
	int c, i = 0;
	
	while (i++ < n - 1 && (c = getch()) != EOF && !isspace(c))
		*p++ = c;
	*p = '\0';
	return i - 1;
}

void test_strcmp(void)
{
	char s[20];
	char t[20];
	int i;
	
	printf("input 2 strings:\n");
	my_gets(s, 20);
	my_gets(t, 20);
	i = strcmp_p(s, t);
	printf("the compare result is: %s\n", (i < 0) ? "s < t" : ((i > 0) ? "s > t" : "s = t"));
}

// 5.6 Pointer Array; Pointers to Pointers

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* max #lines to be sorted */

char *lineptr[MAXLINES];	/* pointers to textlines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void q_sort(char *lineptr[], int left, int right);

/* sort input lines */
int my_sort(void)
{
	int nlines;				/* number of input lines read */

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		q_sort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000			/* max length of any input line */
int get_line(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else
		{
			line[len - 1] = '\0';		/* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/* writelines: write output lines */
void writelines_v2(char *lineptr[], int nlines)
{
	while (nlines-- > 0);
		printf("%s\n", *lineptr++);
}

/* get_line is from Section 1.9 */
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	
	return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void q_sort(char *v[], int left, int right)
{
	int i, last;
	void swap_s(char *v[], int i, int j);

	if (left > right)
		return;
	swap_s(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i < right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap_s(v, ++last, i);
	swap_s(v, left, last);
	q_sort(v, left, last - 1);
	q_sort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap_s(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

// 5.7 Multi-dimensional Arrays

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
void test_month_day(void)
{
	int m, d;
	int year = 2000, day = 31;
	printf("days of day_of_year(2000, 12, 31) is: %d\n", day_of_year(2000, 12, 31));
	month_day(year, day, &m, &d);
	printf("year: %d, day: %d, is month: %d, day: %d\n", year, day, m, d);
}

// 5.8 initialization of Pointer Arrays
/* month_name: return name of n-th month */
char *month_name(int n)
{
	static char *name[] = 
	{
		"Illegal month", 
		"January", "February", "march", 
		"April", "May", "June",
		"July", "August", "September",
		"October", "N0ovember", "December"
	};
	return (n < 1 || n > 12) ? name[0]: name[n];
}

void test_month_name(void)
{
	int i;
	printf("input a month (integer): ");
	scanf("%d", &i);
	printf("%d month's name is: %s\n", i, month_name(i));
}

// 5.9 Pointers vs. Multi-dimensional Arrays

// 5.10 Command-line Arguments

/* echo command-line arguments; 1st version */
int echo_v1(int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
	printf("\n");
	return 0;
}

/* echo command-line arguments; 2nd version */
int echo_v2(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");
	printf("\n");
	return 0;
}

/* echo command-line arguments; 3td version */
int echo_v3(int argc, char *argv[])
{
	while (--argc > 0)
		printf((argc > 1) ? "%s " : "%s", *++argv);
	printf("\n");
	return 0;
}

int echo_v4(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%s ", *++argv);
	printf("\n");
	return 0;
}
#define MAXLINE 1000
/* find: print lines that match pattern from 1st arg */
int find_v1(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc != 2)
		printf("Usage: find pattern\n");
	else
		while (get_line(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL)
			{
				printf("%s", line);
				found++;
			}
	printf("Found times: %d\n", found);
	return found;
}

// test: array const & pointer variable

char array_1[] = "first";
char array_2[] = "Second";
char array_3[] = "Third";
char array_4[] = "Forth";
char *ptr_a[] = {array_1, array_2, array_3, array_4};
char **ptr_b = ptr_a;

char *ptr_c[] = {"abdefghi","1234567","ABCDEFG","!@#$%"};

void ptr_array(char *ptr[])
{
	/*
	char *ptr[] = {"abdefghi","1234567","ABCDEFG","!@#$%"};
	*/
	printf("1st string %s\n",ptr[0]);
	printf("2nd string %s\n", *++ptr);
	printf("3rd string %s\n", (++ptr)[0]);
	printf("3rd string 1st char: %c\n", *ptr[0]);
	printf("3rd string 2nd char: %c\n", *++ptr[0]);
	printf("3rd string 3rd char: %c\n", *++(*ptr));
	printf("4th string 1st char: %c\n", **++ptr);
	printf("4th string %s\n", *ptr);
}

void test_ptr_array(void)
{
	ptr_array(ptr_b);
	ptr_array(ptr_c);
}

/* find: print lines that match pattern from 1st arg */
int find_v2(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found= 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c)
			{
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while (get_line(line, MAXLINE) > 0)
		{
			lineno++;
			if ((strstr(line, *argv) != NULL) != except)
			{
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
}

//5.11 Pointers to Functions

#undef MAXLINES
#define MAXLINES 5000		/* max #lines to be sorted */
char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void quicksort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int sort_v2(int argc, char *argv[])
{
	int nlines;				/* number of input lines read */
	int numeric = 0;		/* 1 if numeric sort */

	if (argc > 1 && strcmp_a(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		quicksort((void **) lineptr, 0, nlines - 1, 
					(int (*)(void *, void *))(numeric ? numcmp : strcmp_a));
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
}
	

/* qsort: sort v[left]...v[right] into increasing order */
void quicksort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap_v2(void *v[], int, int);

	if (left >= right) 			/* do nothing if array contains */
		return;					/* fewer than two elements */
	swap_v2(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap_v2(v, ++last, i);
	swap_v2(v, left, last);

	quicksort(v, left, last - 1, comp);
	quicksort(v, last + 1, right, comp);
}

#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap_v2(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

// 5.12 Complicated Declarations

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;				/* type of last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];		/* identifier name */
char datatype[MAXTOKEN];	/* data type = char, int, etc. */
char out[1000];				/* output string */

int declare(void)
{
	while (gettoken() != EOF)			/* 1st token on line */
	{
		strcpy(datatype, token);		/* is the datatype */
		out[0] = '\0';
		dcl();							/* parse rest of line */
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

/* dcl: parse a declarator */
void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; )		/* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
	int type;

	if (tokentype == '(')				/* ( dcl ) */
	{
		dcl();
		if (tokentype != ')')
			printf("error: missing )\n");
	}
	else if (tokentype == NAME)			/* variable name */
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " function returning");
		else
		{
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}

int gettoken(void)			/* return next token */
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;
	
	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(')
	{
		if ((c = getch()) == ')')
		{
			strcpy(token, "()");
			return tokentype = PARENS;
		}
		else
		{
			ungetch(c);
			return tokentype = '(';
		}
	}
	else if (c == '[')
	{
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	}
	else if (isalpha(c))
	{
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	}
	else
		return tokentype = c;
}

/* undcl: convert word description to declaration */
int undcl(void)
{
	int type;
	char temp[MAXTOKEN];

	while (gettoken() != EOF)
	{
		strcpy(out, token);
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*')
			{
				sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
			}
			else if (type == NAME)
			{
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			}
			else
				printf("invalid input at %s\n", token);
		printf("%s\n", out);
	}
	return 0;
}


#define TEST(func) printf("Testing function "#func":\n");func()

int main(int argc, char *argv[])
{
	TEST(declare);
	//TEST(undcl);
	//test_ptr_array();
	//find_v2(argc, argv);
	//find_v1(argc, argv);
	//echo_v4(argc, argv);
	//echo_v3(argc, argv);
	//echo_v1(argc, argv);
	//echo_v2(argc, argv);
	//TEST(test_month_name);
	//TEST(test_month_day);
	//TEST(my_sort);
	//TEST(test_strcmp);
	//TEST(test_strcpy_p);
	//TEST(test_strcpy_a);
	//TEST(test_my_strlen_v2);
	//TEST(test_alloc);
	//TEST(test_my_strlen);
	//TEST(test_getint);
	//TEST(test_swap);

	return 0;
}
