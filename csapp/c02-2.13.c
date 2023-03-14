#include <stdio.h>

int bis(int x, int m)
{
	return x | (1 << m);
}

int bic(int x, int m)
{
	return x & ~(1 << m);
}

int bool_or(int x, int y)
{
	size_t n;
	int mask;
	int result = 0;

	for (n = sizeof(int) * 8 - 1; n != 0; n--)
	{
		mask = 1 << (n - 1);
		result |= ((x & mask) | (y & mask));
	}
	return result;
}

int bool_and(int x, int y)
{
	size_t n;
	int mask;
	int result = 0;

	for (n = sizeof(int) * 8; n != 0; n--)
	{
		mask = 1 << (n - 1);
		result |= ((x & mask) & (y & mask));
	}
	return result;
}

int main(int argc, char *argv[])
{
	unsigned int a , b;

	a = 0x10;
	b = 0x02;
	printf("bis(%08x, 4) is %08x\n", a, bis(a, 3));
	printf("bic(%08x, 5) is %08x\n", a, bic(a, 4));
	printf("sizeof(int) is %zd\n", sizeof(int));
	printf("%08x OR  %08x is: %08x\n", a, b, bool_or(a, b));
	printf("%08x AND %08x is: %08x\n", a, b, bool_and(a, b));


	return 0;
}
