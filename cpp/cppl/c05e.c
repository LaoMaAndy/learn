// Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fixt it to push such a character back on the input.

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);

#define BUF_SIZE 100

int buffer[BUF_SIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUF_SIZE)
		printf("ungetch: too many characters\n");
	else
		buffer[bufp++] = c;
}

int getint(int *pn)
{
	int c, sign, sc;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		sc = c;
		c = getch();
		if (!isdigit(c))
		{
			ungetch(sc);
			ungetch(c);
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
	{
		//printf("c value is %d\n", c);
		*pn = 10 * *pn + (c - '0');
	}
	//printf("Quit loop, c value is %d\n", c);
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	
	return c;
}
void test_getint(void)
{
	int i, r;
	printf("Input some integer:\n");
	while ((r = getint(&i)) != EOF && r != 0)
		printf("Return value of getint is %d, input intger is : %d\n", r, i);
}

// Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?
int getfloat(double *pf)
{
	int c, sign, sc;
	double  power;
	
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c =='-')
	{
		sc = c;
		c = getch();
		if (!isdigit(c))
		{
			ungetch(sc);
			ungetch(c);
			return 0;
		}
	}
	for (*pf = 0; isdigit(c); c = getch())
		*pf = 10 * *pf + (c - '0');
	if (c == '.')
		c = getch();
	for (power = 1; isdigit(c); c = getch())
	{
		*pf = 10 * *pf + (c - '0');
		power *= 10;
	}
	*pf = sign * *pf / power;
	if (c != EOF)
		ungetch(c);
	
	return c;
}

void test_getfloat(void)
{
	int r;
	double d;

	printf("input some float number:\n");
	while((r = getfloat(&d)) != EOF && r != 0)
		printf("Return value %d, input float number %lf\n", r, d);
}

// Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s, t) copies the string t to the end of s.
void strcat_p(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ = *t++)
		;
}

void test_strcat(void)
{
	char s[100] = "123";
	char t[] = "456";

	printf("s is %s, t is %s\n", s, t);
	strcat_p(s,t);
	printf("strcat(s, t): \n%s\n", s);
}

// Exercise 5-4. Write the function strend(s, t),which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
int strend(char *s, char *t)
{
	int i = 0, j = 0;

	for (i = 0; s[i]; i++)
		;
	for (j = 0; t[j]; j++)
		;
	printf("s length is %d, t length is %d\n", i, j);
	if (i < j || i == 0 || j ==0)
		return 0;
	for (s += i - j; *s == *t && *s != '\0'; s++, t++)
		;
	if (*s == '\0')
		return 1;
	else
		return 0;
}

int my_gets(char *s, int n)
{
	int i = 0, c;

	while (i < n - 1 && (c = getch()) != EOF && !isspace(c))
	{
		*s++ = c;
		i++;
	}
	*s = '\0';
	return i;
}

void test_strend(void)
{
	char s[20], t[20];

	printf("input two strings: \n");
	my_gets(s, 20);
	my_gets(t, 20);

	printf("first  string: %s\n", s);
	printf("second string: %s\n", t);
	printf("strend() result is: %d\n", strend(s, t));
}

// Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s, t, n) copies at most n characters of t to s. Full descriptions are in Appendix B.

char *my_strncpy(char *s, char *t, int n);
char *my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);

char *my_strncpy(char *s, char *t, int n)
{
	while (n > 0 && (*s++ = *t++))
		n--;
	*s = '\0';
	return s;
}

char *my_strncat(char *s, char *t, int n)
{
	while (*s)
		s++;
	while (n > 0 && (*s++ = *t++))
		n--;
	*s = '\0';
	return s;
}

int my_strncmp(char *s, char *t, int n)
{
	int i;
	
	for ( ; n > 0 && *s == *t; n--, s++, t++)
	//while (n-- > 0 && (*s++ == *t++))
		if (*s == '\0')
			return 0;
	i = *s - *t;
	return i;
}

void test_n(void)
{
	char s[100], t[100];
	int i;

	printf("Input two strings:\n");
	my_gets(s, 100);
	my_gets(t, 100);
	printf("String s: %s, String t: %s\n", s, t);
	
	i = my_strncmp(s, t, 3);
	printf("strncmp(s, t, 3))\n");
	printf("the compare result is: %s\n", (i < 0) ? "s < t" : ((i > 0) ? "s > t" : "s = t"));

	my_strncat(s, t, 3);
	printf("strncat(s, t, 3)\n");
	printf("String s: %s, String t: %s\n", s, t);

	my_strncpy(s, t, 5);
	printf("strncpy(s, t, 5)\n");
	printf("String s: %s, String t: %s\n", s, t);

}

// Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers intead of array indexing. Good possibilities include getline(Chapters 1 and 4) aoti, itoa, and their variants (Chapters 2, 3 and 4), reverse(Chapter 3), and strindex and getop(Chapter 4).

//list:
int atoi(char *s)
{
	int n, sign;

	for (	; isspace(*s); s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	for (n = 0; isdigit(*s); s++)
		n = 10 * n + (*s - '0');
	return sign * n;
}

void test_atoi(void)
{
	char s[] = "2147483647";
	char t[] = "-2147483648";
	int i;

	printf("String : %s\n", s);
	printf("Integer: %d\n", atoi(s));
	printf("String : %s\n", t);
	printf("Integer: %d\n", atoi(t));

	i = (unsigned int)~0 >> 1;	
	printf("Max positive integer: %d\n",  i);
//	i = ~((unsigned int)~0 >> 1);
	printf("Max negative integer: %d\n", ~i);
}

char *reverse(char *s)
{
	char *p, *r;
	int  temp;
	
	for (r = p = s; *p != '\0'; p++)
		;
	p--;
	for ( ; p > s; p--, s++)
	{
		temp = *s;
		*s = *p;
		*p = temp;
	}
	return r;
}

void test_reverse(void)
{
	char s[] = "12345657890";

	printf("string : %s\n", s);
	printf("reverse: %s\n", reverse(s));
}

// Reverse for any type.
#define REVERSE(s, t)						\
	do{										\
		t *p, *q;							\
		t temp;								\
		for (p = q = s; *p != '\0'; p++)	\
			;								\
		p--;								\
		for (	; p > q; p--, q++)			\
		{									\
			temp = *q;						\
			*q = *p;						\
			*p = temp;						\
		}									\
		return s;							\
	}while(0);								
		
int *reverse_int(int *s)
{
	REVERSE(s,int);
}

void test_reverse_int(void)
{
	int n[] = {1,2,3,4,5,6,7,8,9};
	int i;

	printf("Initial:\n");
	for (i = 0; i < sizeof(n) / sizeof(n[0]); i++)
		printf("%3d,", n[i]);
	printf("\nReverse:\n");
	reverse_int(n);
	for (i = 0; i < sizeof(n) / sizeof(n[0]); i++)
		printf("%3d,", n[i]);
	printf("\n");

char s[5] = "12345";
	printf("string: %s, sizeof(s): %ld\n", s, sizeof(s));
	char t[] = "12345";
	printf("String: %s, sizeof(t): %ld\n", t, sizeof(t));
}

// Exercise 5-7. Rewrite readlines to store lines in an array supplied by main. rather than calling alloc to maintain storage. How much faster is the program?

// I do not know

// Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
	int i , leap;

	if (year < 1)
	{
		printf("%s error: illegal year: %d\n", __func__, year);
		return 0;
	}
	if (month < 1 || month > 12)
	{
		printf("%s error: illegal month: %d\n", __func__, month);
		return 0;
	}
	if (day < 1 || day > 31)
	{
		printf("function %s error: illegal day: %d\n", __func__, day);
		return 0;
	}
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	if (year < 1 || yearday < 0 || yearday > 366)
	{
		printf("%s error: illegal year / day: %d year, %d day\n", __func__, year, yearday);
		return 0;
	}
	leap = year %4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
	
	return 1;
}


void test_day_of_year(void)
{
	printf("days of day_of_year(2000, 3, 1) is: %d\n", day_of_year(2000, 3, 1));
}


// Exercise 5-9. Rewrite the routines day_of_year and moth_day with pointers instead of indexing.

static int daynum[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year_v2(int year, int month, int day)
{
	int leap, i;
	if (year < 0 || month > 12 || month < 1 || day > 31 || day < 1)
	{
		printf("Error %s, year: %d, month: %d, day: %d \n", __func__, year, month, day);
		return 0;
	}
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += *(*(daynum + leap) + i);
	return day;
}

void test_day_of_year_v2(void)
{
	printf("days of day_of_year(2000, 3, 1) is: %d\n", day_of_year_v2(2000, 3, 1));
}

int month_day_v2(int year, int yearday, int *pmonth, int *pday)
{
	int leap, i;
	
	if (year < 0 || yearday > 366)
	{
		printf("%s error. day: %d, yearday: %d\n", year, yearday);
		return 0;
	}
	leap = year % 4 == 0 && year % 100 != 0 || yar || 400 != 0;
	for (i = 0; 
}

// Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the command line, whre each operator or operand is a separate argument. For example,
// expr 2 3 4 + *
// evaluates 2 * (3 + 4)
// 描述：
//		将expr的参数连续读取，并写写入到一个字符串中，
//			直到参数结束，或出现非法字符
//			如果是一个数字，则持续读取该字符串
//			如果是一个操作符号，则可以连续读取，至字符串结束
//		处理这个字符串，使用堆栈的数据结构
//			将数字压入堆栈，
//			如果是操作符号，则根据操作符的操作数，弹出堆栈，计算结果
//			将结果压入堆栈

// Exercise 5-11. Modify the programs entab and detab (written as exercises in Chapter 1) to accept a list of tab stops as arguments. Use the default tab setings if there are no arguments.

// Exercise 5-12. Extend entab and detab to accept the shorthand 
//	entab -m +n
// to mean tab stops every n columns, starting at column m. DChoose convenient (for the user) default behavior.

// Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n is 10, let us say, but it can be changed by an optional argument, so that
//	tail -n
// prints the last n lines. The program should behave rationally no matter how unreasonable the input or the value of n. Write the program so it makes the best use of available storage; lines should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed size.

// Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order. Be sure that -r works with -n.

// Exercise 5-15. Add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting; for example, a and A compare equal.

// Exercise 5-16. Add the -d("directory order") option, which makes comparisons only on letters, number and blanks. Make usre it works in conjunction with -f.

// Exercise 5-17. Add a field-handling capability, so sorting may be done on fields within lines, each field sorted according to an independent set of options. (The index for this book was sorted with -df for the index category and -n for the page numbers.)

// Exercise 5-18. Make dcl revoer from input errors. 

// Exercise 5-19. Modify undcl so that it does not add redundant parentheses to declarations.

// Exercise 5-20. Expand dcl to handle declarations with function argument types, qualifiers like const, and so on.


#define TEST(func) printf("Testing function: "#func"\n");func()

int main(int argc, char *argv[])
{
	TEST(test_day_of_year_v2);
	TEST(test_day_of_year);
	//TEST(test_reverse_int);
	//TEST(test_reverse);
	//TEST(test_atoi);
	//TEST(test_n);
	//TEST(test_strend);
	//TEST(test_strcat);
	//TEST(test_getfloat);
	//TEST(test_getint);

	return 0;
}





