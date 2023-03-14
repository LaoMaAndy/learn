/*
 * charpter 1 : a tutorial introduction
 */

/*
 * 1.1 Getting Started
 */

#include <stdio.h>

void hello(void)
{
	printf("hello, world\n");
}

/*
 * 1.2 Variables and Arithmetic Expressions
 */

void fahr()
{
	int fahr, celsius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}

void fahr_2()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

/*
 * 1.3 The for statement.
 */

void for_stat()
{
	int fahr;
	
	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
	
/*
 * 1.4 Symbolic Constants
 */
#define LOWER 	0
#define UPPER 	300
#define STEP	20

void symbolic()
{
	int fahr;
	
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
}
	
/*
 * 1.5 Character Input and Output
 */
//1.5.1 file Copying

void file_copy()
{
	int c;
	
	c = getchar();
	while (c != EOF)
	{
		putchar(c);
		c = getchar();
	}	
}

void file_copy2()
{
	int c;
	
	while ((c = getchar()) != EOF)
		putchar(c);
}
//
// 1.5.2 Character Counting
//
void count()
{
	long nc;
	
	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
}

void count2()
{
	double nc;
	
	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);
}

//
// 1.5.3 Line Counting
//
void line_count()
{
	int c, nl;
	
	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
}
//
// 1.5.4 Word Counting
//
#define IN	1
#define OUT	0
void word_count() 
{
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
//
// 1.6 Arrays
//
void arrays(void)
// count digits, shite space, others
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;
	
	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	
	printf("digits = ");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}
//
// 1.7 Functions.
//
int power(int m, int n);
void func(void)
{
	int i;

	for (i = 0; i < 10; ++i)
		printf("%2d %5d %7d\n", i, power(2,i), power(-3,i));
}

int power(int base, int n)
{
	int i, p;

	p = 1;
	for (i = 1; i <=n; ++i)
		p = p * base;
	return p;
}

//
// 1.8 Arguments - Call by Value
//
int power2(int base, int n)
{
	int p;
	
	for (p = 1; n > 0; --n)
		p = p * base;
	return p;
}

//
// 1.9 Character Arrays
//
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

void char_array(void)
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
}

//get_line : read a line into s, return length
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

//copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

//
//1.10 External Variables and Scope
//
#undef MAXLINE 
#define MAXLINE 1000
int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline_2(void);
void copy_2(void);

// print longest input line; specialized version
void longest_2(void)
{
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = getline_2()) > 0)
		if (len > max)
		{
			max = len;
			copy_2();
		}
	if (max >0)
		printf("%s", longest);
}

// getline_2: specialized version
int getline_2(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

//copy_2: specialized version
void copy_2(void)
{
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}


#define TEST(func) printf("Testing function "#func":\n");func()
int main() { 
	TEST(longest_2);
	//TEST(char_array);
	//TEST(func);
	//TEST(arrays);
	//TEST(word_count);
	//TEST(line_count);
	//TEST(count2);
	//TEST(count);
	//TEST(file_copy2);
	//file_copy2();
	//file_copy();
	//symbolic();
	//for_stat();
	//fahr_2();
	//fahr();
	//hello();
	return 0;
}

