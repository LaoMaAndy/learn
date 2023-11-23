#include <stdio.h>

int main(void)
{
	unsigned char c;
	unsigned char h = 0x80;
	unsigned char l = 0x01;
	int r;

	for (c = 0; c < 0xff; c++)
	{
		r = (c - l) & ~c & h;
		printf("%3X : %d\n", c, r);
	} 
	printf("ff is %d\n", 0xff);
	return 0;
}
