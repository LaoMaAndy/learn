/*
function: strings
*/
#define NEED_TYPE
#include "0head.c"
int Strlen(const char *dest)
{
	const char *d = dest;
	
	while (*dest != '\0')
		++dest;
	return dest - d;
}
char *Strcpy(char *dest, const char *src)
{
	char *d = dest;

	while ((*dest++ = *src++) != '\0')
		;
	return d;
}
char *Strncpy(char *dest, const char *src, int n)
{
	char *d = dest;

	while (n-- > 0)
		if ((*dest++ = *src++) == '\0')
			return d;
	*dest = '\0';
	return d;
}
char *Strcat(char *dest, const char *src)
{
	char *d = dest;

	dest += Strlen(dest);
	Strcpy(dest, src);
	return d;
}
char *Strncat(char *dest, const char *src, int n)
{
	char *d = dest;

	dest += Strlen(dest);
	Strncpy(dest, src, n);
	return d;
}
char *Strstr(const char *dest, const char *sub)
{
	const char *s, *d;

	for ( ; *dest != '\0'; ++dest)
		if (*dest == *sub)
		{
			for (d = dest + 1, s = sub + 1; *d == *s && *d != '\0'; ++d, ++s)
				;
			if (*s == '\0')
				return (char *) dest;
		}
	return NULL;
}
int Strindex(const char *dest, const char *sub)
{
	const char *p;
	
	p = Strstr(dest, sub);
	if (p != NULL)
		return p - dest;
	return -1;
}
int Strcmp(const char *s, const char *t)
{
	for ( ; *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
int Strncmp(const char *s, const char *t, int n)
{
	for ( ; --n > 0 && *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
char *Strchr(const char *dest, int chr)
{
	for ( ; *dest != '\0'; ++dest)
		if (*dest == chr)
			return (char *) dest;
	return NULL;
}
char *Strrchr(const char *dest, int chr)
{
	const char *d = dest;

	for (dest += Strlen(dest) - 1; dest >= d; --dest)
		if (*dest == chr)
			return (char *) dest;
	return NULL;
}
int Strspn(const char *dest, const char *pre)
{
	const char *d = dest;

	for ( ; *dest != '\0'; ++dest)
		if (Strchr(pre, *dest) == NULL)
			break;
	return dest - d;
}
int Strcspn(const char *dest, const char *pre)
{
	const char *d = dest;

	for ( ; *dest != '\0'; ++dest)
		if (Strchr(pre, *dest) != NULL)
			break;
	return dest - d;
}
char *Strpbrk(const char *dest, const char *pre)
{
	dest += Strcspn(dest, pre);
	if (*dest != '\0')
		return (char *) dest;
	return NULL;
}
char *Squeeze(char *dest, int chr)
{
	char *p, *q;

	p = q = dest;
	for ( ; *p != '\0'; ++p)
		if (*p != chr)
			*q++ = *p;
	*q = '\0';
	return dest;
}
char *Trim(char *dest)
{
	char *d = dest;

	for (dest += Strlen(dest) - 1; dest >= d; --dest)
		if (!Isspace(*dest))
			break;
	*++dest = '\0';
	return d;
}
char *Reverse(char *dest)
{
	char *p, *q;
	int c;

	p = q = dest;
	for (p += Strlen(dest) - 1; p > q; --p, ++q)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
	return dest;
}
char *Strdup(const char *dest)
{
	char *d;

	d = (char *) malloc(Strlen(dest) + 1);
	if (d != NULL)
		Strcpy(d, dest);
	return d;
}
char *Strtoup(char *dest)
{
	char *d = dest;

	for ( ; *dest != '\0'; ++dest)
		*dest = Toupper(*dest);
	return d;
}
char *Strtolow(char *dest)
{
	char *d = dest;

	for ( ; *dest != '\0'; ++dest)
		*dest = Tolower(*dest);
	return d;
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
	char n[100] = "abcdefg";
	PRN_VAR(i, s);
	PRN_VAL(m, s);
	PRN_VAL(n, s);
	PRN_FUN(Strspn(i, m), d);
	PRN_FUN(Strcspn(i, n), d);
	PRN_FUN(Strpbrk(i, m), s);
	PRN_FUN(Strpbrk(i, n), s);

	char as[] = "1234567";
	char bs[] = "abcde";
	char cs[] = "1234567";
	PRN_VAL(as, s);
	PRN_VAL(bs, s);
	PRN_VAL(cs, s);
	PRN_FUN(Strspn(as, bs), d);
	PRN_FUN(Strspn(as, cs), d);
	PRN_FUN(Strcspn(as, bs), d);
}


	
/*
 * Main fucntion
 */

int main(int argc, char *argv[])
{
	test_str();

	return 0;
}




