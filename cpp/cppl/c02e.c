#include <stdio.h>
#include <limits.h>

//
// Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determin the ranges of the various floating-point types.
//
void determine(void)
{
	printf("Use header definition   :\n");
	printf("sizeof(int) is          : %ld\n", sizeof(int));	
	printf("Min signed char is      : %-d\n", SCHAR_MIN);
	printf("Max signed char is      : %-d\n", SCHAR_MAX);
	printf("Max char is             : %-u\n", CHAR_MAX);
	printf("Min short is            : %-d\n", SHRT_MIN);
	printf("Max short is            : %-d\n", SHRT_MAX);
	printf("Max unsigned short is   : %-u\n", USHRT_MAX);
	printf("Min int is              : %-d\n", INT_MIN);
	printf("Max int is              : %-d\n", INT_MAX);
	printf("Max unsigned int is     : %-u\n", UINT_MAX);
	printf("Min long is             : %-ld\n", LONG_MIN);
	printf("Max long is             : %-ld\n", LONG_MAX);
	printf("Max unsigned long is    : %-lu\n", ULONG_MAX);
}

void determine2(void)
{
	signed char		schar_max, schar_min;
	unsigned char	char_max;
	signed short 	shrt_max, shrt_min;
	unsigned short 	ushrt_max;
	signed int 		int_max, int_min;
	unsigned int 	uint_max;
	signed long 	long_max, long_min;
	unsigned long	ulong_max;
	
	schar_max  = (unsigned char)~0 >> 1;
	schar_min  = ~(unsigned char)schar_max;
	char_max   = ~0;
	shrt_max   = (unsigned short)~0 >> 1;
	shrt_min   = ~(unsigned short)shrt_max; 
	ushrt_max  = ~0;
	int_max    = (unsigned int)~0 >> 1;
	int_min    = ~(unsigned int)int_max;
	uint_max   = ~0;
	long_max   = (unsigned long)~0 >> 1;
	long_min   = ~(unsigned long)long_max;
	ulong_max  = ~0;
	
	printf("Calc the range of integer:\n");
	printf("sizeof(int) is          : %ld\n", sizeof(int));	
	printf("min signed char is      : %-d\n", schar_min);
	printf("max signed char is      : %-d\n", schar_max);
	printf("max char is             : %-u\n", char_max);
	printf("min short is            : %-d\n", shrt_min);
	printf("max short is            : %-d\n", shrt_max);
	printf("max unsigned short is   : %-u\n", ushrt_max);
	printf("min int is              : %-d\n", int_min);
	printf("max int is              : %-d\n", int_max);
	printf("max unsigned int is     : %-u\n", uint_max);
	printf("min long is             : %-ld\n", long_min);
	printf("max long is             : %-ld\n", long_max);
	printf("max unsigned long is    : %-lu\n", ulong_max);
}

void determine3(void)
{
	unsigned int    f_max, f_min;
	float  *fp; 
	unsigned long   d_max, d_min;
	double *dp;
	
	f_max = 0x7F7Fffff;
	f_min = 0xFF7Fffff;
	d_max = 0x7FEFffffFFFFffff;
	d_min = 0xFFEFffffFFFFffff;

	printf("The sizeof float is : %ld\n", sizeof(float));
	printf("The sizeof double is: %ld\n", sizeof(double));
	printf("According IEE754: \n");
	printf("\ta single float with 32bit has 1 bit signal,  8 bit exponent, 23 bit valid value.\n");
	printf("\ta double float with 64bit has 1 bit signal, 11 bit exponent, 52 bit valid value.\n"); 
	printf("\tand, the exponent bit can't be totally 0 or 1.\n");
	printf("So we can build a max float value by integer, then use a pointer to print it.\n\n");

	
	fp = (float *)&f_max;
	dp = (double *)&d_max;
	printf("The max single float 's integer value is : %X\n" , f_max);
	printf("The max double float 's integer value is : %lX\n", d_max); 
	printf("The max single float's value is          : %.20e\n", *fp);
	printf("The max double float's value is          : %.20e\n", *dp);

	printf("\n");

	fp = (float *)&f_min;
	dp = (double *)&d_min;
	printf("The min single float 's integer value is : %X\n" , f_min);
	printf("The min double float 's integer value is : %lX\n", d_min); 
	printf("The min single float's value is          : %.20e\n", *fp);
	printf("The min double float's value is          : %.20e\n", *dp);
}

//
// for (i < lim - 1 && (c = getchar()) != '\n' && c != EOF)
// Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||
// 
void equiv(void)
{
	int lim = 10;
	int c, i;
	char buf[10];

	printf("By definition, the numeric value of a relational or logical expression is 1 if the relation is true, and 0 if the realation is false.\n");
	printf("The unary negation operator ! converts a non-zero operand into 0, and a zero operand into 1.\n");
	for (i = 0; (i < lim - 1) + ((c = getchar()) != '\n') + (c != EOF) == 3; ++i)
		putchar(c);
	putchar('\n');
}
// Exercise 2-3. Write the function htoi(s), which converts a string of hexa-decimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
//
int my_htoi(char s[])
{
	int i, n = 0;
	int d;

	for( i = 0; 
	  	((d = s[i]) >= '0' && d <= '9') || (d >= 'a' && d <= 'f') || (d >= 'A' && d <= 'F');	
		++i)
	{
		if (d >= '0' && d <= '9') 
			d = d - '0';
		else if  (d >= 'a' && d <= 'f')
			d = d - 'a' + 10;
		else if (d >= 'A' && d <= 'F')
			d = d - 'A' + 10;
		
		n = 16 * n + d;
	}
	return n;
}
void test_my_htoi(void)
{
	printf("f is %d\n", my_htoi("f"));
	printf("9 is %d\n", my_htoi("9"));
	printf("ff is %d\n", my_htoi("ff"));
	printf("fa is %d\n", my_htoi("fa"));
	printf("f0 is %d\n", my_htoi("f0"));
	printf("ffff is %d\n", my_htoi("ffff"));
}
//
// Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2
//
void sqeez(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

char *squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (k = 0; s2[k] != '\0'; ++k)
	{
		for(i = j = 0; s1[i] != '\0'; i++)
			if (s1[i] != s2[k]) 
				s1[j++] = s1[i];
		s1[j] = '\0';
	}
	return s1;
}
#define INPUT_BUF 100
void test_squeeze(void)
{
	char buf[INPUT_BUF];
	int c, i;
	char s2[] = "0123456789";

	printf("Iput some char & digital:\n");
	for (i = 0; i < INPUT_BUF && (c = getchar()) != EOF && c != '\n'; ++i)
		buf[i] = c;
	buf[i] = '\0';

	printf("After squeeze all the digital: \n%s\n", squeeze(buf, s2));
}
//
// Exercise 2-5. Write the function any(s1, s2), which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location).
//
int any(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return i;
	return -1;
}

#undef INPUT_BUF
#define INPUT_BUF 100
void test_any(void)
{
	char buf[INPUT_BUF];
	char s2[] = "0123456789";
	int c, i;

	printf("Input some char & digital:\n");
	for (i = 0; i < INPUT_BUF && (c = getchar()) != EOF && c != '\n'; ++i)
		buf[i] = c;
	buf[i] = '\0';

	if ((i = any(buf, s2)) != -1)
		printf("The first location when a digital occur is: %d\n", i + 1);
	else
		printf("Can not find any digital.\n");
}	
//
// Exercise 2-6. Write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
//
unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	return (x & ~(~(~0 << n) << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
}

void test_setbits(void)
{
	unsigned int x = 0x12345678;
	unsigned int y = 0x123F;
	printf("previous x is %X, y is %X, after setbits(x, 3, 4, y) is %X\n", x , y, setbits(x, 3, 4, y));
	printf("previous x is %X, y is %X, after setbits(x, 7, 4, y) is %X\n", x , y, setbits(x, 7, 4, y));
	printf("previous x is %X, y is %X, after setbits(x, 11, 4, y) is %X\n", x ,y, setbits(x, 11, 4, y));
	printf("previous x is %X, y is %X, after setbits(x, 15, 4, y) is %X\n", x ,y, setbits(x, 15, 4, y));
}

//
// Exercise 2-7. Write a function invert(x, p, n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
//
unsigned int invert(unsigned int x, int p, int n)
{
	return x ^ (~(~0 << n) << (p + 1 - n));
}

void test_invert(void)
{
	unsigned int x = 0x11111111;
	
	printf("Previous x is %X, invert(x, 3, 4) is %X\n", x, invert(x, 3, 4));
	printf("Previous x is %X, invert(x, 7, 4) is %X\n", x, invert(x, 7, 4));
	printf("Previous x is %X, invert(x, 11, 4) is %X\n", x, invert(x, 11, 4));
	printf("Previous x is %X, invert(x, 15, 4) is %X\n", x, invert(x, 15, 4));
}
//
// Exercise 2-8. Write a function rightrot(x, n) that returns the value of the integer x rotated to the right by n bit positions.
//
#define BIT_OF_BYTE 8
unsigned int rightrot(unsigned int x, int n)
{
	return (x >> n) | (x << (sizeof(unsigned int) * BIT_OF_BYTE - n));
}

void test_rightrot(void)
{
	unsigned int x = 0xF1234567;
	
	printf("Previous x is %X, rightrot(x, 4) is %X\n", x, rightrot(x, 4));
	printf("Previous x is %X, rightrot(x, 8) is %X\n", x, rightrot(x, 8));
	printf("Previous x is %X, rightrot(x, 12) is %X\n", x, rightrot(x, 12));
	printf("Previous x is %X, rightrot(x, 16) is %X\n", x, rightrot(x, 16));
	printf("Previous x is %X, rightrot(x, 20) is %X\n", x, rightrot(x, 20));
}

//
// Exercise 2-9. In a two's complement number system. x &= (x - 1) deletes the rightmost 1-bit in x. Explain why. Use this ovservation to write a faster verson of bit count.
//
//I don't know how to write the function.

//
// Exercise 2-10. Rewrite the function lower. which converts upper case letters to lower case, with a conditional expression instead of if-else.
//
char my_upper(char c)
{
	return (c >= 'a' && c <= 'z') ? (c - 'a' + 'A') : c;	
}

#undef BUF_SIZE
#define BUF_SIZE 1024
void test_my_upper(void)
{
	char buf[BUF_SIZE];
	int c, i = 0;

	while (i < BUF_SIZE && ((c = getchar()) != EOF) && c != '\n')
		buf[i++] = my_upper(c);
	buf[i] = '\0';

	printf("After upper() is:\n%s\n",buf);
}
//
// My Exercise: Write a program to remove all the blank //
//
// use the first argument as filename to open file as read only.
// use the second argument as filename to open file as write +
// Read a line into a buffer.
// preceed line buffer.
// write line buffer.
// until the end of the file No.1
// Close all the file.


#define TEST(func) printf("Testing function "#func":\n");func()
int main(void)
{
	TEST(test_my_upper);
	//TEST(test_rightrot);
	//TEST(test_invert);
	//TEST(test_setbits);
	//TEST(test_any);
	//TEST(test_squeeze);
	//TEST(test_my_htoi);
	//TEST(equiv);
	//TEST(determine3);
	//TEST(determine);
	//TEST(determine2);
	//TEST(leap_year);
	return 0;
}
