/*
function: bit operate
*/
#include <stdio.h>

unsigned bit_set(unsigned v, int p, int n)
{
	return v | (~(~0u << n) << (p - n + 1));
}
unsigned bit_clr(unsigned v, int p, int n)
{
	return v & ~(~(~0u << n) << (p - n + 1));
}
int bit_chk(unsigned v, int n)
{
	return (v & ~(1u << n)) == 0 ? 0 : 1;
}
unsigned bit_get(unsigned v, int p, int n)
{
	return (v >> (p + 1 - n)) & ~(~0u << n);
}
void bit_prn(unsigned v)
{
	unsigned m = ~(~0U >> 1);
	for (int n = 0; n < sizeof(v) * 8; ++n, m >>= 1)
	{
		printf("%c", (v & m) == 0 ? '0' : '1');
		printf("%s", (n % 8 == 7 ) ? "   " : " ");
	}
	printf("\n");
}

