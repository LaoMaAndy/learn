//
// Chapter 4. Functions and Program structure
//
//4.1 Basics of Function
//
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int max);
int strindex(char source[], char searchro[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int matching(void)
{
	char line[MAXLINE];
	int found = 0;

	while (get_line(line, MAXLINE) > 0)
			if (strindex(line, pattern) >= 0)
			{
				printf("%s", line);
				found++;
			}
	return found;
}

/* get_line: get line intos, return length */
int get_line(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	//printf("%s result: %d\n", __func__, i);
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

void test_matching(void)
{
	char s[] = "abcdefgtest12345xindextesting";
	char t[] = "test";
	char buf[100];
	int i;

	//printf("Please input some lines, inlucde patter \"ould\"\n");
	matching();
	//printf("test strindex: \n");
	//printf("source : %s, target : %s, index result is : %d\n", s, t, strindex(s, t));
	//get_line(buf, 100);
}

//
// 4.2 Functions Returning Non-integers
//
#include <ctype.h>
/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) 	/* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)	
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val / power;
}
void test_atof(void)
{
	char s[50] = "-1245.678";
	double f;

	f = atof(s);
	printf("the string is %s\n", s);
	printf("it's value is %f\n", f);
}
/* rudimentary calculator */
void rudiment(void)
{
	double sum, atof(char []);
	char line[MAXLINE];
	int get_line(char line[], int max);

	sum = 0;
	while (get_line(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
}

/* atoi: convert string s to integer using atof */
int atoi_v2(char s[])
{
	double atof(char s[]);

	return (int)atof(s);
}
void test_atoi_v2(void)
{
	char s[] = "123456790";

	printf("String : %s\n", s);
	printf("atof   : %d\n", atoi_v2(s));
}
//
// 4.3 External Variables
//
#define MAXOP 100 		/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found  */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
void polish(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknow command %s\n", s);
			break;
		}
	}
}

#define MAXVAL 100 		/* maximum depth of val stack */
int sp = 0;				/* next free stack position   */
double val[MAXVAL];		/* value stack                */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else 
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int my_getch(void);
void my_ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = my_getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;					/* not a number */
	i = 0;
	if (isdigit(c))					/* collect integer part */
		while (isdigit(s[++i] = c = my_getch()))
			;
	if (c == '.')					/* collect fraction part */
		while (isdigit(s[++i] = c = my_getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		my_ungetch(c);
	
	return NUMBER;
}

#undef  BUFSIZE 
#define BUFSIZE 100		

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free position in buf */

int my_getch(void)			/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void my_ungetch(int c)		/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

// 4.5 Header Files

// 4.6 Static Variables

// 4.7 Register Variables

// 4.8 Blick Structure

// 4.9 Initialization

// 4.10 Recursion

/* printd: print n in decimal */
void printd(int n)
{
	if (n < 0)
	{
		putchar ('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar (n % 10 + '0');
}

void test_printd(void)
{
	printd(123456);
	printf("\n");
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)						/* do nothing if array contains */
		return;								/* fewer than two elements 		*/
	swap(v, left, (left + right) /2 );		/* move partition elem */
	last = left;							/* to v[0] */
	for (i = left + 1; i <= right; i++)		/* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);					/* restore partition elem */
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void test_qsort(void)
{
	int v[] = {12, 14, 11, 13, 0, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
	int left = 0;
	int right = sizeof(v) / sizeof(v[0]);
	int n ;

	printf("Source: \n");
	for (n = 0; n < right ; n++)
		printf("%3d ", v[n]);
	printf("\n");

	qsort(v, left, right);

	printf("After Sort: \n");
	for (n = 0; n < right ; n++)
		printf("%3d ", v[n]);
	printf("\n");
}
	
#define TEST(func) printf("testing function: "#func"\n");func()

int main(void)
{
	TEST(test_qsort);
	//TEST(test_printd);
	//TEST(polish);
	//TEST(test_atoi_v2);
	//TEST(rudiment);
	//TEST(test_atof);
	//test(test_matching);

	return 0;
}

