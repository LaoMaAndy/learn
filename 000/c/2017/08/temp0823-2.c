/*
 * String functions
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
	for ( ; *p++ = *t++; )
		;
	return s;
}

char *Squeeze(char *s, int c)
{
	char *p, *q;

	for (p = q = s; *p; ++p)
		if (*p != c)
			*q++ = *p;
	*q = '\0';
	return s;
}

/*
 * test
 */
#include <stdio.h>

void test_str(void)
{
	char s[100] = "123456";
	char t[100] = "asbcdefg";
	char r[100] = "!@#$%^&";

	printf("Strlen of 123456 is %d\n", Strlen(s));
	printf("Strcpy : %s\n", Strcpy(s, t));
	printf("Strcat : %s\n", Strcat(t, r));
	printf("Squeeze 'a' :%s\n",  Squeeze(t, 'a'));
}

/*
 * Main function
 */

int main(int argc, char *argv[])
{
	test_str();

	return 0;
}

