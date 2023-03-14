/* hello, thread */
#include <iostream>
#include <thread>
using namespace std;

void foo()
{
	printf("hello, world\n");
}

int main()
{
	thread t1(foo), t2(foo);
	cout << "t1 id: " << t1.get_id() << endl;
	cout << "t2 id: " << t2.get_id() << endl;
	t1.join();
	t2.join();

	return 0;
}
