/*
function: stringcmp,stringvx, stringvec, stringsch, vsswap, vssort, vsuniq
*/
#include "0head.cpp"

int stringcmp(const string &s, const string &t)
{
	auto ss = s.size(), ts = t.size();
	decltype(ss) i;

	for (i = 0; i != ss && i != ts; ++i)
		if (s[i] != t[i])
			return (s[i] - t[i]);
	auto a = (i == ss) ? 0 : s[i];
	auto b = (i == ts) ? 0 : t[i];
	return a - b;
}
size_t stringsch(const string &x, const vector<string> &v)
{
	size_t low = 0, high = v.size();
	while (low < high)
	{
		auto mid = (low + high) / 2;
		auto r = stringcmp(v[mid], x);
		if (r > 0)
			high = mid;
		else if (r < 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
size_t stringvx(const string &x, vector<string> &v, int (*valid)(int))
{
	size_t count = 0;
	bool inword = false;
	decltype(v.end()) t;

	for (auto c : x)
	{
		if (!valid(c))
			inword = false;
		else
		{
			if (inword == false)
			{
				v.push_back("");
				t = v.end() - 1;
				++count;
				inword = true;
			}
			t->push_back(c);
		}
	}
	return count;
}
void stringtok(const string &x, vector<string> &v)
{
	size_t count = 0;
	bool inword = false;
	bool indigit = false;
	decltype(v.end()) t;

	for (auto c : x)
	{
		if (!isdigit(c))
		{
			inword = false;
			indigit = false;
		}
		else
		{
		}
	}
}
int isnspace(int chr)
{
	return !isspace(chr);
}
int istoken(int chr)
{
	return isalnum(chr) || chr == '-';
}
size_t stringvec(const string &x, vector<string> &v)
{
	return stringvx(x, v, isnspace);
}
void vsswap(vector<string>::iterator i, vector<string>::iterator j)
{
	string temp = *i;
	*i = *j;
	*j = temp;
}
void vsqksort(vector<string>::iterator left, vector<string>::iterator right)
{
	if (left >= right)
		return;
	vsswap(left, left + (right - left) / 2);
	auto last = left;
	for (auto i = left + 1; i != right; ++i)
		if (stringcmp(*i, *left) < 0)
			vsswap(++last, i);
	vsswap(left, last);
	vsqksort(left, last);
	vsqksort(last + 1, right);
}
void vssort(vector<string> &v)
{
	vsqksort(v.begin(), v.end());
}
void vsuniq(const vector<string> &src, vector<string> &dest)
{
	decltype(src.size()) i = 0;
	if (i != src.size())
		dest.push_back(src[i++]);
	while (i != src.size())
	{
		if (stringcmp(*(dest.end() - 1), src[i]) != 0)
			dest.push_back(src[i]);
		++i;
	}
}
//test these functions 
void test_stringcmp(void) 
{ 
	string s("aaa"), t("aaab");
	cout << "compare result: " << (stringcmp(s, t)) << " :\t"  << s << " - " << t << endl;
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
	  //stringvx(buf, vec, isalnum);
	}
	vssort(vec);
	for (auto s : vec)
	  cout << s << endl;
	test_stringcmp();
	test_stringsch();
	test_stringvec();
	vector<string> u;
	vsuniq(vec, u);
	for (auto s : u)
		cout << s << endl;
	return 0;
}



