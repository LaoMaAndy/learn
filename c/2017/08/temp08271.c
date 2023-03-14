/*
 * string function prototype
 */
#include <stdio.h>
int  Strlen(const char *str);
char *Strcpy(char *dest, const char *src);
char *Strcat(char *dest, const char *src);
char *Squeeze(char *str, int chr);

int Strcmp(const char *s1, const char *s2);
int Strstr(const char *s1, const char *s2);

char *Strncpy(char *dest, const char *src, int n);
char *Strncat(char *dest, const char *src, int n);


/*
 * implementation
 */

size_t Strlen(const char *str)
{
	const char *p = str;

	while (*p != '\0')
		p++;
	return p - str;
}

char *Strcpy(char *dest, const char *src)
{
	char *d = dest;

	while ((*d++ = *src++) != '\0')
		; 
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

char *Squeeze(char *str, int chr)
{
	char *p = str;
	char *q = str;
	int c;

	do 
		if ((c = *p++) != chr)
			*q++ = c;
	while (c != '\0');
	
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

	printf("%zd\n", Strlen(s));
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

