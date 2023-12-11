/* c to f */
#include <stdio.h>

void ctof()
{
	double c, f;

	printf("Input C degree: ");
	scanf("%lf", &c);
	f = 32.0 + c * 1.8;
	printf("%5.1fC is %5.1fF\n",c, f);
}

int main()
{
	ctof();
	return 0;
}

