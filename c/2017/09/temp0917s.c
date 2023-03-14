/*
 * String functions
 */

int Strlen(const char *dest);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, int n);
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, int n);
char *Squeeze(char *dest, int chr);
char *Strstr(const char *dest, const char *sub);
int Strindex(const char *dest, const char *sub);
int Strcmp(const char *s, const char *t);
char *Trim(char *dest);
char *Reverse(char *dest);

