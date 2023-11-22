#include <stdio.h>
//
//2.1 Varible Names
//
//2.2 Data Types and Sizes
//
//2.3 Constants
//
// strlen: return length of s
int my_strlen(char s[])
{
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}

#define BUF_SIZE 100
void test_my_strlen(void)
{
	char buf[BUF_SIZE];
	int c, i;

	printf("Input a string:\n");
	for (i = 0; i < BUF_SIZE && (c = getchar()) != EOF && c != '\n'; ++i)
		buf[i] = c;
	buf[i] = '\0';

	printf("The size of input string is %d\n", my_strlen(buf));
}

//2.4 Declarations
//
//2.5 Arithmetic Operators
//
void leap_year(void)
{
	int year;
	
	for (year = 1980; year < 2080; ++year)
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			printf("%d is a leap year\n", year);
		else
			printf("%d is not a leap year\n", year);
}
//
//2.6 Relational and Logical Operators
//
//2.7 Type Conversions.
//
// stoi: convert s to integer
int my_atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
void test_my_atoi(void)
{
	char s[] = "321412";
	printf("%s is %d\n", s, my_atoi(s));
}
// lower: convert c to lower case; ASCII only
int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else 
		return c;
}
void test_lower(void)
{
	int c;
	while ((c = getchar()) != EOF)
		putchar(lower(c));
}

unsigned long int my_next = 1;
int my_rand(void)
{
	my_next = my_next * 1103515245 + 12345;
	return (unsigned int)(my_next / 65536) % 32768;
}
// rand: reutrn pseudo-random integer on 0..32767
int my_srand(unsigned int seed)
{
	my_next = seed;
}
// srand: set seed for rand()
void test_my_rand(void)
{
	int i;
	
	for (i = 0; i < 200; ++i)
		printf("%4d%c", my_rand() % 100, i % 10 == 9 ? '\n' : '\t');
}

#define RAND_RANGE 100 
#define RAND_TEST_TIME (RAND_RANGE * 100 * 100)
void test_my_rand_2(void)
{
	long i, times = RAND_TEST_TIME;
	int r[RAND_RANGE];
	
	for (i = 0; i < RAND_RANGE; ++i)
		r[i] = 0;

	for (i = 0; i < times; ++i)
		++r[my_rand() % RAND_RANGE];

	for (i = 0; i < RAND_RANGE; ++i)
		printf("%5d%c", r[i], i % 10 == 9 ? '\n' : '\t');
	printf("\n");
}
//
//2.8 INcrement and Decrement Operators
//
// squeeze: delete all c from s
void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

void test_squeeze(void)
{
	char s[] = "This is a test that are test again";

	printf("sting: %s\n", s);
	squeeze(s, 't');
	printf("after squeeze 't' is: %s\n", s);
}
// strcat: concatenate t to end of s; s must be big enough
void my_strcat(char s[], char t[])
{
	int i, j;
	
	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != 0)
		;
}

void test_my_strcat(void)
{
	char str1[20] = "this is ";
	char str2[20] = "a test";


	printf("first str: %s, second str: %s\n", str1, str2);
	my_strcat(str1, str2);
	printf("Strcat: %s\n", str1);
}

//
//2.9 Bitwise Operators
//
// getbits: get n bits from postion p
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0<< n);
}	

//
//2.10 Assignment Operators and Expressions
//
// bitcount: count 1bits in x
int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

void test_bitcount(void)
{
	printf("bitcount 0xF : %2d\n", bitcount(0xf));
	printf("bitcount 0xA : %2d\n", bitcount(0xA));
	printf("bitcount 0x1F: %2d\n", bitcount(0x1F));
	printf("bitcount 0xFE: %2d\n", bitcount(0xfe));
	printf("bitcount 0xFA: %2d\n", bitcount(0xfa));
}
//
// 2.11 Conditional Expressios
//
// 2.12 Precedence and ORder of Evaluation
//
#define TEST(func) printf("Testing function "#func":\n");func()
int main(void)
{
	TEST(test_bitcount);
	//TEST(test_my_strcat);
	//TEST(test_squeeze);
	//TEST(test_my_rand_2);
	//TEST(test_my_rand);
	//TEST(test_lower);
	//TEST(test_my_atoi);
	//TEST(leap_year);
	//TEST(test_my_strlen);
	return 0;
}
