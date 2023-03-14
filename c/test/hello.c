/* hello.c  */
#include <unistd.h>

void test()
{
	write(1, "hello, world\n", 13);
	_exit(0);
}
int main()
{
	test();
	return 0;
}

