/*
function: stringcmp, stringvec, stringsch, vsswap, vsqksort, vssort
*/
#include "0head.cpp"
int stringcmp(const string &s, const string &t)
{
	string::size_type i = 0;
	decltype(string[0]) cs, ct;
	do
	{
		if (i == s.size() || i == t.size())
			break;
		cs = s[i];
		ct = t[i];
		++i;
	} while (cs == ct);
	if (i == s.size())
		cs = 0;
	if (i == t.size())
		ct = 0;
	return cs - ct;
}
int stringsch(const string &s, const vector<string> &v)
{
	size_t high = v.size(), low;
	while (low < high)
	{
		auto mid = (low + high) / 2;
		auto r = s.compare(v[mid]);
		if (r < 0)
			high = mid;
		else if (r > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
size_t stringvec(const string &s, vector<string> &v)
{
	size_t count = 0;
	bool inword = false;
	decltype(v.end()) t;
	for (auto c : s)
		if (!isalnum(c))
			inword = false;
		else
		{
			if (inword == false)
			{
				v.push_back("");
				t = v.end() - 1;
				++count;
			}
			t->push_back(c);
			inword = true;
		}
	return count;
}
void vsswap(vector<string>::iterator i, vector<string>::iterator j)
{
	string temp;
	temp = *i;
	*i = *j;
	*j = temp;
}
void vsqksort(vector<string>::iterator left, vector<string>::iterator right)
{
	if (left >= right)
		return;
	vsswap(left, left + (right - left) / 2);
	auto last = left;
	for (auto i = left + 1; i < right; ++i)
		if (stringcmp(*i, *left) < 0)
			vsswap(++last, i);
	vsswap(left, last);
	vsqksort(left, last);
	vsqksort(last + 1, right);
}
void vssort(vector<string> &vs)
{
	vsqksort(vs.begin(), vs.end());
}
void bitset(unsigned &v, int n)
{
	v |= (1ul << n);
}
void bitclr(unsigned &v, int n)
{
	v &= (1ul << n);
}
bool bitchk(unsigned v, int n)
{
	return (v & ~(1ul << n)) == 0 ? false : true;
}
int fact(int n)
{
	if (n > 1)
		return fact(n - 1) * n;
	return 1;
}
int viprn(const vector<int> &vi, unsigned i)
{
	if (i < vi.size())
	{
		cout << vi[i] << endl;
		viprn(vi, i + 1);
	}
}
//test these functions
void test_recursion(void)
{
	for (int i = 1; i <= 10; ++i)
		COUT_VAR(fact(i));
	vector<int> vi = {10, 20, 30, 40, 50, 60};
	viprn(vi, 0);
}
void bitprn(unsigned long v)
{
	unsigned long m = ~(~0UL >> 1);
	for (int n = 0; n < sizeof(v) * 8; ++n, m >>= 1)
	  cout << (((v & m) == 0) ? 0 : 1) << ((n % 8 == 0 && n != 0) ? " - " : " ");
	cout << endl;
}
void test_bit(void)
{
	unsigned i = 0;
	bitset(i , 3);
	bitset(i , 4);
	bitprn(i);
	bitclr(i, 4);
	bitset(i, 0);
	bitset(i, sizeof(i) * 8 - 1);
	COUT_VAL(bitchk(i, 3));
	bitprn(i);
}
	
void test_stringcmp(void)
{
	string s("aaa"), t("aaab");
	cout << "compare : " << s << " -  " << t << " : " << (stringcmp(s, t)) << endl;
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
void test_stringvec(void)
{
	string input("1 22 333 4444    55555 666666 7777777 88888888     999999999 z");
	vector<string> vs;
	int i = stringvec(input, vs);
	cout << "string to vec count: " << i << endl;
	for (auto s : vs)
		cout << s << endl;
}
int main(int argc, char *argv[])
{
	cout << "Usage: input some words, end with CTRL-D, or : ./a.out<0test.c" << endl;
	string buf;
	vector<string> vec;
	while (getline(cin, buf))
	{
	  cout << buf << endl;
	  stringvec(buf, vec);
	}
	vssort(vec);
	for (auto s : vec)
	  cout << s << endl;
	test_stringcmp();
	test_stringsch();
	test_stringvec();
	test_bit();
	test_recursion();
	return 0;
}


