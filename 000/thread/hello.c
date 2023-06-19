/* hello.c */
#include <iostream>
#include <thread>

void hello()
{
	std::cout << "hello, thread world" << std::endl;
}

std::thread fo() {
	std::thread t(hello);
	std::thread s = std::move(t);
	return s;
}


int main() {
	std::thread t(hello);
	t.detach();

	return 0;
}

