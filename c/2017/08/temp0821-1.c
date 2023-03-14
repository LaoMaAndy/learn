/*
 * prototype: some function of string
 */

int Strlen(char *s);
char *Strcpy(char *s, char *t);
char *Strcat(char *s, char *t);
char *Squeeze(char *s, int c);

/*
 * implementation
 */

int Strlen_v0(char *s)
{
	char *p = s;

	while (*s)
		++s;
	return s - p;
}

int Strlen_v1(char *s)
{
	int i;

	for (i = 0; s[i]; ++i)
		;
	return i;
}

int Strlen_v2(char *s)
{
	int i = 0;

	while (s[i])
		++i;
	return i;
}

int Strlen_v3(char *s)
{
	char *p = s;

	while (*p++)
		;
	return p - s;
}

int Strlen(char *s)
{
	char *p;

	for (p = s; *p; ++p)
		;
	return p - s;
}

char *Strcpy(char *s, char *t)
{
	char *p = s;

	while (*p++ = *t++)
		;
	return s;
}

char *Strcpy_v1(char *s, char *t)
{
	char *p = s;

	while (*p = *t)
		++p, ++t;
	return s;
}

char *Strcpy_v2(char *s, char *t)
{
	char *p;

	for (p = s; *s = *t; ++s, ++t)
		;
	return p;
}
	
char *Strcpy_v3(char *s, char *t)
{
	char *p;

	for (p = s; *s++ = *t++; )
		;
	return p;
}

char *Strcat(char *s, char *t)
{
	char *p = s;

	while (*s)
		++s;
	while (*s++ = *t++)
		;
	return p;
}

char *Squeeze(char *s, int c)
{
	char *p, *q = s;

	for (p = s; *s; ++s)
		if (*s != c)
			*p++ = *s;
	*p = '\0';
	return q;
}


/*
 * test this function
 */
#include <stdio.h>

void test_len(int (*func)(char *))
{
	char s[] = "123";

	printf("%s\n", s);
	printf("%d\n", func(s));
}

void test_cat(char *(*func)(char *, char*))
{
	char s[100] = "";
	char t[] = "efgh";

	printf("%s\n", func(s, t));
}

// main functino
#define CHECK(foo) printf("Testing function :"#foo"\n");foo

int main(int argc, char *argv[])
{

	int i;

	CHECK(test_len(Strlen_v0));
	CHECK(test_len(Strlen_v1));
	CHECK(test_len(Strlen_v2));
	CHECK(test_len(Strlen_v3));
	CHECK(test_cat(Strcat));

	for (i = 0; i < 7; i++)
		printf("%c", i["0123456"]);
	printf("\n");

	return 0;
}
