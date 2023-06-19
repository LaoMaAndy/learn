#include "head.h"

int Atoi(const char *s)
{
	int val, sign;

	while (Ispace(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	for (val = 0; Isdigit(*s); s++)
		val = val * 10 + (*s  - '0');
	return sign * val;
}

double Atof(const char *s)
{
	double val, power;
	int sign;

	while (Ispace(*s))
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	for (val = 0.0; Isdigit(*s); s++)
		val = val * 10.0 + (*s - '0');
	if (*s == '.')
		s++;
	for (power = 1; Isdigit(*s); s++)
	{
		val = val * 10.0 + (*s - '0');
		power *= 10.0;
	}
	return sign * val / power;
}

char *Itoa(int n, char *dest)
{
	int sign;
	char *d = dest;
	
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
