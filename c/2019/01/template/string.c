/* string */
#include "head.h"

/*
size_t Strlen(const char *s)
{
	const char *p;

	for (p = s; *s != '\0'; ++s)
		;
	return s - p;
}
*/
size_t Strlen(const char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}

/*
char *Strcpy(char *dest, const char *src)
{
	char *p = dest;

	while ((*dest++ = *src++) != '\0')
		;
	return p;
}
*/
char *Strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return dest;
}
/*
char *Strncpy(char *dest, const char *src, size_t n)
{
	char *p = dest;
	char c;

	for ( ; n != 0; --n)
	{
		if ((c = *src++) == '\0')
			break;
		*dest++ = c;
	}
	for ( ; n != 0; --n)
		*dest++ = '\0';
	return p;
}
*/

char *Strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; ++i)
		dest[i] = src[i];
	for ( ; i < n; ++i)
		dest[i] = '\0';
}


/*
char *Strcat(char *dest, const char *src)
{
	char *p = dest;

	dest += Strlen(dest);
	Strcpy(dest, src);
	return p;
}
*/

char *Strcat(char *dest, const char *src)
{
	size_t dest_len = Strlen(dest);
	size_t i;
	char c;

	for (i = 0; (c = src[i]) != '\0'; ++i)
		dest[dest_len + i] = c;
	dest[dest_len + i] = '\0';
	return dest;
}


/*
char *Strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = Strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; ++i)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return dest;
}
*/
char *Strncat(char *dest, const char *src, size_t n)
{
	char *d = dest;

	d += Strlen(d);
	for ( ; n != 0; --n)
		if ((*d++ = *src++) == '\0')
			break;
	*d = '\0';
	return dest;
}

/*
int Strcmp(const char *s, const char *t)
{
	for ( ; *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
*/
int Strcmp(const char *s, const char *t)
{
	size_t i;

	for (i = 0; s[i] == t[i]; ++i)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}


/*
int Strncmp(const char *s, const char *t, size_t n)
{
	for ( ; n > 1 && *s == *t; ++s, ++t, --n)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
*/
int Strncmp(const char *s, const char *t, size_t n)
{
	size_t i;

	if (n == 0)
		return 0;
	for (i = 0; i < n - 1 && s[i] == t[i]; ++i)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}


/*
char *Strstr(const char *dest, const char *sub)
{
	char s, d;
	size_t n = Strlen(sub);

	for (s = *sub; (d = *dest) != '\0'; ++dest)
		if (d == s)
			if (Strncmp(dest, sub, n) == 0)
				return (char *) dest;
	return NULL;
}
*/
char *Strstr(const char *dest, const char *sub)
{
	size_t i;
	size_t n = Strlen(sub);
	char c;
	char d = *sub;

	for (i = 0; (c = dest[i]) != '\0'; ++i)
	   if (c == d)
			if (Strncmp(dest + i, sub, n) == 0)
				return (char *)(dest + i);
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


char *Strchr(const char *dest, char chr)
{
	char c;

	for ( ; (c = *dest) != '\0'; ++dest)
		if (c == chr)
			return (char *) dest;
	return NULL;
}
/*
char *Strchr(const char *dest, char chr)
{
	size_t i;

	for (i = 0; dest[i] != '\0'; ++i)
		if (dest[i] == chr)
			return (char *) dest + i;
	return NULL;
}
*/

char *Strrchr(const char *dest, char chr)
{
	const char *p = dest;

	dest += Strlen(dest);
	for (--dest; dest >= p; --dest)
		if (*dest == chr)
			return (char *)dest;
	return NULL;
}

/* error: 
char *Strrchr(const char *dest, char chr)
{
	size_t i;

	for (i = Strlen(dest) - 1; i >= 0; --i)  //error, i's type is size_t
		if (dest[i] == chr)
			return dest + i;
	return NULL;
}
*/
/*
size_t Strspn(const char *dest, const char *pre)
{
	const char *p = dest;
	char c;

	for ( ; (c = *dest) != '\0'; ++dest)
		if (Strchr(pre, c) == NULL)
			break;
	return dest - p;
} 
*/
size_t Strspn(const char *dest, const char *pre)
{
	size_t i;

	for (i = 0; dest[i] != '\0'; ++i)
		if (Strchr(pre, dest[i]) == NULL)
			break;
	return i;
}


/*
size_t Strcspn(const char *dest, const char *npre)
{
	const char *p = dest;
	char c;

	for ( ; (c = *dest) != '\0'; ++dest)
		if (Strchr(npre, c) != NULL)
			break;
	return dest - p;
}
*/
size_t Strcspn(const char *dest, const char *npre)
{
	size_t i;

	for (i = 0; dest[i] != '\0'; ++i)
		if (Strchr(npre, dest[i]) != NULL)
			break;
	return i;
}

char *Strpbrk(const char *dest, const char *npre)
{
	dest += Strcspn(dest, npre);
	if (*dest != '\0')
		return (char *) dest;
	return NULL;
}

char *Strrev(char *s)
{
	char *p, *q;
	char c;

	p = q = s;
	s += Strlen(s);
	for (--s; s > p; ++p, --s)
	{
		c = *s;
		*s = *p;
		*p = c;
	}
	return q;
}

// Remove leading and  trailling blank 

char *Strtrim(char *dest)
{
	char *p, *q, *r;

	q = dest + Strlen(dest);
	for (--q; q >= dest; --q)
		if (!Isspace(*q))
			break;
	*++q = '\0';
	for (p = dest; p < q; ++p)
		if (!Isspace(*p))
			break;
	if (p != dest)
		for (r = dest; p <= q; ++p, ++r)
			*r = *p;
	return dest;
}
/* error
char *Strtrim(char *dest)
{
	size_t i, j, k;

	j = Strlen(dest);
	if (j == 0) 
		return dest;
	for (i = 0; dest[i] != '\0'; ++i)  
		if (!Isspace(dest[i]))
			break;
	for (--j; j >= 0; --j)   	//Bug: j's type is size_t, which is unsigned, so j >= 0 is true forever
		if (!Isspace(dest[j]))
			break;
	dest[++j] = '\0';
	if (i != 0)
		for (k = i; i <= j; ++i)
			dest[i - k] = dest[i];
} 
*/
/*
char *Strsqz(char *dest, char chr)
{
	char *p, *q;
	char c;

	for (p = q = dest; (c = *dest) != '\0'; ++dest)
		if (c != chr)
			*p++ = c;
	*p = '\0';
	return q;
}
*/
char *Strsqz(char *dest, char chr)
{
	size_t i, j;

	for (i = 0, j = 0; dest[i] != '\0'; ++i)
		if (dest[i] != chr)
			dest[j++] = dest[i];
	dest[j] = '\0';
	return dest;
}

/*
char *Strsqzs(char *dest, const char *s)
{
	for ( ; *s != '\0'; ++s)
		Strsqz(dest, *s);
	return dest;
}
*/
char *Strsqzs(char *dest, const char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; ++i)
		Strsqz(dest, s[i]);
	return dest;
}

char *Strdup(const char *dest)
{
	char *p;
	size_t i;

	i = Strlen(dest) + 1;
	p = (char *) malloc(i);
	if (p != NULL)
		Strcpy(p, dest);
	return p;
}

/*
char *Strtoup(char *dest)
{
	char c;
	char *p = dest;

	for ( ; (c = *dest) != '\0'; ++dest)
		*dest = Toupper(c);
	return p;
}
*/
char *Strtoup(char *dest)
{
	size_t i;
	char c;

	for (i = 0; (c = dest[i]) != '\0'; ++i)
		dest[i] = Toupper(c);
	return dest;
}
/*
char *Strtolow(char *dest)
{
	char *p = dest;
	char c;

	for ( ; (c = *dest) != '\0'; ++dest)
		*dest = Tolower(c);
	return p;
}
*/
char *Strtolow(char *dest)
{
	size_t i;
	char c;

	for (i = 0; (c = dest[i]) != '\0'; ++i)
		dest[i] = Tolower(c);
	return dest;
}

