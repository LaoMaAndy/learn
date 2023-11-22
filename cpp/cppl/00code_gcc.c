char *strcat(char *dest, const char *src)
{
	char *s1 = dest;
	const char *s2 = src;
	char c;

	do
		c = *s1++;
	while (c != '\0');

	s1 -= 2;

	do
	{
		c = *s2++;
		*++s1 = c;
	}
	while (c != '\0');

	return dest;
}

int strcmp(const char *p1, const char *p2)
{
	const unsigned char *s1 = (const unsigned char *) p1;
	const unsigned char *s2 = (const unsigned char *) p2;
	unsigned char c1, c2;

	do
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 == '\0')
			return c1 - c2
	}
	while (c1 == c2);
	return c1 - c2;
}

char *strcpy(char *dest, const char *src)
{
	char c;
	char *s = (char *) src;
	const ptrdiff_t off = dest - s - 1;

	do 
	{
		c = *s ++;
		s[off] = c;
	}
	while (c != '\0');
	return dest;
}

size_t strcspn(const char *s, const char *reject)
{
	  size_t count = 0;

	    while (*s != '\0')
		    if (strchr (reject, *s++) == NULL)
			      ++count;
			else
				 return count;

	r count;
}
