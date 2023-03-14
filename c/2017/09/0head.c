#include <stdio.h>
#include <stdlib.h>

// you can add this:
//		NEED_TYPE_FUNCTION
//		NEED_STRING_FUNCTION
//		NEED_CONVERT_FUNCTION
//		NEED_FILE_FUNCTION
// to include functions

#ifndef TEMP_0HEAD_C
#define TEMP_0HEAD_C
/* define PRN_... 6 */
#define PRN_VAL(val, type) 	printf("(variable) "#val":\t%"#type"\n", val)
#define PRN_VAR(val, type) 	printf("(variable) "#val":\t%"#type"\n", val)
#define PRN_FUN(fun, type) 	printf("(function) "#fun":\t%"#type"\n", fun)
#define PRN_CAL(fun)		printf("(function) "#fun"\n");fun
#define PRN_SEN(sen)		printf("(sentence) "#sen";\n");sen
#define PRN_STR(str)		printf(#str"\n")
#define PRN_PRN				printf

#if defined(NEED_TYPE_FUNCTION) || defined(NEED_STRING_FUNCTION) || defined(NEED_FILE_FUNCTION)
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

#endif //#if defined(NEED_TYPE_FUNCTION) || defined(NEED_STRING_FUNCTION) || defined(NEED_FILE_FUNCTION)

#if defined(NEED_STRING_FUNCTION) || defined(NEED_FILE_FUNCTION) 
int Strlen(const char *dest)
{
	const char *d = dest;

	while (*d != '\0')
		d++;
	return d - dest;
}

char *Strcpy(char *dest, const char *src)
{
	char *d = dest;

	while ((*d++ = *src++) != '\0')
		;
	return dest;
}

char *Strncpy(char *dest, const char *src, int n)
{
	char *d = dest;

	while (n-- > 0)
		if ((*d++ = *src++) == '\0')
			return dest;
	*d = '\0';
	return dest;
}

char *Strcat(char *dest, const char *src)
{
	char *d = dest;

	d += Strlen(dest);
	Strcpy(d, src);
	return dest;
}

char *Strncat(char *dest, const char *src, int n)
{
	char *d = dest;

	d += Strlen(dest);
	Strncpy(d, src, n);
	return dest;
}

char *Squeeze(char *dest, int chr)
{
	char *p = dest, *q = dest;
	int c;

	while ((c = *p++) != '\0')
		if (c != chr)
			*q++ = c;
	*q = '\0';
	return dest;
}

char *Strstr(const char *dest, const char *sub)
{
	const char *d = dest;
	int i;
	
	for ( ; *d != '\0'; d++)
		if (*d == *sub)
		{
			for (i = 1; d[i] == sub[i] && d[i] != '\0'; i++)
				;
			if (sub[i] == '\0')
				return (char *) d;
		}
	return (char *) 0;
}

int Strindex(const char *dest, const char *sub)
{
	const char *p;

	p = Strstr(dest, sub);
	if (p != 0)
		return p - dest;
	return -1;
}

int Strcmp(const char *s, const char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

char *Trim(char *dest)
{
	char *d = dest;

	d += Strlen(dest);
	while (--d >= dest)
		if (!Ispace(*d))
			break;
	*++d = '\0';
	return dest;
}

char *Reverse(char *dest)
{
	char *p = dest, *q =dest;
	int c;

	for (p += Strlen(dest) - 1; p > q; p--, q++)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
	return dest;
}
#endif //#if defined(NEED_STRING_FUNCTION) || defined(NEED_FILE_FUNCTION) 

#if defined(NEED_CONVERT_FUNCTION)
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
#endif //#if defined(NEED_CONVERT_FUNCTION)

#if defined(NEED_FILE_FUNCTION)
int Getline(FILE *fp, char *dest, int lim)
{
	char *d = dest;
	int c;

	while (--lim > 0 && (c = fgetc(fp)) != EOF && c != '\n')
		*d++ = c;
	if (c == '\n')
		*d++ = c;
	*d = '\0';
	return d - dest;
}

int Getword(FILE *fp, char *dest, int lim)
{
	char *d = dest;
	int c;

	while (Ispace(c = fgetc(fp)))
		;
	if (c != EOF)
		*d++ = c;
	if (!Isalpha(c))
	{
		*d = '\0';
		return c;
	}
	for ( ; --lim > 0; d++)
		if (!Isalnum(*d = fgetc(fp)))
		{
			ungetc(*d, fp);
			break;
		}
	*d = '\0';
	return *dest;
}

char *Strdup(const char *s)
{
	char *p;

	p = (char *) malloc(Strlen(s) + 1);
	if (p != NULL)
		Strcpy(p, s);
	return p;
}

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
#endif //#if defined(NEED_FILE_FUNCTION)

#if defined(KEY_TABLE)
/* for key word count */
struct kword
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
#define KEY_COUNT (sizeof(keytab) / sizeof(keytab[0]))
#endif   //defined(KEY_TABLE)

#endif

