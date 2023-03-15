#include <stdio.h>

int main(void)
{
	char s[] = "string";
	int i[sizeof(s)];

	printf("sizeof s is %ld\n",sizeof(s));

	return 0;
}
