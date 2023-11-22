/* convert.c */
#include "template/head.h"

int Atoi(const char *s)
{
	int sign, val;

	while (Isspace(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-')
		++s;
	for (val = 0; Isdigit(*s); ++s)
		val = val * 10 + (*s - '0');
	return sign * val;
}
double Atof(const char *s)
{
	double val, power;
	int sign;

	while (Isspace(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-')
		++s;
	for (val = 0.0; Isdigit(*s); ++s)
		val = val * 10.0 + (*s - '0');
	if (*s == '.')
		++s;
	for (power = 1.0; Isdigit(*s); ++s)
	{
		val = val * 10.0 + (*s - '0');
		power *= 10.0;
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
	return Strrev(p);
}
int fact(int n)
{
	if (n <= 1)
		return 1;
	return n * fact(n - 1);
}
void prnstr(const char *s)
{
	if (*s == '\0')
		return ;
	printf("%c", *s);
	prnstr(s + 1);
}

