#include "../dsaa.h"

long fib(int n)
{
	 long r = 0, s = 0, t = 1;

	for ( ; n > 0; --n)
	{
		r = s + t;
		s = t;
		t = r;
	}
	return r;
}
long fib2(int n)
{
	if (n < 2)
		return 1;
	else
		return fib2(n - 1) + fib2(n - 2);
}
void test_fib()
{
	int i;

	for (i = 0; i < 100; ++i)
		printf("Fibonacci %3d: %ld\n", i, fib(i));
}
void test_fib2()
{
	int i = 55;
	long r;

	printf("recursive for Fibonacci: %d\n", i);
	r = fib2(i);
    printf("Result: %ld\n", r);	
}
int main()
{
	//test_fib();
	test_fib2();
	return 1;
}
