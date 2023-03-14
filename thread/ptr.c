/* ptr.c */
#include <iostream>
#include <thread>
using namespace std;

void foo()
{
	cout << "foo is running...\n" << endl;
}

int main()
{
	thread *p = new thread(foo);
	p->join();

	return 0;
}

