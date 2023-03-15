void Strcpy(char *dest, char *src)
{
	while (*dest++ = *src++)
		;
}

void Strcpy_1(char *dest, char *src)
{
	char *d = dest;
	char *s = src;

	while (*d++ = *s++)
		;
}
#include <stddef.h>
#include <string.h>

#undef strcpy
char *strcpy_STD (dest, src)
     char *dest;
     const char *src;
{
  char c;
  char *s = (char *) src;
  const ptrdiff_t off = dest - s - 1;

  do
    {
      c = *s++;
      s[off] = c;
    }
  while (c != '\0');

  return dest;
}
