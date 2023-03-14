/* detach.c */
#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdlib.h>

void foo()
{
	for (int i = 0; i < 100; ++i)
		write(1, "hello, world\n", 13);
}
void fa()
{
	std::cout << "c++ output << " << std::endl;
}
int main()
{
	std::thread t(foo);
	t.detach();
	return 0;
}

