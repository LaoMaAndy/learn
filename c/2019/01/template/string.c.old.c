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

char *Strstr(const char *dest, const char *sub)
{
	const char *d = dest;
	int i;
	
	for ( ; *d != '\0'; d++)
		if (*d == *sub)
		{
			for (i = 1; d[i] == sub[i] && d[i] != '\0'; i++)
				;
			if (sub[i] == '\0')
				return (char *) d;
		}
	return (char *) 0;
}

int Strindex(const char *dest, const char *sub)
{
	const char *p;

	p = Strstr(dest, sub);
	if (p != 0)
		return p - dest;
	return -1;
}

int Strcmp(const char *s, const char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
extern int Isspace(int i);
char *Trim(char *dest)
{
	char *d = dest;

	d += Strlen(dest);
	while (--d >= dest)
		if (!Isspace(*d))
			break;
	*++d = '\0';
	return dest;
}

char *Reverse(char *dest)
{
	char *p = dest, *q =dest;
	int c;

	for (p += Strlen(dest) - 1; p > q; p--, q++)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
	return dest;
}
