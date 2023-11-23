/* hello2.c */
#include <unistd.h>

void hello()
{
	char s[] = "hello, world\n";
	int i = sizeof(s) - 1;

	write(STDOUT_FILENO, s, i);
}

int main()
{
	hello();
	_exit(0);
}



