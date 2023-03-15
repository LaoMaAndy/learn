/*
 String function
 */
 #define NEED_TYPE
 #include "0head.c"

int Strlen(const char *dest);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, int n);
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, int n);
char *Squeeze(char *dest, int chr);
int Strcmp(const char *s, const char *t);
char *Strstr(const char *dest, const char *sub);
int Strindex(const char *dest, const char *sub);
char *Trim(char *dest);
char *Reverse(char *dest);
char *Strdup(char *dest);
char *Strtoup(char *dest);
char *Strtolow(char *dest);
char *Strchr(const char *dest, int chr);
char *Strrchr(const char *dest, int chr);
int Strspn(const char *dest, const char *pre);
int Strcspn(const char *dest, const char *pre);
char *Strpbrk(const char *dest, const char *pre);

int Strlen(const char *dest)
{
	const char *d = dest;

	while (*d != '\0')
		d++;
	return d - dest;
}

char *Strcpy(char *dest, const char *src)
{
	char *d = dest;

	while ((*d++ = *src++) != '\0')
		;
	return dest;
}

char *Strncpy(char *dest, const char *src, int n)
{
	char *d = dest;

	while (n-- > 0)
		if ((*d++ = *src++) == '\0')
			return dest;
	*d = '\0';
	return dest;
}

char *Strcat(char *dest, const char *src)
{
	char *d = dest;

	d += Strlen(dest);
	Strcpy(d, src);
	return dest;
}

char *Strncat(char *dest, const char *src, int n)
{
	char *d = dest;

	d += Strlen(dest);
	Strncpy(d, src, n);
	return dest;
}

char *Squeeze(char *dest, int chr)
{
	char *p = dest, *q = dest;
	int c;

	while ((c = *p++) != '\0')
		if (c != chr)
			*q++ = c;
	*q = '\0';
	return dest;
}

int Strcmp(const char *s, const char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

char *Strstr(const char *dest, const char *sub)
{
	const char *d, *s;

	for ( ; *dest != '\0'; dest++)
		if (*dest == *sub)
		{
			for (d = dest, s = sub; *++d == *++s && *d != '\0'; )
				;
			if (*s == '\0')
				return (char *) dest;
		}
	return NULL;
}

int Strindex(const char *dest, const char *sub)
{
	const char *d;

	d = Strstr(dest, sub);
	if (d != NULL)
		return d - dest;
	return -1;
}

char *Trim(char *dest)
{
	char *d = dest;

	for (d += Strlen(dest) - 1; d >= dest; d--)
		if (!Isspace(*d))
			break;
	*++d = '\0';
	return dest;
}

char *Reverse(char *dest)
{
	char *p = dest, *q = dest;
	int c;

	for (p += Strlen(dest) - 1; p > q; p--, q++)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
	return dest;
}

char *Strdup(char *dest)
{
	char *d;

	d = (char *) malloc(Strlen(dest));
	if (d != NULL)
		Strcpy(d, dest);
	return d;
}

char *Strtoup(char *dest)
{
	int c;
	char *d = dest;

	while ((c = *d) != '\0')
		*d++ = Toupper(c);
	return dest;
}

char *Strtolow(char *dest)
{
	char *d = dest;
	int c;

	while ((c = *d) != '\0')
		*d++ = Tolower(c);
	return dest;
}

char *Strchr(const char *dest, int chr)
{
	for ( ; *dest != '\0'; dest++)
		if (*dest == chr)
			return (char *) dest;
	return NULL;
}

char *Strrchr(const char *dest, int chr)
{
	const char *d;

	for (d = NULL; *dest != '\0'; dest++)
		if (*dest == chr)
			d =  dest;
	return (char *) d;
}
	
int Strspn(const char *dest, const char *pre)
{
	const char *d;

	for (d = dest; *d != '\0'; d++)
		if (Strchr(pre, *d) == NULL)
			break;
	return d - dest;
}
		
int Strcspn(const char *dest, const char *pre)
{
	const char *d;

	for (d = dest; *d != '\0'; d++)
		if (Strchr(pre, *d) != NULL)
			break;
	return d - dest;
}

char *Strpbrk(const char *dest, const char *pre)
{
	const char *d;

	for (d = dest; *d != '\0'; d++)
		if (Strchr(pre, *d) != NULL)
			return (char *) d;
	return NULL;
}

/*
 * test these function
 */
void test_str(void)
{	
	char s[100] = "12345";
	char t[100] = "abcdefg";
	char r[100] = "ABCDEFGHI";

	PRN_VAL(s, s);
	PRN_VAL(t, s);
	PRN_VAL(r, s);
	PRN_FUN(Strlen(s), d);
	PRN_FUN(Strcpy(s, t), s);
	PRN_FUN(Strncpy(s, t, 3), s);
	PRN_FUN(Strcat(s, t), s);
	PRN_FUN(Strncat(s, r, 2), s);
	PRN_FUN(Squeeze(s, 'a'), s);

	char d[100] = "12abc1234567890abc1234abca";
	char e[100] = "abc";
	char *p = d;
	int l;
	PRN_STR(----------);
	PRN_VAL(d, s);
	PRN_VAL(e, s);
	PRN_FUN(l = Strlen(e), d);
	PRN_FUN(Strindex(p, e), d);
	PRN_FUN(p = Strstr(p, e), s);
	PRN_SEN(p += l);
	PRN_VAL(p, s);
	PRN_FUN(Strindex(p, e), d);
	PRN_FUN(p = Strstr(p, e), s);
	PRN_SEN(p += l);
	PRN_VAL(p, s);
	PRN_FUN(Strindex(p, e), d);
	PRN_FUN(p = Strstr(p, e), s);

	char f[100] = "Abde    ";
	char g[100] = " "; 
	PRN_STR(--------);
	PRN_VAL(f, s);
	PRN_VAL(g, s);
	PRN_FUN(Strlen(f), d);
	PRN_FUN(Strlen(Trim(f)), d);
	PRN_VAL(f, s);
	PRN_FUN(Strlen(Trim(g)), d);
	PRN_FUN(Strlen(""), d);

	char h[100] = "1234567";
	PRN_STR(-------);
	PRN_VAL(h, s);
	PRN_FUN(Reverse(h), s);
	PRN_PRN("test micro PRN_PRN. variable h's value is :%s\n", h);

	char a[100] = "AbCdEfGhIjK012#^";
	PRN_STR(-----------);
	PRN_VAR(a, s);
	PRN_FUN(Strtoup(a), s);
	PRN_FUN(Strtolow(a), s);
	PRN_FUN(Strdup(a), s);

	char i[100] = "12340eabcdefg5678eabcdefghi123e re12";
	PRN_VAR(i, s);
	PRN_FUN(Strchr(i, 'e'), s);
	PRN_FUN(Strrchr(i, 'e'), s);
	char m[100] = "1234567890";
	PRN_VAL(m, s);
	PRN_FUN(Strspn(i, m), d);
	char n[100] = "abcdefg";
	PRN_VAL(n, s);
	PRN_FUN(Strcspn(i, n), d);
	PRN_FUN(Strpbrk(i, m), s);
	PRN_FUN(Strpbrk(i, n), s);
}


	
/*
 * Main fucntion
 */

int main(int argc, char *argv[])
{
	test_str();


	return 0;
}

