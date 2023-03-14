/*
function: string
*/
#define NEED_TYPE
#include "0haed.c"

size_t Strlen(const char *dest);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, size_t n);
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, size_t n);
int Strcmp(const char *s, const char *t);
int Strncmp(const char *s, const char *t, size_t n);
char *Strstr(const char *dest, const char *sub);
size_t Strindex(const char *dest, const char *sub);
char *Strchr(const char *dest, int chr);
char *Strrchr(const char *dest, int chr);
size_t Strspn(const char *dest, const char *pre);
size_t Strcspn(const char *dest, const char *pre);
char *Strpbrk(const char *dest, const char *pre);
char *Squeeze(char *dest, int chr);
char *Trim(char *dest);
char *Reverse(char *dest);
char *Strdup(char *dest);
char *Strtoup(char *dest);
char *Strtolow(char *dest);


