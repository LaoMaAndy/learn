/*
function: convert, file get
*/
#define NEED_STRING
#include "0head.c"

int Atoi(const char *s)
{
	int val, sign;

	if (Isspace(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		++s;
	for (val = 0; Isdigit(*s); ++s)
		val = val * 10 + (*s + '0');
	return sign * val;
}
