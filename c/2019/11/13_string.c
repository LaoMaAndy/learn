/*
 * string.c
 */
#include "head.h"

size_t Strlen(const char *s) {
	const char *base = s;

	for ( ; *s != '\0'; ++s)
		;
	return s - base;
}
char *Strcpy(char *dest, const char *src) {
	char *ret = dest;

	while ((*dest++ = *src++) != '\0')
		;
	return ret;
}
char *Strncpy(char *dest, const char *src, size_t n) {
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; ++i)
		dest[i] = src[i];
	for ( ; i < n; ++i)
		dest[i] = '\0';
	return dest;
}
char *Strcat(char *dest, const char *src) {
	char *ret = dest;

	dest += Strlen(dest);
	Strcpy(dest, src);
	return ret;
}
char *Strncat(char *dest, const char *src, size_t n) {
	size_t dest_len, i;

	dest_len = Strlen(dest);
	for (i = 0; i < n && src[i] != '\0'; ++i)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return dest;
}
int Strcmp(const char *s, const char *t) {
	for ( ; *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
int Strncmp(const char *s, const char *t, size_t n) {
	size_t i;

	if (n == 0)
		return 0;
	for (i = 0; i < n - 1 && s[i] == t[i]; ++i)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}
char *Strstr(const char *dest, const char *sub) {
	size_t len;

	len = Strlen(sub);
	for ( ; *dest != '\0'; ++dest)
		if (*dest == *sub)
			if (Strncmp(dest, sub, len) == 0)
				return (char *) dest;
	return NULL;
}
size_t Strindex(const char *dest, const char *sub) {
	const char *base = dest;

	dest = Strstr(dest, sub);
	return (dest == NULL) ? -1 : (dest - base);
}
char *Strchr(const char *dest, char c) {
	for ( ; *dest != '\0'; ++dest)
		if (*dest == c)
			return (char *) dest;
	return NULL;
}
char *Strrchr(const char *dest, char c) {
	const char *base = dest;

	dest += Strlen(dest);
	for (--dest; dest >= base; --dest)
		if (*dest == c)
			return (char *) dest;
	return NULL;
}
size_t Strspn(const char *dest, const char *pre) {
	const char *base = dest;

	for ( ; *dest != '\0'; ++dest)
		if (Strchr(pre, *dest) == NULL)
			break;
	return dest - base;
}
size_t Strcspn(const char *dest, const char *npre) {
	const char *base = dest;

	for ( ; *dest != '\0'; ++dest)
		if (Strchr(npre, *dest) != NULL)
			break;
	return dest - base;
}
char *Strpbrk(const char *dest, const char *npre) {
	dest += Strcspn(dest, npre);
	return (*dest == '\0') ? NULL : (char *) dest;
}
char *Strrev(char *dest) {
	char *front, *back, c;

	front = back = dest;
	back += Strlen(dest);
	for (--back; back > front; --back, ++front) {
		c = *back;
		*back = *front;
		*front = c;
	}
	return dest;
}
char *Strdup(const char *s) {
	char *p;

	p = (char *) malloc(Strlen(s) + 1);
	return (p == NULL) ? p : Strcpy(p, s);
}
char *Strsqz(char *dest, char c) {
	char *cur, *ret;

	cur = ret = dest;
	for ( ; *dest != '\0'; ++dest)
		if (*dest != c)
			*cur++ = *dest;
	*cur = '\0'; 
	return ret;
}
char *Strsqzs(char *dest, const char *sq) {
	for ( ; *sq != '\0'; ++sq)
		Strsqz(dest, *sq);
	return dest;
}
char *Strtoup(char *dest) {
	char *ret = dest;

	for ( ; *dest != '\0'; ++dest)
		*dest = Toupper(*dest);
	return ret;
}
char *Strtolow(char *dest) {
	char *ret = dest;

	for ( ; *dest != '\0'; ++dest)
		*dest = Tolower(*dest);
	return ret;
}
char *Strlead(char *dest) {
	char *cur = dest;

	for ( ; *dest != '\0'; ++dest)
		if (!Isspace(*dest))
			break;
	return (dest == cur) ? dest : Strcpy(cur, dest);
}
char *Strtail(char *dest) {
	char *base = dest;

	dest += Strlen(dest);
	for (--dest; dest >= base; --dest)
		if (!Isspace(*dest))
			break;
	*++dest = '\0';
	return base;
}
char *Strtrim(char *dest) {
	return Strlead(Strtail(dest));
}