/*
  prototype: function of string
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
	char *p = s;

	while (*p)
		p++;
	while (*p++ = *t++)
		;
	return s;
}

#include <stdio.h>
void test_str(void)
{
	char s[100] = "012345";
	char t[] = "abcdefg";

	printf("String: %s Strlen is: %d\n", s, Strlen(s));
	printf("String: %s Strcpy %s is: %s\n", s, t, Strcpy(s, t));
	printf("s is %s, t is %s, Strcat is:%s \n", s, t, Strcat(s, t));
}

#define TEST(foo) printf("Testing function: "#foo"\n");foo
int main(int argc, char *argv[])
{
	test_str();

	return 0;
}
