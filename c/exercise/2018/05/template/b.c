/*
function: bit operate
*/
#include "0head.c"

unsigned setbits(unsigned v, int p, int n)
{
	return v | (~(~0u << n) << (p - n + 1));
}
unsigned clrbits(unsigned v, int p, int n)
{
	return v & ~(~(~0u << n) << (p - n + 1));
}
int chkbit(unsigned v, int n)
{
	return (v & ~(1u << n)) == 0 ? 0 : 1;
}
unsigned getbits(unsigned v, int p, int n)
{
	return (v >> (p + 1 - n)) & ~(~0u << n);
}
void prnbit(unsigned v)
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
	PRN_VAR(i = setbits(i , 1, 1), d);
	prnbit(i);
	PRN_VAR(i = setbits(i , 15, 3), d);
	prnbit(i);
	PRN_VAR(i = setbits(i , 4, 2), d);
	prnbit(i);
	PRN_VAR(i = clrbits(i, 4, 3), d);
	prnbit(i);
	PRN_VAR(i = setbits(i, 16, 1), d);
	prnbit(i);
	PRN_VAR(i = setbits(i, sizeof(i) * 8 - 1, 1), d);
	prnbit(i);
	PRN_VAL(chkbit(i, 3), d);
	PRN_FUN(getbits(f, 15, 4), X);
}
int main(int argc, char *argv[])
{
	test_bit();
	return 0;
}
