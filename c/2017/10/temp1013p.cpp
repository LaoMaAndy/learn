/*
function: cpp
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int Stringcmp(string s, string t)
{
	auto cs = s.cbegin(), ct = t.cbegin();
	for ( ; cs != s.cend() && ct != t.cend(); cs++, ct++)
		if (*cs != *ct)
			return *cs - *ct;
	return (cs - s.cend()) - (ct - t.cend());
}
int searchstr(string x, vector<string> text)
{
	auto bp = text.cbegin();
	int low = 0;
	int high = text.cend() - bp;

	while (low < high)
	{
		int mid, r;
		mid = (low + high) / 2;
		r = x.compare(*(bp + mid));
		if (r < 0)
			high = mid;
		else if (r > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
void test_searchstr(void)
{
	vector<string> text{"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii"};
	int i = 0;
	for (auto n : text)
		cout << "[" << i++ << "] " << n << endl;
	vector<string> vx{"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "zz", "11"};
	for (auto x = vx.begin(); x != vx.end(); x++)
	{
		cout << "Searching :" << *x;
		auto r = searchstr(*x, text);
		if (r == -1)
			cout << "...can not find it";
		else
			cout << "\t, position: " << r;
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	test_searchstr();
	return 0;
}


	
