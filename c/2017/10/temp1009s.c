/*
String functions
*/

int Strlen(const char *s);
char *Strcpy(char *dst, const char *src);
char *Strncpy(char *dst, const char *src, int n);
char *Strcat(char *dst, const char *src);
char *Strncat(char *dst, const char *src, int n);
char *Strstr(const char *dst, const char *sub);
int Strindex(const char *dst, const char *sub);
int Strcmp(const char *s, const char *t);
int Strncmp(const char *s, const char *t, int n);
char *Strchr(const char *dst, int chr);
char *Strrchr(const char *dst, int chr);
int *Strspn(const char *dst, char *pre);
int *Strcspn(const char *dst, char *npre);
char *Strpbrk(const char *dst, char *pre);
char *Squeeze(char *dst, int chr);
char *Trim(char *dst);
char *Reverse(char *dst);
char *Strdup(const char *dst);
char *Strtoup(char *dst);
char *Strtolow(char *dst);


