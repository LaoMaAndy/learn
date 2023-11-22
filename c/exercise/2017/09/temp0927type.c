/*
 * prototype. type convert functions.
 */

int Ispace(int c);
int Isdigit(int c);
int Isupper(int c);
int Islower(int c);
int Toupper(int c);
int Tolower(int c);
char *Strup(char *dest);
char *Strlow(char *dest);
int Atoi(const char *s);
double Atof(const char *s);
char *Itoa(int n, char *s);
unsigned Getbits(unsigned x, int p, int n);


/*
 * implementation
 */

int Ispace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int Isdigit(int c)
{
	return c >= '0' && c <= '9';
}

int Isupper(int c)
{
	return c >= 'A' && c <= 'Z';
}

int Islower(int c)
{
	return c >= 'a' && c <= 'z';
}

int Toupper(int c)
{
	if (Islower(c))
		return c - 'a' + 'A';
	return c;
}

int Tolower(int c)
{
	if (Isupper(c))
		return c - 'A' + 'a';
	return c;
}

char *Strup(char *dest)
{
	char *d = dest;
	int c;

	while ((c = *d) != '\0')
		*d++ = Toupper(c);
	return dest;
}


char *Strlow(char *dest)
{
	char *d = dest;
	int c;

	while ((c = *d) != '\0')
		*d++ = Tolower(c);
	return dest;
}

int Atoi(const char *s)
{
	int val, sign;

	for ( ; Ispace(*s); s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	for (val = 0; Isdigit(*s); s++)
		val = 10 * val + (*s - '0');
	return sign * val;
}


double Atof(const char *s)
{
	double val, power;
	int sign;

	for ( ; Ispace(*s); s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	for (val = 0.0; Isdigit(*s); s++)
		val = val * 10.0 + (*s - '0');
	if (*s == '.')
		s++;
	for (power = 1.0; Isdigit(*s); s++)
	{
		val = val * 10.0 + (*s - '0');
		power *= 10.0;
	}
	return val * sign / power;
}

int Strlen(const char *dest)
{
	const char *d = dest;

	while (*d != '\0')
		d++;
	return d - dest;
}

char *Reverse(char *dest)
{
	char *p = dest, *q = dest;
	int c;

	for (p += Strlen(dest) - 1; p > q; p--, q++)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
	return dest;
}

char *Itoa(int n, char *dest)
{
	char *d = dest;
	int sign;

	if ((sign = n) < 0)
		n = -n;
	do
	{
		*d++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		*d++ = '-';
	*d = '\0';
	Reverse(dest);
	return dest;
}

unsigned Getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n )) & ~(~0 << n);
}
		
/*
 * test these function
 */
#include <stdio.h>
#include "00prn.h"

void test(void)
{
	char a[100] = "AbCdEfGhIjK012#^";
	char b[100] = "-1234567.00";
	char c[100] = " -908076.543a";
	int d = -12345678;
	char e[100];
	unsigned f = 0x1F320;

	PRN_VAR(a, s);
	PRN_FUN(Strup(a), s);
	PRN_FUN(Strlow(a), s);
	PRN_FUN(Atoi(b), d);
	PRN_FUN(Atof(b), .2f);
	PRN_FUN(Atof(c), f);
	PRN_FUN(Itoa(d, e), s);
	PRN_FUN(Getbits(f, 15, 4), X);

}

/*
 * main function
 */

int main(int argc, char *argv[])
{
	test();

	return 0;
}






