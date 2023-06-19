/* max int */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void asc()
{
	printf("A: %d, %o\n", 'A', 'A');
	printf("a: %d, %o\n", 'a', 'a');
}
void test()
{
	int i, j;
	int mid1, mid2;

	i = INT_MAX - 3;
	j = INT_MAX - 1;
	mid1 = (i + j) / 2;
	mid2 = i + (j - i) / 2;

	printf("max_int: %d, mid1: %d, mid2: %d\n", INT_MAX, mid1, mid2);
}
int main()
{
	asc();
	test();
	return 0;
}

