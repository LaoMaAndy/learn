#include <stdio.h>

int main(void)
{
	int i;
	int j;

	printf("sizeof int is: %zd\n", sizeof(int));
	j = (unsigned int)~0 >> 1;
	printf("%10d : j's value\n", j);
	i = 200 * 300 * 400 * 500;
	printf("%10d = 200*300*400*500\n",i);
	j = 0x19000;
	printf("0x19000 is %d\n", j);
	return 0;
}
