/*
function: recurse, mprintf
*/
#define NEED_STRING
#include "0head.c"

void prnint(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10 > 0)
		prnint(n / 10);
	putchar(n % 10 + '0');
}
void prnstr(const char *s, int n)
{
	if (s[n] != '\0')
	{
		putchar(s[n]);
		prnstr(s, n + 1);
	}
}
int fact(int n)
{
	if (n > 1)
		return fact(n - 1) * n;
	return 1;
}
void mprint(const char *fmt, ...)
{
	va_list ap;
	const char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p != '\0'; ++p)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch(*++p)
		{
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval != '\0'; ++sval)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}
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


/* test these function */

void prnbit(unsigned v)
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
	PRN_CAL(prnstr("recursion_test", 0));
	printf("\n");
	PRN_CAL(prnint(123456));
	printf("\n");
	for (int i = 0; i < 10; ++i)
		printf("%d\n", fact(i));
}
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
	test_recursion();
	test_bit();
	return 0;
}
