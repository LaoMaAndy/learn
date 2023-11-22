#include "0head.cpp"
int stringcmp(const string s, const string t)
{
	auto cs = s.begin(), ct = t.begin();
	for ( ; cs != s.end() && ct != t.end(); ++cs, ++ct)
	  if (*cs != *ct)
		return *cs - *ct;
	return (s.end() - cs) - (t.end() - ct);
}
int stringsch(const string x, const vector<string> v)
{
	int low = 0;
	int high = v.size();
	auto base = v.begin();
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
int strtovec(const string s, vector<string> &v)
{
	if (s.size() == 0)
	  return 0;
	if (v.size() == 0)
	  v.push_back("");
	bool inword = false;
	int count = 0;
	auto vp = v.end() - 1;
	for (auto c : s)
	{
		if (isspace(c) && inword)
		{
			++vp;
			inword = false;
		}
		else if(!isspace(c))
		{
			if (!inword)
			{
				++count;
				inword = true;
			}
			if (vp == v.end())
			{
				v.push_back("");
				vp = v.end() - 1;
			}
			vp->push_back(c);
		}
	}
	return count;
}
void c11_var(void)
{
	int i = 1024;
	int &ir = i;
	int *ip = &ir;
	const int ci = 12;
	const int *cip = &ci;
	const int &cir = ci;
	const int *&cipr = cip;
	vector<int> v1 = {0};
	vector<int> v2{10,20};
	vector<int> v3(10, 1);
	vector<int> v4(10);
}
void c11_type(void)
{
	typedef double DOUBLE;
	using LD_TYPE = long double;
	vector<DOUBLE> vd;
	auto pv = vd.begin();
	decltype(vd.begin()) pva;
	int i;
	int *sp = &i;
	decltype(*sp) tp = i;
}
void c11_size(void)
{
	string s = "a string";
	string *p= &s;
	auto n1 = s.size();
	auto n2 = (*p).size();
	auto n3 = p->size();
	auto n4 = s.end() - s.begin();
}
void bittype(void)
{
	unsigned long q = 15;
	q |= 1UL << 27;
	q &= ~(1UL << 17);
	bool s = q & (1UL << 27);
	cout << q << s << endl;
}
void stringtype(void)
{
	string s("This");
	string t("12345");
	string r;
	s.size();
	s.empty();
	s.push_back('.');
	s[0] = 'a';
	r = s + t;
	s += t;
	r = t;
	bool c = (s == t);
	c = (s > t);
	c = (s < t);
}
void vectortype(void)
{
	vector<int> v1(7);
	vector<int> v2{10};
	vector<int> v3(10, 1);
	vector<int> v4 = {1, 2, 3};
	vector<int>::const_iterator it;
	ptrdiff_t dt = v1.end() - v1.begin();
	for (auto i : v1)
	  cout << i;
	for (auto &i : v1)
	  cout << (i *= 2);
	for (decltype(v1.size()) i = 0; i < v1.size(); ++i)
	  cout << v1[i];
	for (auto i = v1.begin(); i != v1.end(); ++i)
	  cout << *i;
	for (decltype(v1.size()) i = 0; i < v1.size(); ++i)
	  cout << *(v1.begin() + i);
}
void arraytype(void)
{
	int ia [10];
	int *p;
	for (p = begin(ia); p != end(ia); ++p)
		cout << *p;
	p[-2] = 100;
	vector<int> vi(begin(ia), end(ia));
	int ib[4][4];
	for (auto &row : ib)
	  for (auto &col : row)
		cout << col;
}

/*test these function */
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
void test_strtovec(void)
{
	string input("  is     is that that are are are find find find find");
	vector<string> vs{""};
	int i = strtovec(input, vs);
	cout << "count: " << i << endl;
	for (auto s : vs)
		cout << s << endl;
}
int main() {
	c11_var();
	c11_type();
	c11_size();
	bittype();
	stringtype();
	vectortype();
	arraytype();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}


