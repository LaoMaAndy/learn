#include <iostream>
#include <string>
#include <vector>
using namespace std;
int stringcmp(string s, string t)
{
	auto sc = s.cbegin(), tc = t.cbegin();
	for ( ; sc != s.cend() && tc != t.cend(); sc++, tc++)
		if (*sc != *tc)
			return *sc - *tc;
	return (s.cend() - sc) - (t.cend() - tc);
}
int stringsch(const string x, const vector<string> v)
{
	auto bp = v.cbegin();
	int low = 0;
	int high = v.cend() - v.cbegin();
	while (low < high)
	{
		int mid = (low + high) / 2;
		int r = x.compare(bp[mid]);
		if (r < 0)
			high = mid;
		else if (r > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
/*test these function */
void test_stringcmp(void)
{
	string s("aaa"), t("aaab");
	cout << "compare : " << s << " - " << t << " : " << (stringcmp(s, t)) << endl;
	vector<string> vs{"this", "thisabcde", "that", "thit", "thi", "thja", "this", "", "u", "t"};
	for (auto i = vs.cbegin(); i != vs.cend(); ++i)
	{
		int r = stringcmp(vs[0], *i);
		cout << "compare result: " << r << " :\t"  << vs[0] << " - " << *i << endl;
	}
	cout << "sizeof('this') is: " << sizeof("this") << endl;
}
void test_stringsch(void)
{
	vector<string> text{"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii"};
	int i = 0;
	for (auto n : text)
		cout << "[" << i++ << "] " << n << endl;
	vector<string> vx{"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "zz", "11"};
	for (auto x = vx.begin(); x != vx.end(); x++)
	{
		cout << "Searching :" << *x;
		auto r = stringsch(*x, text);
		if (r == -1)
			cout << "...can not find it";
		else
			cout << "\t, position: " << r;
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	test_stringcmp();
	test_stringsch();
	return 0;
}


