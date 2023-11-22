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
	char s[] = "-12345";
	int i = 0;

	printf("String : %s\n", s);
	printf("Integer: %d\n", atoi(s));
	i = unsigned(~i) >> 1;	
	printf("Max positive integer: %d\n",  i);
	printf("Max negative integer: %d\n", ~(unsigned)(~i));
}



#define TEST(func) printf("Testing function: "#func"\n");func()

int main(int argc, char *argv[])
{
	TEST(test_atoi);
	//TEST(test_n);
	//TEST(test_strend);
	//TEST(test_strcat);
	//TEST(test_getfloat);
	//TEST(test_getint);

	return 0;
}





