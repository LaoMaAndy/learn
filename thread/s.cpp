/* s.cpp */
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void foo(int n)
{
	cout << "foo: " << n << " is running..." << endl;
}
void fa()
{
	vector<thread> ts;
	for (int i = 0; i < 10; ++i)
		ts.push_back(thread(foo, i));
	for (auto & i : ts)
		i.join();
}
void fb()
{
	vector<int> vi;
	for (int i = 0; i < 10; ++i)
		vi.push_back(i);
	for (const auto& i : vi)
		cout << i;
}
int main()
{
	fa();
	return 0;
}
