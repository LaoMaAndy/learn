//cpp. basics
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
	return - 1;
}
int stringvec(const string &s, vector<string> &v)
{
	bool inword = false;
	int count = 0;
	vector<string>::iterator vp;
	for (auto c : s)
	{
		if (isspace(c))
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
#define STRING_OK
void var_type(void)
{
	int a = 1;
	int &ar = a;
	int *ap = &a;
	int *&arp = ap;
	const int b = 12;
	const int &br = a;
	const int &bbr = b;
	const int *ba = &a;
	const int *bb = &b;
	const int *&bpr = ba;
	constexpr int c = b ;
	vector<int> ca(10);
	vector<int> cb(10, 1);
	vector<int> cc{10};
	vector<int> cd = {0};
	vector<int> ce = {10, 20};
	typedef const unsigned long CUL;
	typedef vector<int> VINT;
	using VSTR = vector<string>;
	using VVSTR = vector<vector<string>>;
	VINT f;
	VINT *fp;
	auto gb = f.begin();
	auto ge = f.end();
	vector<int>::iterator hi;
	vector<int>::reverse_iterator hr;
	decltype(f.end()) h_end;
	decltype(f.size()) h_size;
	decltype(*fp) r_f = f;
	decltype((fp)) r_rp = fp;
}
void string_type(void)
{
	string s("12345");
	string t("abdcde");
	string r;
	s.size();
	s.empty();
	s.push_back('d');
	s[0];
	r = s + t;
	r = s;
	int i = s == t;
	i = s != t;
	i = s > t;
	i = s < t;
}
void vector_type(void)
{
	vector<int> v(10);
	
}
/*test these function */
#if defined(BASIC_OK)
void bit_type(void)
{
	unsigned long i = 0;
	bit_set(i , 3);
	bit_set(i , 4);
	bit_prn(i);
	bit_clr(i, 4);
	bit_set(i, 0);
	bit_set(i, sizeof(i) * 8 - 1);
	COUT_VAL(bit_chk(i, 3));
	bit_prn(i);
}
#endif
#if defined(STRING_OK)
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
#endif
int main() {
#if defined(BASIC_OK)
	vector_type();
	array_type();
	string_type();
	bit_type();
#endif
#if defined(STRING_OK)
	test_stringcmp();
	test_stringsch();
	test_stringvec();
#endif
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}


