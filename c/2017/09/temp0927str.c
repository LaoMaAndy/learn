/*
 * prototype. type functions. string functions. 8 + 11 + 4
 */

int Ispace(int c);
int Isdigit(int c);
int Isupper(int c);
int Islower(int c);
int Toupper(int c);
int Tolower(int c);
char *Strup(char *dest)
char *Strlow(char *dest);

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

int Atoi(const char *s);
double Atof(const char *s);
char *Itoa(int n, char *dest);
unsigned Getbits(unsigned x, int p, int n);
