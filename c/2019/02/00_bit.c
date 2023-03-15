/*
function: bit operate
*/
//#include "0head.c"
#include "template/head.h"

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

/* test these function */
void test_bit(void)
{
	unsigned i = 0; unsigned f = 0x1F320; 
	PRN_VAR(i = bit_set(i , 1, 1), d);
	bit_prn(i);
	PRN_VAR(i = bit_set(i , 15, 3), d);
	bit_prn(i);
	PRN_VAR(i = bit_set(i , 4, 2), d);
	bit_prn(i);
	PRN_VAR(i = bit_clr(i, 4, 3), d);
	bit_prn(i);
	PRN_VAR(i = bit_set(i, 16, 1), d);
	bit_prn(i);
	PRN_VAR(i = bit_set(i, sizeof(i) * 8 - 1, 1), d);
	bit_prn(i);
	PRN_VAL(bit_chk(i, 3), d);
	PRN_FUN(bit_get(f, 15, 4), X);
}
int main(int argc, char *argv[])
{
	test_bit();
	return 0;
}
