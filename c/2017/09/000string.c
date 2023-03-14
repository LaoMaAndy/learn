#ifndef TEMP_STRING_C
#define TEMP_STRING_C
#include "000head.c"

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

char *Trim(char *dest)
{
	char *d = dest;

	d += Strlen(dest);
	while (--d >= dest)
		if (!Ispace(*d))
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

char *Strtoup(char *dest)
{
	char *d = dest;
	int c;

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

int Atoi(const char *s)
{
	int val, sign;

	while (Ispace(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	for (val = 0; Isdigit(*s); s++)
		val = val * 10 + (*s - '0');
	return sign * val;
}

double Atof(const char *s)
{
	double val, power;
	int sign;

	while (Ispace(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	for (val = 0.0; Isdigit(*s); s++)
		val = val * 10.0 + (*s - '0');
	if (*s == '.')
		s++;
	for (power = 1.0; Isdigit(*s); s++)
	{
		val = val * 10.0 + (*s - '0');
		power *= 10;
	}
	return sign * val / power;
}

char *Itoa(int n, char *dest)
{
	char *d = dest;
	int sign;

	if ((sign = n) < 0)
		n = -n;
	do
	{
		*d++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		*d++ = '-';
	Reverse(dest);
	return dest;
}

void Printd(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
		Printd(n / 10);
	putchar(n % 10 + '0');
}

unsigned Getbits(unsigned x, int p, int n)
{
	return (x >> (p - n + 1)) & ~(~0 << n);
}

int Getline(FILE *fp, char *dest, int lim)
{
	char *d = dest;
	int c;

	while (--lim > 0 && (c = fgetc(fp)) != EOF && c != '\n')
		*d++ = c;
	if (c == '\n')
		*d++ = c;
	*d = '\0';
	return d - dest;
}

int Getword(FILE *fp, char *word, int lim)
{
	char *w = word;
	int c;

	while (Ispace(c = fgetc(fp)))
		;
	if (c != EOF)
		*w++ = c;
	if (!Isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!Isalnum(*w = fgetc(fp)))
		{
			ungetc(*w, fp);
			break;
		}
	*w = '\0';
	return word[0];
}


#endif
