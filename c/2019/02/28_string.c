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
	size_t i, dest_len;

	dest_len = Strlen(dest);
	for (i = 0; i < n && src[i] != '\0'; ++i)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
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
	size_t i;

	if (n == 0)
		return 0;
	for (i = 0; i < n - 1 && s[i] == t[i]; ++i)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}
char *Strstr(const char *dest, const char *src)
{
	size_t n = Strlen(src);

	for ( ; *dest != '\0'; ++dest)
		if (*dest == *src)
			if (Strncmp(dest, src, n) == 0)
				return (char *) dest;
	return NULL;
}
size_t Strindex(const char *dest, const char *src)
{
	const char *p = dest;

	dest = Strstr(dest, src);
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
	const char *p = dest;

	for ( ; *dest != '\0'; ++dest)
		if (Strchr(pre, *dest) == NULL)
			break;
	return dest - p;
}
size_t Strcspn(const char *dest, const char *npre)
{
	const char *p = dest;

	for ( ; *dest != '\0'; ++dest)
		if (Strchr(npre, *dest) != NULL)
			break;
	return dest - p;
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

	p = q = s;
	s += Strlen(s);
	for (--s; s > p; --s, ++p)
	{
		c = *s;
		*s = *p;
		*p = c;
	}
	return q;
}
char *Strdup(const char *s)
{
	char *p;

	p = (char *) malloc(Strlen(s) + 1);
	if (p == NULL)
		return p;
	return Strcpy(p, s);
}
char *Strsqz(char *s, char c)
{
	char *p, *q;

	p = q = s;
	for ( ; *s != '\0'; ++s)
		if (*s != c)
			*p++ = *s;
	*p = '\0';
	return q;
}
char *Strsqzs(char *s, const char *sq)
{
	for ( ; *sq != '\0'; ++sq)
		Strsqz(s, *sq);
	return s;
}
char *Strtoup(char *s)
{
	char *p = s;

	for ( ; *s != '\0'; ++s)
		*s = Toupper(*s);
	return p;
}
char *Strtolow(char *s)
{
	char *p = s;

	for ( ; *s != '\0'; ++s)
		*s = Tolower(*s);
	return p;
}
char *Strlead(char *s)
{
	char *p = s;

	for ( ; *s != '\0'; ++s)
		if (!Isspace(*s))
			break;
	if (s != p)
		Strcpy(p, s);
	return p;
}
char *Strtail(char *s)
{
	char *p = s;

	s += Strlen(s);
	for (--s; s >= p; --s)
		if (!Isspace(*s))
			break;
	*++s = '\0';
	return p;
}
char *Strtrim(char *s)
{
	return Strlead(Strtail(s));
}
