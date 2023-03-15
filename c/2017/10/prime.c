/*
 function: prime
 */
#include <stdio.h>
#include <math.h>

int isprime(long n)
{
	long i;
	long m;
	if (n < 6)
		return 0;
	m = (long) sqrt((double)n);

	//printf("number: %ld, sqrt: %ld\n", n, m);
	for (i = 2; i <= m; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

void test(void)
{
	long n;
	int i = 0;

	for (n = 6; n < 1234567; n++)
		if (isprime(n))
			printf("%9ld%c", n, (i++ % 15 == 14) ? '\n' : ' ');
	printf("\ntest OK.\n");
}

int main(void)
{
	test();
	return 0;
}

