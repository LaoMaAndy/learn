/* 
function: stringsch, stringcmp, stringvec, vsswap, vsqksort
*/
#include "0head.cpp"
int stringcmp(const string &s, const string &t)
{
	char cs, ct;
	cs = ct = '\0';
	for (decltype(s.size()) i = 0; cs == ct; ++i)
	{
		if (i == s.size())
		{
			cs = '\0';
			break;
		}
		if (i == t.size())
		{
			ct = '\0';
			break;
		}
		cs = s[i];
		ct = t[i];
	}
	return cs - ct;
}
int stringsch(const string &s, const vector<string> &v)
{
	int low = 0, high = v.size();
	while (low < high)
	{
		int mid = (low + high) / 2;
		int r = s.compare(v[mid]);
		if (r < 0)
			high = mid;
		else if (r > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
int stringvec(const string &s, vector<string> &v)
{
	int count = 0;
	bool inword = false;
	vector<string>::iterator vt;
	for (auto c : s)
		if (!isalnum(c))
			inword = false;
		else
		{
			if (inword == false)
			{
				v.push_back("");
				vt = v.end() - 1;
				++count;
			}
			vt->push_back(c);
			inword = true;
		}
	return count;
}
void vsswap(vector<string>::iterator s, vector<string>::iterator t)
{
	string temp;
	temp = *s;
	*s = *t;
	*t = temp;
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
void vssort(vector<string> &vs)
{
	vsqksort(vs.begin(), vs.end());
}
//test these functions
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
	return 0;
}

