/* hardware_concurrency() */
#include <thread>
#include <iostream>
using namespace std;

int main()
{
	int n = std::thread::hardware_concurrency();

	printf("hardware_concurrency: %d\n", n);
	return 0;
}
