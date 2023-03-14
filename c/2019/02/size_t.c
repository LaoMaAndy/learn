/* length of size_t and length of int */
#include <stdio.h>

int main()
{
	size_t i;
	int n;

	printf("size_t is: %ld\n", sizeof(i));
	printf("int    is: %ld\n", sizeof(n));
	return 0;
}

