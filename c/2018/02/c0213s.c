/*
function: string
*/
#define NEED_TYPE
#include "0head.c"

size_t Strlen(const char *dest)
{
	const char *d;

	for (d = dest; *d != '\0'; ++d)
		;
	return d - dest;
}
char *Strcpy(char *dest, const char *src)
{
	char *d = dest;

	while ((*d++ = *src++) != '\0')
		;
	return dest;
}
char *Strncpy(char *dest, const char *src, size_t n)
{
	char *d = dest;

	for ( ; n != 0; --n)
		if ((*dest++ = *src++) == '\0')
			break;
	for ( ; n != 0; --n)
	   *dest++ = '\0';
	return dest;
}	
char *Strcat(char *dest, const char *src)
{
	char *d = dest;

	d += Strlen(d);
	Strcpy(d, src);
	return dest;
}
char *Strncat(char *dest, const char *src, size_t n)
{
	char *d = dest;

	d += Strlen(d);
	for ( ; n != 0; --n)
		if ((*d++ = *src++) == '\0')
			break;
	return dest;
}
int Strcmp(const char *s, const char *t)
{
	for ( ; *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
int Strncmp(const char *s, const char *t, size_t n)
{
	for ( ; n > 1 && *s == *t; ++s, ++t, --n)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
char *Strstr(const char *dest, const char *sub)
{
	const char *d, *s;

	for ( ; *dest != '\0'; ++dest)
		if (*dest == *sub)
		{
			d = dest + 1;
			s = sub + 1;
			for ( ; *d == *s; ++d, ++s)
				if (*d == '\0')
					break;
			if (*s == '\0')
				return (char *) dest;
		}
	return NULL;
}
size_t Strindex(const char *dest, const char *sub)
{
	const char *d;

	d = Strstr(dest, sub);
	if (d != NULL)
		return d - dest;
	return -1;
}
char *Strchr(const char *dest, char chr)
{
	const char *d;

	for (d = dest; *d != '\0'; ++d)
		if (*d == chr)
			return (char *) d;
	return NULL;
}
char *Strrchr(const char *dest, char chr)
{
	const char *d;

	for (d = dest + Strlen(dest) - 1; d >= dest; --d)
		if (*d == chr)
			return (char *) d;
	return NULL;
}
size_t Strspn(const char *dest, char *pre)
{
	const char *d;

	for (d = dest; *d != '\0'; ++d)
		if (Strchr(pre, *d) == NULL)
			break;
	return d - dest;
}
size_t Strcspn(const char *dest, char *npre)
{
	const char *d;

	for (d = dest; *d != '\0'; ++d)
		if (Strchr(npre, *d) == NULL)
			break;
	return d - dest;
}
char *Strpbrk(const char *dest, char *npre)
{
	const char *d;

	d += Strcspn(dest, npre);
	if (*d != '\0')
		return (char *) d;
	return NULL;
}
char *Strrev(char *dest)
{
	char *p, *q;
	char c;

	p = q = dest;
	for (p += Strlen(p) - 1; p > q; --p, ++q)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
	return dest;
}
char *Strtrim(char *dest)
{
	char *d;

	for (d = dest + Strlen(dest) - 1; d >= dest; --d)
		if (!Isspace(*d))
			break;
	*++d = '\0';
	return dest;
}
char *Strsqz(char *dest, char c)
{
	char *p, *q;

	p = q = dest;
	for ( ; *p != '\0'; ++p)
		if (*p != c)
			*q++ = *p;
	*q = '\0';
	return dest;
}
char *Strdup(char *dest)
{
	char *d;

	d = (char *) malloc(Strlen(dest) + 1);
	if (d != NULL)
		Strcpy(d, dest);
	return d;
}
char *Strtoup(char *dest)
{
	char *d;

	for (d = dest; *d != '\0'; ++d)
		*d = Toupper(*d);
	return dest;
}
char *Strtolow(char *dest)
{
	char *d;

	for (d = dest; *d != '\0'; ++d)
		*d = Tolower(*d);
	return dest;
}
char *Strsqzs(char *dest, const char *s)
{
	for ( ; *s != '\0'; ++s)
		Strsqz(dest, *s);
	return dest;
}


void test_str(void)
{	
	char s[100] = "12345";
	char t[100] = "abcdefg";
	char r[100] = "ABCDEFGHI"; 
	PRN_VAL(s, s);
	PRN_VAL(t, s);
	PRN_VAL(r, s);
	PRN_FUN(Strlen(s), lu);
	PRN_FUN(Strcpy(s, t), s);
	PRN_FUN(Strncpy(s, t, 3), s);
	PRN_FUN(Strcat(s, t), s);
	PRN_FUN(Strncat(s, r, 2), s);
	PRN_FUN(Strsqz(s, 'a'), s);

	char d[100] = "12abc1234567890abc1234abca";
	char e[100] = "abc";
	char *p = d;
	size_t l;
	PRN_STR(----------);
	PRN_VAL(d, s);
	PRN_VAL(e, s);
	PRN_FUN(l = Strlen(e), lu);
	PRN_FUN(Strindex(p, e), lu);
	PRN_FUN(p = Strstr(p, e), s);
	PRN_SEN(p += l);
	PRN_VAL(p, s);
	PRN_FUN(Strindex(p, e), lu);
	PRN_FUN(p = Strstr(p, e), s);
	PRN_SEN(p += l);
	PRN_VAL(p, s);
	PRN_FUN(Strindex(p, e), lu);
	PRN_FUN(p = Strstr(p, e), s);

	char f[100] = "Abde    ";
	char g[100] = " "; 
	PRN_STR(--------);
	PRN_VAL(f, s);
	PRN_VAL(g, s);
	PRN_FUN(Strlen(f), lu);
	PRN_FUN(Strlen(Strtrim(f)), lu);
	PRN_VAL(f, s);
	PRN_FUN(Strlen(Strtrim(g)), lu);
	PRN_FUN(Strlen(""), lu);

	char h[100] = "1234567";
	PRN_STR(-------);
	PRN_VAL(h, s);
	PRN_FUN(Strrev(h), s);
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
	PRN_FUN(Strspn(i, m), lu);
	PRN_FUN(Strcspn(i, n), lu);
	PRN_FUN(Strpbrk(i, m), s);
	PRN_FUN(Strpbrk(i, n), s);

	char as[] = "1234567";
	char bs[] = "abcde";
	char cs[] = "1234567";
	PRN_VAL(as, s);
	PRN_VAL(bs, s);
	PRN_VAL(cs, s);
	PRN_FUN(Strspn(as, bs), lu);
	PRN_FUN(Strspn(as, cs), lu);
	PRN_FUN(Strcspn(as, bs), lu);
}


	
/*
 * Main fucntion
 */

int main(int argc, char *argv[])
{
	test_str();

	return 0;
}




