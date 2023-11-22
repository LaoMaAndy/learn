/*
 * string.c 
 */
#include "head.h"

size_t Strlen(const char *s) {
	const char *base;

	for (base = s; *s != '\0'; ++s)
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
	size_t sub_len;

	sub_len = Strlen(sub);
	for ( ; *dest != '\0'; ++dest)
		if (*dest == *sub)
			if (Strncmp(dest, sub, sub_len) == 0)
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
	return NULL;
}
