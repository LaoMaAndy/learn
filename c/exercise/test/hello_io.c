/* hello_io.c */
#include <unistd.h>

int main()
{
	int i;
	for (i = 0; i < 10000; ++i)
		write(1, "hello, world\n", 12);
	_exit(0);
}

