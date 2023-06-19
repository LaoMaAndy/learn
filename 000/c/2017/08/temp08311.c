/*
 * prototype: String functions
 */

int Strlen(char *s);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, int n);
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, int n);
char *Squeeze(char *dest, int chr);
int Strcmp(const char *s, const char *t);
char *Strstr(const char *dest, const char *sub);

/*
 * implementation
 */

int Strlen(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;
	return p - s;
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

	for ( ; n > 0; --n)
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
	while((*d++ = *src++) != '\0')
		;
	return dest;
}

char *Strncat(char *dest, const char *src, int n)
{
	char *d = dest;

	while (*d != '\0')
		d++;
	for ( ; n > 0; --n)
		if ((*d++ = *src++) == '\0')
			return dest;
	*d = '\0';
	return dest;
}

char *Squeeze(char *dest, int chr)
{
	char *p = dest;
	char *q = dest;
	int c;

	while ((c = *p++) != '\0')
		if (c != chr)
			*q++ = c;
	*q = '\0';
	return dest;
}

char *Squeeze(char *dest, char chr)
{
	char *p = dest, *q = dest;
	char c;

	while ((c = *p++) != '\0')
		if (c != chr)
			*q++ = c;
	*q = '\0';
	return dest;
}

int Strcmp(const char *s, const char *t)
{
	for( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}


int Strcmp(const char *s, const char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

char *Strstr(const char *dest, const char *sub)
{
	const char *d;
	int i;

	for (d = dest; *d != '\0'; ++d)
		if (*d == *sub)
		{
			for (i = 1; d[i] == sub[i] && d[i] != '\0'; ++i)
				;
			if (sub[i] == '\0')
				return (char *)d;
		}
	return (char *)0;
}

char *Strstr(const char *dest, const char *sub)
{
	const char *d;
	int i;

	for (d = dest; *d != '\0'; ++d)
		if (*d == *sub)
		{
			for (i = 1; d[i] == sub[i] && d[i] != '\0'; ++i)
				;
			if (sub[i] == '\0')
				return (char *)d;
		}
	return (char *)0;
}

/*
 * test these function
 */
#include <stdio.h>

void test_str(void)
{	
	char s[100] = "12345";
	char t[100] = "abcdefg";
	char r[100] = "ABCDEFGHI";

	printf("String s: %s\n", s);
	printf("%d\n", Strlen(s));
	printf("Strcpy:  %s\n", Strcpy(s, t));
	printf("Strncpy: %s\n", Strncpy(s, t, 100));
	printf("Strcat:  %s\n", Strcat(s, r));
	printf("Strncat: %s\n", Strncat(s, r, 100));
	printf("Squeeze: %s\n", Squeeze(s, 'a'));

	char d[100] = "abc1234567890abc1234abca";
	char e[100] = "abc";
	char *p;
	int n;
	int l;
	l = Strlen(e);
	p = d;
	printf("Strstr: %s\n", p = Strstr(p, e));
	p += l;
	printf("Strstr: %s\n", p = Strstr(p, e));
	p += l;
	printf("Strstr: %s\n", p = Strstr(p, e));
}

/*
 * Main fucntion
 */

int main(int argc, char *argv[])
{
	test_str();

	return 0;
}


