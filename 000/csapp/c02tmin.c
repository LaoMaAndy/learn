#include <stdio.h>
#include <limits.h>

#define TM (-0x7FFFFFFF-1)

int main(int argc, char *argv[])
{
	int dpos32 = (2147483648 > 0);
	int hpos32 = (0x80000000 > 0);

	int dtmin32 = -2147483648;
	int dpos32a = (dtmin32 > 0);
	int htmin32 = 0x80000000;
	int hpos32a = (htmin32 > 0);

	int a = (-2147483647-1 == 2147483648U);

	printf("dpos32 is %d\n", dpos32);
	printf("hpos32 is %d\n", hpos32);
	printf("dpos32a is %d\n", dpos32a);
	printf("hpos32a is %d\n", hpos32a);
	printf("TM is %d\n", TM);
	printf("a is %d\n", a);

	return 0;
}

