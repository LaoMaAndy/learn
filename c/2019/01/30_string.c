/* string */
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
	const size_t dest_len = Strlen(dest);

	Strcpy(dest + dest_len, src);
	return dest;
}
char *Strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	const size_t dest_len = Strlen(dest);

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

	for (i = 0; i < n - 1 && s[i] == t[i]; ++i)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}
char *Strstr(const char *dest, const char *sub)
{
	size_t sub_len = Strlen(sub);
	size_t i;

	for (i = 0; dest[i] != '\0'; ++i)
		if (dest[i] == *sub)
			if (Strncmp(dest + i, sub, sub_len) == 0)
				return (char *) dest + i;
	return NULL;
}
size_t Strindex(const char *dest, const char *sub)
{
	char *p = Strstr(dest, sub);

	if (p != NULL)
		return p - dest;
	return -1;
}
char *Strchr(const char *dest, char chr)
{
	size_t i;

	for (i = 0; dest[i] != '\0'; ++i)
		if (dest[i] == chr)
			return (char *)dest + i;
	return NULL;
}
char *Strrchr(const char *s, char c)
{
	const char *p;

	p = s + Strlen(s);
	for (--p; p >= s; --p)
		if (*p == c)
			return (char *) p;
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

	for (i = 0; dest[i] != '\0'; ++i)
		if (Strchr(npre, dest[i]) != NULL)
			break;
	return i;
}
char *Strpbrk(const char *dest, const char *npre)
{
	dest += Strcspn(dest, npre);
	if (*dest != '\0')
		return (char *) dest;
	return NULL;
}
//error: if Strlen(dest) == 0; j = -1
char *Strrev(char *dest)
{
	size_t i, j;
	char c;

	for (i = 0, j = Strlen(dest) - 1; j > i; ++i, --j)
	{
		c = dest[i];
		dest[i] = dest[j];
		dest[j] = c;
	}
	return dest;
}
char *Strtrim(char *dest)
{
	char *p, *q, *r;

	q = dest + Strlen(dest);
	for (--q; q >= dest; --q)
		if (!Isspace(*q))
			break;
	*++q = '\0';
	for (p = dest; p < q; ++p)
		if (!Isspace(*p))
			break;
	if (p != dest)
		for (r = dest; p <= q; ++p, ++r)
			*r = *p;
	return dest;
}
char *Strsqz(char *s, char c)
{
	size_t i, j;

	for (i = 0, j = 0; s[i] != '\0'; ++i)
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
