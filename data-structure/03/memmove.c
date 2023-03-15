/* memory move test */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef int dtype;

void my_memcpy(void *dest, void *src, size_t i)
{
	i /= sizeof(long);
	--i;
	for ( ; i != 0; --i)
		*(long *)dest++ = *(long *)src++;
}

void test_mem_move()
{
	size_t size = 2L * 1024L * 1024L * 1024L;
	int loop = 10, i;
	dtype *dest, *src;

	dest = (dtype *) malloc(size * sizeof(dtype));
	src  = (dtype *) malloc(size * sizeof(dtype));

	if (dest == NULL || src == NULL)
	{
		printf("malloc() return NULL\n");
		exit(1);
	}
	printf("malloc() OK, start ....\n");
	for (i = 0; i < loop; ++i)
	{
		my_memcpy(dest, src, size * sizeof(dtype));
		printf("Block: %-5d\n", i + 1);
	}
	printf("\nBlok size: %ld, OK\n", size * sizeof(dtype));
}
int main()
{
	test_mem_move();
	return 0;
}