#define NEE_TYPE_FUNCTION
#include "0head.c"

/*
 function of strings
 */

int Strlen(const char *dest);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, int n);
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, int n);
char *Squeeze(char *dest, int chr);
int Strcmp(const char *s, const char *t);
char *Strstr(const char *dest, const char *sub);
int Strindex(conat char *dest, const char *sub);
char *Trim(char *dest);
char *Reverse(char *dest);
char *Strtoup(char *dest);
char *Strtolow(char *dest);
char *Strdup(const char *dest)
{
	char *p;

	p = (char *) malloc(Strlen(dest) + 1);
	if (p != 0)
		Strcpy(p, dest);
	return p;
}


