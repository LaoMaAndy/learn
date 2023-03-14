#include <stdio.h>
#include <stdlib.h>

#ifndef TEMP_HEAD_C
#define TEMP_HEAD_C
/* define PRN_... 6 */
#define PRN_VAL(val, type) 	printf("(variable) "#val":\t%"#type"\n", val)
#define PRN_VAR(val, type) 	printf("(variable) "#val":\t%"#type"\n", val)
#define PRN_FUN(fun, type) 	printf("(function) "#fun":\t%"#type"\n", fun)
#define PRN_CAL(fun)		printf("(function) "#fun"\n");fun
#define PRN_SEN(sen)		printf("(sentence) "#sen";\n");sen
#define PRN_STR(str)		printf(#str"\n")
#define PRN_PRN				printf

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

int Isalpha(int c)
{
	return Isupper(c) || Islower(c);
}

int Isalnum(int c)
{
	return Isalpha(c) || Isdigit(c);
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

/* for key word count */
struct ckey
{
	char *word;
	int count;
} keytab[] = 
{
	"auto"		, 0,
	"break"		, 0,
	"case"		, 0,
	"char"		, 0,
	"const"		, 0,
	"continue"	, 0,
	"default"	, 0,
	"do"		, 0, 
	"double"	, 0,
	"else"		, 0,
	"enum"		, 0,
	"extern"	, 0,
	"float"		, 0,
	"for"		, 0,
	"goto"		, 0,
	"if"		, 0,
	"int"		, 0,
	"long"		, 0,
	"register"	, 0,
	"return"	, 0,
	"short"		, 0,
	"signed"	, 0,
	"sizeof"	, 0,
	"static"	, 0,
	"struct"	, 0,
	"switch"	, 0,
	"typedef"	, 0,
	"union"		, 0,
	"unsigned"	, 0,
	"void"		, 0,
	"volatile"	, 0,
	"while"		, 0,
};
#define keycount (sizeof(keytab) / sizeof(keytab[0]))

#endif

