/* string.c */
#include "template/head.h"

size_t Strlen(const char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
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
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; ++i)
		dest[i] = src[i];
	for ( ; i < n; ++i)
		dest[i] = '\0';
	return dest;
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
	size_t i;
	size_t dest_len = Strlen(dest);

	for (i = 0; i < n && src[i] != '\0'; ++i)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return dest;
}
int Strcmp(const char *s, const char *t)
{
	for( ; *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
int Strncmp(const char *s, const char *t, size_t n)
{
	if (n == 0)
		return 0;
	for ( ; --n > 0 && *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
char *Strstr(const char *dest, const char *sub)
{
	size_t n = Strlen(sub);

	for ( ; *dest != '\0'; ++dest)
		if (*dest == *sub)
			if (Strncmp(dest, sub, n) == 0)
				return (char *) dest;
	return NULL;
}
size_t Strindex(const char *dest, const char *sub)
{
	const char *p = dest;

	dest = Strstr(dest, sub);
	if (dest == NULL)
		return -1;
	return dest - p;
}
char *Strchr(const char *dest, char c)
{
	for ( ; *dest != '\0'; ++dest)
		if (*dest == c)
			return (char *) dest;
	return NULL;
}
char *Strrchr(const char *dest, char c)
{
	const char *p = dest;

	dest += Strlen(dest);
	for (--dest; dest >= p; --dest)
		if (*dest == c)
			return (char *) dest;
	return NULL;
}
size_t Strspn(const char *dest, const char *pre)
{
	size_t i;

	for (i = 0; dest[i] != '\0'; ++i)
		if (Strchr(pre, dest[i]) == NULL)
			break;
	return i;
}
size_t Strcspn(const char *dest, const char *npre)
{
	size_t i;

	for (i = 0; dest[i] != '\0'; ++i)\
		if (Strchr(npre, dest[i]) != NULL)
			break;
	return i;
}
char *Strpbrk(const char *dest, const char *npre)
{
	dest += Strcspn(dest, npre);
	if (*dest == '\0')
		return NULL;
	return (char *) dest;
}
char *Strrev(char *s)
{
	char *p, *q;
	char c;

	p = s;
	q = s + Strlen(s) - 1;
	for ( ; q > p; --q, ++p)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
	return s;
}
char *Strdup(const char *s)
{
	char *p;

	p = (char *) malloc(Strlen(s) + 1);
	if (p == NULL)
		return NULL;
	return Strcpy(p, s);
}
char *Strsqz(char *s, char c)
{
	char *p, *q;

	p = q = s;
	for ( ; *p != '\0'; ++p)
		if (*p != c)
			*q++ = *p;
	return s;
}
char *Strsqzs(char *s, const char *sqz)
{
	for ( ; *sqz != '\0'; ++sqz)
		Strsqz(s, *sqz);
	return s;
}
char *Strtrim(char *s)
{
	char *p, *q;

	for (p = s; *p != '\0'; ++p)
		if (!Isspace(*p))
			break;
	q = s + Strlen(s) - 1;
	for (; q >= p; --q) 
		if (!Isspace(*q))
			break;
	*++q = '\0';
	if (p != s)
		Strcpy(s, p);
	return s;
}
char *Strtoup(char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; ++i)
		s[i] = Toupper(s[i]);
	return s;
}
char *Strtolow(char *s)
{
	char *p = s;

	for ( ; *s != '\0'; ++s)
		*s = Tolower(*s);
	return p;
}


