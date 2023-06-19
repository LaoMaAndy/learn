#include <stdio.h>

unsigned int s4(unsigned int i)
{
	return i & 0xff;
}

unsigned int s4or(unsigned int i)
{
	return i ^ ~0xff;
}

unsigned s4a1(unsigned int i)
{
	return i | 0xff;
}

#define ABC 0x87654321
int main(int argc, char *argv[])
{
	printf("%08x,  s4 is: %08x\n",ABC, s4(ABC));
	printf("%08x,  s4or is: %08x\n",ABC, s4or(ABC));
	printf("%08x,  s4a1 is: %08x\n",ABC, s4a1(ABC));

	return 0;
}
