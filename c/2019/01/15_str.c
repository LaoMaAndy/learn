/* string.c */
#include "./template/head.h"

size_t Strlen(const char *dest)
{
	const char *s;

	for (s = dest; *s != '\0'; ++s)
		;
	return s - dest;
}
char *Strcpy(char *dest, const char *src)
{
	char *d = dest;

	while ((*d++ = *src++) != '\0')
		;
	return dest;
}
char *Strncpy(char *dest, const char *src, size_t n)
{
	char *d = dest;

	for ( ; n != 0; --n)
		if ((*dest++ = *src++) == '\0')
			break;
	for ( ; n != 0; --n)
		*dest++ = '\0';
	return dest;
}
char *Strcat(char *dest, const char *src)
{
	char *d = dest;

	d += Strlen(d);
	Strcpy(d, src);
	return dest;
}
char *Strncat(char *dest, const char *src, size_t n)
{
	char *d = dest;

	d += Strlen(d);
	for ( ; n != 0; --n)
		if ((*d++ = *src++) == '\0')
			break;
	return dest;
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
	for ( ; n > 1 && *s == *t; ++s, ++t, --n)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
char *Strstr(const char *dest, const char *sub)
{
	const char *d, *s;

	for ( ; *dest != '\0'; ++dest)
		if (*dest == *sub)
		{
			d = dest + 1;
			s = sub + 1;
			for ( ; *d == *s; ++d, ++s)
				if (*d == '\0')
					break;
			if (*s == '\0')
				return (char *) dest;
		}
	return NULL;
}
size_t Strlen(const char *dest);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, size_t n);
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, size_t n);
int Strcmp(const char *s, const char *t);
int Strncmp(const char *s, const char *t, size_t n);
char *Strstr(const char *dest, const char *sub);
size_t Strindex(const char *dest, const char *sub);
char *Strchr(const char *dest, char chr);
char *Strrchar(const char *dest, char chr);
size_t Strspn(const char *dest, char *pre);
size_t Strcspn(const char *dest, char *npre);
char *Strpbrk(const char *dest, char *npre);
char *Strrev(char *dest);
char *Strtrim(char *dest);
char *Strsqz(char *dest, char c);
char *Strsqzs(char *dest, const char *s);
char *Strdup(const char *dest);
char *Strtoup(char *dest);
char *Strtolow(char *dest);

