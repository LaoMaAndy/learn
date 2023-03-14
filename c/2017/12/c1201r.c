/*
function: revcurse, bit_operation
*/
#define NEED_STRING
#include "0head.c"

void intprn(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10 > 0)
		intprn(n / 10);
	putchar(n % 10 + '0');
}
void strprn(const char *s, int i)
{
	if (s[i] != '\0')
	{
		putchar(s[i]);
		strprn(s, i + 1);
	}
}
int fact(int n)
{
	if (n > 1)
		return fact(n - 1) * n;
	return 1;
}
unsigned bitset(unsigned v, int n)
{
	return v | (1u << n);
}
unsigned bitclr(unsigned v, int n)
{
	return v & ~(1u << n);
}
int bitchk(unsigned v, int n)
{
	return v & ~(1u << n) == 0 ? 0 : 1;
}
unsigned getbits(unsigned v , int p , int n)
{
	return (v >> (p + 1 - n)) & ~(~0 << n);
}

/* test these function */

void bitprn(unsigned v)
{
	unsigned m = ~(~0U >> 1);
	for (int n = 0; n < sizeof(v) * 8; ++n, m >>= 1)
	{
		printf("%c", (v & m) == 0 ? '0' : '1');
		printf("%s", (n % 8 == 0 && n != 0) ? " - " : " ");
	}
	printf("\n");
}
void test_recursion(void)
{
	PRN_CAL(strprn("recursion_test", 0));
	printf("\n");
	PRN_CAL(intprn(123456));
	printf("\n");
	for (int i = 0; i < 10; ++i)
		printf("%d\n", fact(i));
}
void test_bit(void)
{
	unsigned i = 0; unsigned f = 0x1F320; 
	PRN_VAR(i = bitset(i , 3), d);
	PRN_CAL(bitprn(i));
	PRN_VAR(i = bitset(i , 4), d);
	PRN_CAL(bitprn(i));
	PRN_VAR(i = bitclr(i, 4), d);
	PRN_VAR(i = bitset(i, 0), d);
	PRN_CAL(bitprn(i));
	PRN_VAR(i = bitset(i, sizeof(i) * 8 - 1), d);
	PRN_CAL(bitprn(i));
	PRN_VAL(bitchk(i, 3), d);
	PRN_FUN(getbits(f, 15, 4), X);
}
int main(int argc, char *argv[])
{
	test_recursion();
	test_bit();
	return 0;
}
