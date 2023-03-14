/*
function: string function, search
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int stringlen(const string dest)
{
	return dest.cend() - dest.cbegin();
}
string &stringcpy(string &dest, const string src)
{
	auto cs = src.cbegin();
	auto cd = dest.begin();
	while (cs != src.cend())
	{
		*cd = *cs;
		++cd;
		++cd;
	}
	return dest;
}
string &stringcat(string &dest, const string src)
{
	auto cs = src.cbegin();
	while (cs != src.cend())
	{
		dest.push_back(*cs);
		++cs;
	}
	return dest;
}
int stringcmp(const string s, const string t)
{
	auto cs = s.cbegin(), ct = t.cbegin();
	for ( ; cs != s.cend() && ct != t.cend(); ++cs, ++ct)
		if (*cs != *ct)
			return *cs - *ct;
	return (s.cend() - cs) - (t.cend() - ct);
}
int stringsch(const string x, const vector<string> vs)
{
	auto base = vs.cbegin();
	int low = 0;
	int high = vs.size();
	while (low < high)
	{
		int mid = (low + high) / 2;
		int r = x.compare(*(base + mid));
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
void test_string(void)
{
	string a("123456");
	string b("abcdefgh");
	string c("ABCEDFGH");
	cout << "Test string function : " << endl;
	cout << "string a: " << a << endl;
	cout << "\t length: " << stringlen(a) << endl;
	cout << "empty string: " << endl;
	cout << "\t length: " << stringlen(string("")) << endl;
	cout << "a: " << a << " b: " << b << endl;
	cout << "\t string cat: " << stringcat(a, b) << endl;
}
void test_stringcmp(void)
{
	string s("aaa"), t("aaab");
	cout << "compare : " << s << " - " << t << " : " << (stringcmp(s, t)) << endl;
	vector<string> vs{
						"this", 
						"thisabcde", 
						"that", 
						"thit", 
						"thi", 
						"thja", 
						"this", 
						"", 
						"u", 
						"t"
					};
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
	test_string();
	test_stringcmp();
	test_stringsch();
	return 0;
}


