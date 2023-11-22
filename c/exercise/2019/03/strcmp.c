/* strcmp.c */
#include <stdio.h>
#include <stdlib.h>

size_t Strlen(const char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}
int Strcmp(const char *s, const char *t)
{
	for ( ; *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
int Strncmp(const char *s, const char *t, size_t n)
{
	size_t i;

	for (i = 0; i < n - 1 && s[i] == t[i]; ++i)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}
char *Strstr(const char *dest, const char *sub)
{
	size_t i, j;


}
