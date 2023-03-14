/*
	class: stringx. a class seems like string, but it is a count version. 
*/
#include "kstring.h"
/* these function implementation */

void Strinfo(const char *dest, size_t len)
{
	const char *p = dest; 
	int i;

	printf("[String information]\n");
	printf("Char:\n\t");
	for (i = 0; i < len; ++i)
	{
		if (*p == '\0')
			printf("  ");
		else
			printf("%2c", *p);
		++p;
		if (i % 16 == 15)
			printf("\n\t");
		else if (i % 8 == 7)
			printf(" - ");
		else
			printf(" ");
	}
	p = dest;
	printf("\nASCII:\n\t");
	for (i = 0; i < len; ++i)
	{
		unsigned char v = *p++;
		printf("%2X", v);
		if (i % 16 == 15)
			printf("\n\t");
		else if (i % 8 == 7)
			printf(" - ");
		else
			printf(" ");
	}
	printf("\n");
}
void Strxprn(const char *dest, size_t len)
{
	size_t i;

	for (i = 0; i < len; ++i)
		putchar(dest[i]);
}
size_t Strlen(const char *dest)
{
	const char *d = dest;

	while (*dest != '\0')
		++dest;
	return dest - d;
}
char *Strcpy(char *dest, const char *src)
{
	char *s = (char *) src;
	const ptrdiff_t diff = dest - s - 1;
	char c;

	do{
		c = *s++;
	   s[diff] = c;
	} while (c != '\0');
	return dest;	
}
char *Strncpy(char *dest, const char *src, size_t n)
{
	char c;
	char *d = dest;

	for ( ; n != 0; --n)
	{
		c = *src++;
		if (c == '\0')
			break;
		*dest++ = c;
	}
	for ( ; n != 0; --n)
		*dest++ = '\0';
	return d;
}
char *Strxcpy(char *dest, const char *src, size_t n)
{
	for ( ; n > 0; --n)
		dest[n] = src[n];
	return dest;
}
char *Strcat(char *dest, const char *src)
{
	char *d = dest;

	dest += Strlen(dest);
	Strcpy(dest, src);
	return d;
}
char *Strncat(char *dest, const char *src, size_t n)
{
	char *d = dest;

	dest += Strlen(dest);
	while (n-- != 0)
		if ((*dest++ = *src++) == '\0')
			return d;
	*dest = '\0';
	return d;
}
char *Strxcat(char *dest, size_t ds, const char *src, size_t n)
{
	char *d = dest;
	
	dest += ds;
	while (n-- != 0)
		*dest++ = *src++;
	return d;
}
int Strcmp(const char *s, const char *t)
{
	for ( ; *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
int Strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char c1 = '\0';
	unsigned char c2 = '\0';

	while (n-- > 0)
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 == '\0' || c1 != c2)
			return c1 - c2;
	}
	return c1 - c2;
}
int Strxcmp(const char *s, size_t ss, const char *t, size_t ts)
{
	unsigned char c1 = '\0';
	unsigned char c2 = '\0';
	unsigned char *p1 = (unsigned char *) s;
	unsigned char *p2 = (unsigned char *) t;
	size_t i = 0;

	while (i != ts)
	{
		c1 = p1[i];
		c2 = p2[i];
		if (i == ss)
			return 0 - c2;
		if (c1 != c2)
			return c1 - c2;
		++i;
	}
	return c1 - c2;
}
char *Strstr(const char *dest, const char *sub)
{
	const unsigned char *dp = (const unsigned char *) dest;
	const unsigned char *sp = (const unsigned char *) sub;
	const unsigned char *s, *d;
	unsigned char a = (unsigned char) *sub;
	unsigned char b;

	for ( ; (b = *dp) != '\0'; ++dp)
		if (b == a)
		{
			s = sp + 1;
			d = dp + 1;
			for ( ; *s == *d && *d != '\0'; ++s, ++d)
				;
			if (*s == '\0')
				return (char *) dp;
		}
	return NULL;
}
char *Strxstr(const char *dest, size_t ds, const char *sub, size_t ss)
{
	const unsigned char *dp = (const unsigned char *) dest;
	const unsigned char *sp = (const unsigned char *) sub;
	const unsigned char *s, *d;
	unsigned char a = (unsigned char) *sub;
	size_t i, j;

	for (i = 0, ds -= ss; i < ds; ++i)
		if (dp[i] == a)
		{
			s = sp;
			d = dp + i;
			for (j = 1; s[j] == d[j] && j < ss; ++j)
				;
			if (j == ss)
				return (char *) (dp + i);
		}
	return NULL;
}
size_t Strindex(const char *dest, const char *sub)
{
	const char *p;

	p = Strstr(dest, sub);
	if (p != NULL)
		return p - dest;
	return -1;
}
size_t Strxindex(const char *dest, size_t ds, const char *sub, size_t ss)
{
	const char *p;

	p = Strxstr(dest, ds, sub, ss);
	if (p != NULL)
		return p - dest;
	return -1;
}
char *Strchr(const char *dest, int c)
{
	const char *d = dest;

	for ( ; *dest != '\0'; ++dest)
		if (*dest == c)
			return (char *) dest;
	return NULL;
}
char *Strxchr(const char *dest, size_t ds, int c)
{
	const char *d = dest;
	size_t i;

	for (i = 0; i < ds; ++i)
	   if (d[i] == c)
	   return (char *)(d + i);
	return NULL;
}	

char *Strrchr(const char *dest, int c)
{
	const unsigned char *d = (const unsigned char *) dest;
	unsigned char a;

	d += Strlen((const char*) d);
	while (--d >= (const unsigned char *) dest)
		if (*d == c)
			return (char *) d;
	return NULL;
}

char *Strxrchr(const char *dest, size_t ds, int c)
{
	const char *d = dest + ds;
	while (d >= dest)
	{
		if (*d == c)
			return (char *) d;
		--d;
	}
	return NULL;
}

size_t Strspn(const char *dest, const char *pre)
{
	const char *d = dest;
	for ( ; *dest != '\0'; ++dest)
		if (Strchr(pre, *dest) == NULL)
			break;
	return dest - d;
}
size_t Strxspn(const char *dest, size_t ds, const char *pre, size_t ps)
{
	size_t i;
	for (i = 0; i < ds; ++i)
	   if (Strxchr(pre, ps, dest[i]) == NULL)
			break;
	return i;	
}

size_t Strcspn(const char *dest, const char *pre)
{
	const char *d = dest;
	for ( ; *dest != '\0'; ++dest)
		if (Strchr(pre, *dest) != NULL)
			break;
	return dest - d;
}
size_t Strxcspn(const char *dest, size_t ds, const char *npre, size_t ns)
{
	size_t i;

	for (i = 0; i < ds; ++i)
		if(Strxchr(npre, ns, dest[i]) != NULL)
			break;
	return i;
}
char *Strpbrk(const char *dest, const char *npre)
{
	const char *p;

	dest += Strcspn(dest, npre);
	if (*dest != '\0')
		return (char *) dest;
	return NULL;
}
char *Strxpbrk(const char *dest, size_t ds, const char *npre, size_t ns)
{
	size_t i;

	if ((i = Strxcspn(dest, ds, npre, ns)) < ds)
		return (char *) (dest + i);
	return (char *) dest;
}
char *Strsqz(char *dest, int chr)
{
	char *p, *q;
	p = q = dest;

	for ( ; *p != '\0'; ++p)
		if (*p != chr)
			*q++ = *p;
	*q = '\0';
	return dest;
}
size_t Strxsqz(char *dest, size_t ds, int chr)
{
	size_t i;
	char *d = dest;
	char c;

	for (i = 0; i < ds; ++i)
		if ((c = dest[i]) != chr)
			*d++ = c;
	return d - dest;
}
char *Strtrim(char *dest)
{
	char *d = dest;

	d += Strlen(d) - 1;
	for ( ; d >= dest; --d)
		if (!isspace(*d))
			break;
	*++d = '\0';
	return dest;
}
size_t Strxtrim(char *dest, size_t ds)
{
	char *d = dest;

	d += ds - 1;
	for ( ; d >= dest; --d)
		if (!isspace(*d))
			break;
	return d - dest;
}
char *Strrev(char *dest)
{
	char *p, *q;
	char c;

	p = q = dest;
	p += Strlen(p) - 1;
	for ( ; p > q; --p, ++q)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
	return dest;
}
char *Strxrev(char *dest, size_t ds)
{
	char *d1, *d2;
	char c;
	d1 = d2 = dest;

	for (d1 += ds; d1 > d2; --d1, ++d2)
	{
		c = *d1;
		*d1 = *d2;
		*d2 = c;
	}
	return dest;
}

char *Strdup(const char *dest)
{
	char *p = (char *) malloc(Strlen(dest) + 1);
	
	if (p != NULL)
		Strcpy(p, dest);
	return (char *) p;
}
char *Strxdup(const char *dest, size_t ds)
{
	char *p = (char *) malloc(ds);

	if (p != NULL)
		Strxcpy(p, dest, ds);
	return p;
}
char *Strtoup(char *dest)
{
	char *d = dest;

	for ( ; *d != '\0'; ++d)
		*d = toupper(*d);
	return dest;
}
char *Strxtoup(char *dest, size_t ds)
{
	size_t i;

	for (i = 0; i < ds; ++i)
		dest[i] = toupper(dest[i]);
	return dest;
}
char *Strtolow(char *dest)
{
	char *d = dest;

	for ( ; *d != '\0'; ++d)
		*d = tolower(*d);
	return dest;
}
char *Strxtolow(char *dest, size_t ds)
{
	size_t i;

	for (i = 0; i < ds; ++i)
		dest[i] = tolower(dest[i]);
	return dest;
}

char *Strsqzs(char *dest, char *sq)
{
	char *d = dest;

	for ( ; *sq != '\0'; ++sq)
		Strsqz(dest, *sq);
	return d;
}
char *Strxsqzs(char *dest, size_t ds, char *sq, size_t ss)
{
	char *d = dest;
	size_t i;

	for (i = 0; i < ss; ++i)
		Strxsqz(dest, ds, sq[i]);
	return dest;
}

