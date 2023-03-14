/* ip.c */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 20;
	int i, *ip;

	ip = (int *) malloc(n * sizeof(int));
	if (ip == NULL)
	{
		printf("malloc() return NULL\n");
		return 0;
	}
	printf("ip: %p\n", ip);
	for (i = 0; i < n; ++i)
	{
		*ip++ = i;
	}
	printf("ip: %p\n", ip);
	ip -= n;
	printf("ip: %p\n", ip);
	for (i = 0; i < n; ++i)
		printf("%3d  ", *ip++);
	printf("\n");
	return 0;
}
