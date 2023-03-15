/* Capitalize the first letter of the function name */
/* algorithms */
void swap(int v[], int i, int j);
void qksort(int v[], int left, int right);
void shsort(int v[], int n);
void bbsort(int v[], int n);

/* data structure */

/* character and type function */
int Atoi(char s[]);							/* 2.7 */
int Lower(int c);							/* 2.7 */

/* string function */
int Strlen(char *s);
char *Strcat(char *s, char *t);				/* 2.8 */
char *Strcpy(char *t, char *s);				/* 1.9 */
char *Squeeze(char s[], int c);				/* 2.8 */

/* input output */
void Putgetchar(void);						/* 1.5.1 */
void Wordcount(void);						/* 1.5.4 */
int Getline(char s[], int lim);				/* 1.9 */

/* grammar lexical */

/* mathematics */
int Power(int base, int n);					/* 1.7 , 1.8 */
unsigned Getbits(unsigned x, int p, int n);	/* 2.9 */

unsigned long int Rand_next = 1;			/* globle variable for Rand() */
int Rand(void);								/* 2.7 */
void Srand(unsigned int seed);				/* 2.7 */ 

/* Others */
void Printarray(int v[], int n);			/* 2.10 */


/****** function sorce coed ********/
#include <stdio.h>

void Putgetchar(void)						/* 1.5.1 */
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(c);
}

void Wordcount(void)						/* 1.5.4 */
{
	int c, nl, nw, nc, state;

	state = 0;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			++nw;
		}
	}
	printf("line:%d word:%d char:%d\n", nl, nw, nc);
}

int Power(int base, int n)					/* 1.7 , 1.8 */
{
	int p;

	for (p = 1; n > 0; --n)
		p = p *base;
	return p;
}
void test_Power(void)
{
	int i;

	for (i = 1; i < 20; i++)
		printf("Power (2,%3d) is : %8d\n", i, Power(2, i));
}
/* bug report: see the text file */
int Getline(char s[], int lim)				/* 1.9 */
{
	int c, i;

	if (lim == 1)
		return (s[0] = '\0');
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c!= '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	//printf("\nGetline. i is: %d, line is: %s\n", i, s);
	return i;
}
void test_Getline(void)
{
	char s[3];
	int n = sizeof(s);

	printf("sizeof(s[%d]) :%ld\n", n, sizeof(s));
	while (Getline(s, n) != 0)
		printf("%s", s);
	printf("n value is %d\n", n);
}

char *Strcpy(char *t, char *s)			/* 1.9 */
{
	while (*t++ = *s++);
	return t;
}
void test_Strcpy(void)
{
	char t[] = "1234567890";
	char s[] = "abcdefg";
	printf("t is: %s\n", t);
	printf("s is: %s\n", s);
	Strcpy(t, s);
	printf("str_cpy(t, s)\n");
	printf("t is: %s\n:", t);
}

int Atoi(char s[])						/* 2.7 */
{
	int i, n;
	
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
void test_Atoi(void)
{
	printf("123456 is: %d\n", Atoi("123456"));
}

int Lower(int c)							/* 2.7 */
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
void test_Lower(void)
{
	char s[100];
	int i, n;

	n = Getline(s, sizeof(s));
	for (i = 0; i < n; i++)
		s[i] = Lower(s[i]);
	printf("After Lower:\n%s\n", s);
}

int Rand(void)								/* 2.7 */
{
	extern unsigned long int Rand_next;
	Rand_next = Rand_next * 1103515245 + 12345;
	return (unsigned int)(Rand_next / 65536) % 32768;
}

void Srand(unsigned int seed)				/* 2.7 */ 
{
	Rand_next = seed;
}

void test_Rand(void)
{
	int v[1000];
	int n = sizeof(v) / sizeof(v[0]);
	int i;

	for (i = 0; i < n; i++)
		v[i] = 0;
	for (i = 0; i < n * 1000; i++)
		v[Rand() % n]++;
	for (i = 0; i < n; i++)
		printf("%3d%c", v[i], (i % 10 == 9) ? '\n' : '\t');
	printf("\n");
}

char *Squeeze(char s[], int c)				/* 2.8 */
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
	return s;
}

char *Strcat(char s[], char t[])				/* 2.8 */
{
	int i, j;
	
	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0')
		;
	return s;
}
void test_Strcat(void)
{
	char s[200] = "This is a ";
	char t[] = "test";
	printf("%s\n", Strcat(s, t));
}

unsigned Getbits(unsigned x, int p, int n)	/* 2.9 */
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

void Printarray(int v[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%6d%c", a[i], (i % 9 == 9 || i == n - 1) ? '\n' : ' ');
}

/******* inovke *********/
#define TEST(func) printf("Testing function: "#func" \nPress CTRL-D to quit.\n");func
int main(int argc, char *argv[])
{
	//TEST(Putgetchar());
	//TEST(Wordcount());
	//TEST(test_Getline());
	//TEST(test_Power());
	//TEST(test_Strcpy());
	//TEST(test_Atoi());
	//TEST(test_Lower());
	//TEST(test_Rand());
	TEST(test_Strcat());

	return 0;
}

