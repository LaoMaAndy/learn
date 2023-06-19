/*
 functions of convert, get from file
 */
#define NEED_STRING_FUNCTION
#include "0head.c"

int Atoi(const char *s)
{
	int sign, val;
	
	while (Issapce(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	for (val = 0; Isdigit(*s); s++)
		val = val * 10 + (*s - '0');
	return sign * val;
}

double Atof(const char *s)
{
	double val, power;
	int sign;

	while (Isspace(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	for (val = 0; Isdigit(*s); s++)
		val = val * 10 + (*s - '0');
	if (*s == '.')
		s++;
	for (power = 1; Isdigit(*s); s++)
	{
		val = val * 10 + (*s - '0');
		power *= 10;
	}
	return sign * val / power;
}

char *Itoa(int n, char *s)
{
	int sign;
	char *p = s;

	if ((sign = n) < 0)
		n = -n;
	do
	{
		*s++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	return Reverse(p);
}

void Printd(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10 > 0)
		Printd(n / 10);
	putchar(n + '0');
}

unsigned Getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

int Getline(FILE *fp, char *buf, int lim);
int Getword(FILE *fp, char *buf, int lim);

