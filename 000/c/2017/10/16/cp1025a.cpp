//fucntion: stringcmp, stringvec, stringsch, vsswap, vsqksort, vssort
#include "0head.cpp"
int stringcmp(const string &s, const string &t)
{
	decltype(*(string::iterator)) cs, ct;
	string::size_type i = 0;
	do
	{
		cs = s[i];
		ct = t[i];
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
		++i;
	} while (cs == ct);
	return cs - ct;
}
int stringsch(const string &s, const vector<string> &v)
{
	vector<string>::size_type low = 0, high = v.size();
	while (low < high)
	{
		decltype(high) mid = (low + high) / 2;
		int r = v[mid].compare(s);
		if (r > 0)
		  high = mid;
		else if (r < 0)
		  low = mid + 1;
		else 
		  return mid;
	}
	return -1;
}
int stringvec(const string &s, vector<string> &v)
{
	vector<string>::iterator tv;
	int count = 0;
	bool inword = false;
	for (auto c : s)
	{
		if (!isalnum(c))
			inword = false;
		else
		{
			if (!inword)
			{
				v.push_back("");
				tv = v.end() - 1;
				++count;
			}
			tv->push_back(c);
			inword = true;
		}
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

