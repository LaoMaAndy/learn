// Getword() with cpp
#include "0head.cpp"
int stringcmp(const string &s, const string &t)
{
	auto cs = s.begin(), ct = t.begin();
	for ( ; cs != s.end() && ct != t.end(); ++cs, ++ct)
	  if (*cs != *ct)
		return *cs - *ct;
	return (s.end() - cs) - (t.end() - ct);
}
int stringsch(const string &x, const vector<string> &v)
{
	int low = 0;
	int high = v.size();
	while (low < high)
	{
		int mid = (low + high) / 2;
		int r = x.compare(v[mid]);
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
	vector<string>::iterator vp;
	for (auto c : s)
	{
		if (!isalnum(c))
		  inword = false;
		else
		{
			if (!inword)
			{
				v.push_back("");
				vp = v.end() - 1;
				++count;
			}
			vp->push_back(c);
			inword = true;
		}
	}
	return count;
}
void vecswap(vector<string>::iterator i, vector<string>::iterator j)
{
	string temp;
	temp  = *i;
	*i = *j;
	*j = temp;
}
void vecqsort(vector<string>::iterator left, vector<string>::iterator right)
{
	vector<string>::iterator i, last;
	if (left >= right)
		return ;
	vecswap(left, (left + (right - left) / 2));
	last = left;
	for (i = left + 1; i != right; ++i)
		if (stringcmp(*i, *left) < 0)
			vecswap(++last, i);
	vecswap(left, last);
	vecqsort(left, last);
	vecqsort(last + 1, right);
}
void vecsort(vector<string> &v)
{
	vecqsort(v.begin(), v.end());
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
	test_stringcmp();
	test_stringsch();
	test_stringvec();
	cout << "Usage: input some words, end with CTRL-D, or : ./a.out<0test.c" << endl;
	string buf;
	vector<string> vec;
	while (getline(cin, buf))
	{
	  cout << buf << endl;
	  stringvec(buf, vec);
	}
	vecsort(vec);
	for (auto s : vec)
	  cout << s << endl;
	return 0;
}
