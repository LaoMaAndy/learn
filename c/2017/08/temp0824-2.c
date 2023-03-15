/*
 * prototype: some functions about String
 */
int Strlen(char *s);
char *Strcpy(char *s, char *t);
char *Strcat(char *s, char *t);
char *Squeeze(char *s, int c);

/*
 * implementation
 */

int Strlen(char *s)
{
	char *p;

	for (p = s; *p; p++)
		;
	return p - s;
}

char *Strcpy(char *s, char *t)
{
	char *p;

	for (p = s; *p++ = *t++; )
		;
	return s;
}

char *Strcat(char *s, char *t)
{
	char *p;

	for (p = s; *p; p++)
		;
	for ( ;*p++ = *t++; )
		;
	return s;
}

char *Squeeze(char *s, int c)
{
	char *p, *q;

	for (p = q = s; *p; p++)
		if (*p != c)
			*q++ = *p;
	*q = '\0';
	return s;
}

/*
 * test these function
 */
#include <stdio.h>

void test_str(void)
{
	char s[100] = "123456";
	char t[100] = "abcdefgabcdef";
	char r[100] = "!@#$%^";

	printf("length of 123456 is %d\n", Strlen(s));
	printf("Strcpy s, t: %s\n", Strcpy(s, t));
	printf("Strcat t, r: %s\n", Strcat(t, r));
	printf("Squeeze t, a: %s\n", Squeeze(t, 'a'));
}

/*
 * Main function
 */
#define TEST(func) printf("Testing function: "#func"\n");func

int main(int argc, char *argv[])
{
	TEST(test_str());

	return 0;
}

