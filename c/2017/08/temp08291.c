/*
 * prototype : String functions
 */
int Strlen(char *s);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, int n);
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, int n);
char *Squeeze(char *dest, int chr);
int Strcmp(const char *s1, const char *s2);
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

char *Strcpy_1(char *dest, const char *src)
{
	char *d = dest;
	
	while ((*d = *src) != '\0')
	{
		d++;
		src++;
	}
	return dest;
}

#include <stdio.h>
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

	while (*d !=  '\0')
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
	for ( ; n > 0; --n)
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
			*q++= c;
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

/*
 * test
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
}

/*
 * Main function
 */
#define TEST(foo) printf("Testing function: "#foo"\n");foo

int main(int argc, char *argv[])
{
	TEST(test_str());

	return 0;
}

