/*
 * function: stringcmp, stringvec, stringsch
 */
#include "0head.cpp"
int stringcmp(const string &s, const string &t)
{
	auto sp = s.begin(), tp = t.begin();
	for ( ; sp != s.end() && tp != t.end(); ++sp, ++tp )
	  if (*sp != *tp)
		return *sp - *tp;
	return (s.end() - sp) - (t.end() - tp);
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
	int inword = false;
	int count = 0;
	decltype(v.end()) vp;
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
	int i = 1;
	int &ir = i;
	int *ip = &i;
	int *&irp = ip;
	const int n = 12;
	const int *np = &n;
	const int &nr = n;
	const int *&nrp = np;
	constexpr int ca = n * 10 + 2;
	vector<int> va(10);
	vector<int> vb(10, 1);
	vector<int> vc{10};
	vector<int> vd = {0};
	vector<int> ve = {10, 20};
	typedef const string CONSTR;
	typedef vector<int> VECINT;
	using STR = string;
	using VSTR = vector<string>;
	VSTR vs;
	VSTR *vsp;
	auto sb = vs.begin();
	auto sbr = vs.begin();
	vector<string>::iterator st;
	vector<string>::reverse_iterator rst;
	decltype(vs.end()) vs_end;
	decltype(vs.size()) vs_size;
	decltype(*vsp) r_vs = vs;
	decltype((vsp)) r_vsp  = vsp;
}
void string_type(void)
{
	string s("abcdefg");
	string t("12345678980");
	string r;
	s.size();
	s.empty();
	s.push_back('c');
	s[0];
	r = s + t;
	r = s;
	s == t;
	s != t;
	s > t;
	s < t;
}
void vector_type(void)
{
	vector<int> v1(10);
	ptrdiff_t pt = v1.cend() - v1.cbegin();
	auto vp = &v1;
	auto n1 = v1.size();
	auto n2 = (*vp).size();
	auto n3 = vp->size();
	auto n4 = v1.cend() - v1.cbegin();
	int n = 0;
	for (auto &i : v1)
	  i = n++;
	for (auto i : v1)
	  COUT_VAR(i);
	for (auto ca = v1.begin(); ca != v1.end(); ++ca)
	  *ca = *ca * *ca;
	for (size_t i = 0; i < v1.size(); ++i)
	  COUT_VAR(v1[i]);
	for (size_t i = 0; i < v1.size(); ++i)
	  COUT_VAR(*(v1.begin() + i) * i);
	for (auto i : v1)
	  COUT_VAR(i);
}
void bit_prn(unsigned long v)
{
	unsigned long m = ~(~0UL >> 1);
	for (int n = 0; n < sizeof(v) * 8; ++n, m >>= 1)
	  cout << (((v & m) == 0) ? 0 : 1) << ((n % 8 == 0 && n != 0) ? " - " : " ");
	cout << endl;
}
bool bit_chk(unsigned long v, int n)
{
	return (v & (1UL << n) == 0 ? false : true);
}
void bit_set(unsigned long &v, int n)
{
	v |= 1UL << n;
}
void bit_clr(unsigned long &v, int n)
{
	v &= ~(1UL << n);
}
void array_type(void)
{
	int ia[20];
	int i = 1, j = 0;
	for (auto pi =  begin(ia); pi < end(ia); ++pi)
	  *pi = i + j, j = i, i = *pi;
	vector<int> vi(begin(ia), end(ia));
	for (auto array_item : vi)
		COUT_VAR(array_item);
	int ib[4][5];
	i = 0;
	for (auto &row : ib)
		for (auto &col : row)
			col = ia[i++];
	for (auto &row : ib)
	  for (auto &col : row)
		COUT_VAR(col);
}
#define BASIC_OK

/*test these function */
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
void test_stringvec(void)
{
	string input("1 22 333 4444    55555 666666 7777777 88888888     999999999 z");
	vector<string> vs;
	int i = stringvec(input, vs);
	cout << "string to vec count: " << i << endl;
	for (auto s : vs)
		cout << s << endl;
}
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


