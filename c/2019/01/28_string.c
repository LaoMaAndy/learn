/* string.c */
#include "template/head.h"

size_t Strlen(const char *s)
{
	const char *p;

	for (p = s; *p != '\0'; ++p)
		;
	return p - s;
}
char *Strcpy(char *dest, const char *src)
{
	char *p = dest;

	while ((*dest++ = *src++) != '\0')
		;
	return p;
}
char *Strncpy(char *dest, const char *src, size_t n)
{
	char *p = dest;
	for ( ; n != 0; --n)
		if ((*dest++ = *src++) == '\0')
			break;
	for ( ; n != 0; --n)
	   *dest++ = '\0';
	return p;
}
char *Strcat(char *dest, const char *src)
{
	char *p = dest;
	
	dest += Strlen(dest);
	Strcpy(dest, src);
	return p;
}
char *Strncat(char *dest, const char *src, size_t n)
{
	char *p = dest;
	dest += Strlen(dest);
	for ( ; n != 0; --n)
		if ((*dest++ = *src++) == '\0')
			break;
	return p;
}
int Strcmp(const char *s, const char *t)
{
	for ( ; *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
int Strncmp(const char *s, const char *t)
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
					beak;
			if (*s == '\0')
				return (char *)dest;
		}
	return NULL;
}
size_t Strindex(const char *dest, const char *sub)
{
	const char *d;
	 d = Strstr(dest, sub);
	 if (d != NULL)
		 return d - dest;
	 return -1;
}
char *Strchr(const char *dest, char chr)
{
	const char *d = dest;

	for ( ; dest != '\0'; ++dest)
		if (*dest == chr)
			return (char *) dest;
	return NULL;
}
char *Strrchr(const char *dest, char chr)
{
	size_t n = Strlen(dest);

	for ( ; n > 0; --n)
		if (dest[n] == chr)
			return (char *) dest;
	return NULL;
}

