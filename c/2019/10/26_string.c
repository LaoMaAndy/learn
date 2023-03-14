/*
 * string.c
 */
#include "head.h"
size_t Strlen(const char *s) {
	size_t i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}
char *Strcpy(char *dest, const char *src) {
	char *ret = dest;

	while ((*dest++ = *src++) != '\0')
		;
	return ret;
}
