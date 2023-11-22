#ifndef TEMP_HEAD
#define TEMP_HEAD
#include <stdio.h>
#include <stdlib.h>
/* define PRN_... 6 */
#define PRN_VAL(val, type) 	printf("(variable) "#val":\t%"#type"\n", val)
#define PRN_FUN(fun, type) 	printf("(function) "#fun":\t%"#type"\n", fun)
#define PRN_CAL(fun)		printf("(function) "#fun"\n");fun
#define PRN_SEN(sen)		printf("(sentence) "#sen";\n");sen
#define PRN_STR(str)		printf(#str"\n")
#define PRN_PRN			printf

/* some function of type */
int Ispace(int c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\v';
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

#endif

