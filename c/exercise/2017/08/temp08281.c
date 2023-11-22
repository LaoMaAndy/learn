/*
 * String function prototype
 */
#include <stdio.h>
size_t Strlen(const char *s);
char *Strcpy(char *dest, const char *src);
char *Strcat(char *dest, const char *src);
char *Squeeze(char *dest, int chr);


/*
 * implementation
 */

size_t Strlen(const char *s)
{
	const char *p = s;

	while (*p != '\0')
		p++;
	return p - s;
}

char *Strcpy(char *dest, const char *src)
{
	char *d = dest;
	
	while ((*d++ = *src++) != '\0')
		;
	return dest;
}

char *Strcat(char *dest, const char *src)
{
	char *d = dest;

	while (*d != '\0')
		d++;
	while ((*d++ = *src++) != '\0')
		;
	return dest;
}

char *Squeeze(char *dest, int chr)
{
	char *p1 = dest;
	char *p2 = dest;
	int c;

	do 
		if ((c = *p1++) == chr)
			*p2++ = c;
	while (c != '\0');
	return dest;
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("size of char is: %zd\n", sizeof(char));
	printf("size of short is: %zd\n", sizeof(short));
	printf("size of int is: %zd\n", sizeof(int));
	printf("size of size_t is %zd\n", sizeof(size_t));
	printf("size of long is %zd\n", sizeof(long));
	printf("size of float is %zd\n", sizeof(float));
	printf("size of double is %zd\n", sizeof(double));
	printf("size of long long is %zd\n", sizeof(long long));
	return 0;
}
