/*
 * String function prototype
 */

int Strlen(char *s);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, int n);
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, int n);
char *Squeeze(char *dest, int chr);
int Strcmp(const char *s, const char *t);
char *Strstr(const char *s, const char *sub);

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
	for ( ; n > 0; n--)
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

	for (d = dest; *d != '\0'; d++)
		if (*d == *sub)
		{
			for (i = 1; d[i] == sub[i] && d[i] != '\0'; ++i)
				;
			if (sub[i] == '\0')
				return (char *)d;
		}
	return (char *)0; 
}

#include <stdio.h>
int main(int argc, char *argv[])
{
	char d[100] = "abc1234567890abc1234abca";
	char s[100] = "abc";
	char *p;
	int n;
	int l;

	l = Strlen(s);
	p = d;
	printf("Strstr: %s\n", p = Strstr(p, s));
	p += l;
	printf("Strstr: %s\n", p = Strstr(p, s));
	p += l;
	printf("Strstr: %s\n", p = Strstr(p, s));


	return 0;
}
