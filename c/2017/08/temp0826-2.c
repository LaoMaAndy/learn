/*
 * String function prototype
 */

int  Strlen(const char *str);
char *Strcpy(char *dest, const char *src);
char *Strcat(char *dest, const char *src);
char *Squeeze(char *str, int chr);

/*
 * implementation
 */

int Strlen(const char *str)
{
	const char *p = str;

	while (*p != '\0')
		++p;
	return p - str;
} // that's OK

char *Strcpy(char *dest, const char *src)
{
	char *d = dest;

	while ((*d++ = *src++) != '\0')
		;
	return dest;
} // that's OK

char *Strcat(char *dest, const char *src)
{
	char *d = dest;

	while (*d != '\0')
		++d;
	while ((*d++ = *src++) != '\0')
		;
	return dest;
}// that's OK

char *Squeeze(char *str, int chr)
{
	char *s = str;
	char *p = str;
	int c;

	while ((c = *s++) != '\0')
		if (c != chr)
			*p++ = c;
	*p = '\0';
	return str;
} // that's OK
	

/*
 * test
 */
#include <stdio.h>

void test_str(void)
{
	char s[100] = "12345";
	char t[100] = "abcdefg";
	char r[100] = "ABCDEFGHI";

	printf("%d\n", Strlen(s));
	printf("Strcpy:  %s\n", Strcpy(s, t));
	printf("Strcat:  %s\n", Strcat(s, r));
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


