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
	size_t i;

	for (i = 0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return dest;
}
char *Strcpy2(char *dest, const char *src)
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
	size_t i, dest_len = Strlen(dest);

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
char *Strstr(const char *dest, const char *sub)
{
	size_t i;
	size_t n = Strlen(sub);

	for (i = 0; dest[i] != '\0'; ++i)
		if (dest[i] == sub[0])
			if (Strncmp(dest + i, sub, n) == 0)
				return (char *) dest + i;
	return NULL;
}
size_t Strindex(const char *dest, const char *sub)
{
	char *p = Strstr(dest, sub);
	
	if (p != NULL)
		return p - dest;
}
char *Strchr(const char *dest, char c)
{
	size_t i;

	for (i = 0; dest[i] != '\0'; ++i)
		if (dest[i] == c)
			return (char *)dest + i;
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
size_t Strcspn(const char *dest, const char *pre)
{
	size_t i;

	for (i = 0; dest[i] != '\0'; ++i)
		if (Strchr(pre, dest[i]) != NULL)
			break;
	return i;
}
char *Strpbrk(const char *dest, const char *pre)
{
	size_t i;

	i = Strcspn(dest, pre);
	if (dest[i] == '\0')
		return NULL;
	return (char *) dest + i;
}
char *Strrev(char *s)
{
	char *p, *q;
	char c;

	p = q = s;
	q += Strlen(s);
	for (--q; q > p; ++p, --q)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
	return s;
}
char *Strtrim(char *s)
{
	char *p, *q, *r;

	for (p = s; *p != '\0'; ++p)
		if (!Isspace(*p))
			break;
	for (q = s + Strlen(s) - 1; q >= p; --q)
		if (!Isspace(*q))
			break;
	*++q = '\0';
	if (p != s)
		for (r = s; p <= q; ++p, ++r)
			*r = *p;
	return s;
}
char *Strsqz(char *s, char c)
{ 
	size_t i, j;

	for (i = j = 0; s[i] != '\0'; ++i)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
	return s;
}
char *Strsqzs(char *s, const char *sqz)
{
	size_t i;

	for (i = 0; sqz[i] != '\0'; ++i)
		Strsqz(s, sqz[i]);
	return s;
}
char *Strdup(const char *s)
{
	char *p;

	p = (char *) malloc(Strlen(s) + 1);
	if (p != NULL)
		Strcpy(p, s);
	return p;
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
	size_t i;

	for (i = 0; s[i] != '\0'; ++i)
		s[i] = Tolower(s[i]);
	return s;
}


