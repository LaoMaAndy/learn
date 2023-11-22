/*
 * string functions
 */

int Strlen(const char *dest);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, int n);
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, int n);
char *Squeeze(char *dest, int chr);
char *Strstr(const char *dest, const char *src);
int Strindex(const char *dest, const char *src);
int Strcmp(const char *dest, const char *src);
char *Trim(char *dest);
char *Reverse(char *dest);

/*
 * implementation
 */

int Strlen(const char *dest)
{
	const char *d = dest;

	while(*d != '\0')
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

	while (*d != '\0')
		d++;
	while ((*d++ = *src++) != '\0')
		;
	return dest;
}

char *Strncat(char *dest, const char *src, int n)
{
	char *d = dest;

	while (*d != '\0')
		d++;
	while (n-- > 0)
		if ((*d++ = *src++) == '\0')
			return dest;
	*d = '\0';
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

	for ( ;*d != '\0'; d++)
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
	if (p != '\0')
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

	while (*d != '\0')
		d++;
	for (--d; d >= dest; d--)
		if (*d != ' ' && *d != '\t' && *d != '\n')
			break;
	if (d == dest)
		*d = '\0';
	else
		*++d = '\0';
	return dest;
}

char *Reverse(char *dest)
{
	char *p = dest, *q = dest;
	int c;

	while (*p != '\0')
		p++;
	for (--p; p > q; p--, q++)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
	return dest;
}

/*
 * test these function
 */
#include "00prn.h"
void test_str(void)
{	
	char s[100] = "12345";
	char t[100] = "abcdefg";
	char r[100] = "ABCDEFGHI";

	PRN_VAL(s, s);
	PRN_VAL(t, s);
	PRN_VAL(r, s);
	PRN_FUN(Strlen(s), d);
	PRN_FUN(Strcpy(s, t), s);
	PRN_FUN(Strncpy(s, t, 3), s);
	PRN_FUN(Strcat(s, t), s);
	PRN_FUN(Strncat(s, r, 2), s);
	PRN_FUN(Squeeze(s, 'a'), s);

	char d[100] = "12abc1234567890abc1234abca";
	char e[100] = "abc";
	char *p = d;
	int l;
	PRN_STR(----------);
	PRN_VAL(d, s);
	PRN_VAL(e, s);
	PRN_FUN(l = Strlen(e), d);
	PRN_FUN(Strindex(p, e), d);
	PRN_FUN(p = Strstr(p, e), s);
	PRN_SEN(p += l);
	PRN_VAL(p, s);
	PRN_FUN(Strindex(p, e), d);
	PRN_FUN(p = Strstr(p, e), s);
	PRN_SEN(p += l);
	PRN_VAL(p, s);
	PRN_FUN(Strindex(p, e), d);
	PRN_FUN(p = Strstr(p, e), s);

	char f[100] = "Abde    ";
	char g[100] = " "; 
	PRN_STR(--------);
	PRN_VAL(f, s);
	PRN_VAL(g, s);
	PRN_FUN(Strlen(f), d);
	PRN_FUN(Strlen(Trim(f)), d);
	PRN_VAL(f, s);
	PRN_FUN(Strlen(Trim(g)), d);
	PRN_FUN(Strlen(""), d);

	char h[100] = "1234567";
	PRN_STR(-------);
	PRN_VAL(h, s);
	PRN_FUN(Reverse(h), s);
	PRN_PRN("test micro PRN_PRN. variable h's value is :%s\n", h);
}

/*
 * Main fucntion
 */

int main(int argc, char *argv[])
{
	test_str();

	return 0;
}
