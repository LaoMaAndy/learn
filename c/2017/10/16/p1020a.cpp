#include "0head.cpp"
int stringcmp(const string s, const string t)
{
	auto cs = s.cbegin(), ct = t.cbegin();
	for ( ; cs != s.cend() && ct != t.cend(); ++cs, ++ct )
	  if (*cs != *ct)
		return *cs - *ct;
	return (s.cend() - cs) - (t.cend() - ct);
}
int stringsch(const string x, const vector<string> v)
{
	auto base = v.cbegin();
	int low, high;
	low = 0;
	high = v.size();
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
int strtovec(const string s, vector<string> &vs)
{
	if (s.size() == 0)
		return 0;
	if (vs.size() == 0)
		vs.push_back("");
	bool inword = false;
	int count = 0;
	auto vsp = vs.end() - 1;
	for (auto c : s)
		if (isspace(c) && inword == true)
		{
			++vsp;
			inword = false;
		}
		else if (!isspace(c))
		{
			if (inword == false)
			{
				++count;
				inword = true;
			}
			if (vsp == vs.end())
			{
				vs.push_back("");
				vsp = vs.end() - 1;
			}
			vsp->push_back(c);
		}
	return count;
}
void bitop(void)
{
	unsigned long q = 15;
	q |= 1UL << 27;
	q &= ~(1UL << 27);
	bool s = q & (1UL << 27);
}
void c11_var(void)
{
	// assignment
	vector<int> v1 = {0};
	vector<int> v2{10,12};
	vector<int> v3(10,1);
	vector<int> v4(10);
	COUT_VAR(v1.size());
	COUT_VAR(v2.size());
	COUT_VAR(v3.size());
	COUT_VAR(v4.size());
	// reference, pointer
	int i = 1024;
	int &ir = i;
	int *ip = &ir;
	int *&ipr = ip;
	const int ci = 12;
	const int *cip = &ci;
	const int &cir = ci;
	const int *&cipr = cip;
	COUT_VAR(i);
	COUT_VAR(ir);
	COUT_VAR(*ip);
	COUT_VAR(*ipr);
	COUT_VAR(ci);
	COUT_VAR(*cip);
	COUT_VAR(cir);
	COUT_VAR(*cipr);
}
constexpr int const_test(void)
{
	return 0;
}
int out_j = 0;
constexpr int out_i = 10;
void c11_type(void)
{
	//constexpr, auto, typedef, using, decltype
	constexpr int ci = 20;
	constexpr int cia = ci * 10 + 1;
	constexpr int sz = const_test();
	constexpr int *np = nullptr;
	constexpr int *ip = &out_j;
	constexpr const int *ipc = &out_i;
	COUT_VAR(ci);
	COUT_VAR(cia);
	COUT_VAR(sz);
	COUT_VAR(np);
	COUT_VAR(*ip);
	COUT_VAR(*ipc);
	typedef double DOUBLE;
	vector<DOUBLE> vd = {1.2, 1.3};
	using L_DOUBLE = long double;
	vector<L_DOUBLE> vld {9.2, 10.3};
	auto c1 = vd.begin();
	decltype(vd.begin()) c2 = vd.begin();
	decltype((vd.begin())) c3 = vd.begin();
	int i = 0;
	int *sp = &i;
	decltype(*sp) tp = i;
	COUT_VAR(tp = 12345);
	COUT_VAR(i);
	COUT_VAR(*c1);
	COUT_VAR(*c2);
	COUT_VAR(*c3);
	COUT_STR(a + b + c + d);
}
void test_string(void)
{
	string s("This is a test");
	string t("1234567890");
	string r("ABCDEFGHI");
	string p;
	COUT_VAR(s.size());
	COUT_VAR(s.empty());
	COUT_FUN(s.push_back('c'));
	COUT_VAR(s[0]);
	COUT_VAR(s + t);
	COUT_VAR(s = t);
	COUT_VAR(s == t);
	COUT_VAR(s != t);
	COUT_VAR(s > t);
	COUT_VAR(s < t);
	COUT_VAR(s);
	//COUT_FUN(getline(cin, p));
}
void test_vector(void)
{
	vector<int> v1(7);
	vector<int> v2{10};
	vector<int> v3(10, 1);
	vector<int> v4{10, 1};
	vector<int> v5 = {12, 2, 4, };
	v1.push_back(12);
	v1 = {11, 12, 13, 14, 15, 16, 17, 18};
	vector<int>::const_iterator it = v1.cbegin();
		ptrdiff_t dt = v1.cend() - v1.cbegin();
	COUT_INV("ptrdiff_t", dt);
	for (auto i : v1)
		COUT_VAR(i);
	for (auto &i : v1)
		COUT_VAR(i *= 2);
	for (unsigned i = 0; i < v1.size(); ++i)
		COUT_VAR(v1[i]);
	for (auto ca = v1.begin(); ca != v1.end(); ++ca)
		COUT_VAR(*ca);
	for (unsigned i = 0; i < v1.size(); ++i)
		COUT_VAR(*it);
}
void test_array(void)
{
	int ia[] = {21, 22, 23, 24, 25, 26};
	for (int *pi = begin(ia); pi < end(ia); ++pi)
		COUT_VAR(*pi);
	int *pt = &ia[3];
	pt[-2] = 100;
	vector<int> vi(begin(ia), end(ia));
	for (auto i : vi)
		COUT_VAR(i);
	int ib[4][4] = {{1, 2, 3, 4}, {10, 20, 30, 40}, {21, 22, 23, 24}, {51, 52, 53, 54}};
	for (auto &row : ib)
		for (auto &col : row)
			COUT_VAR(col);
}
void test_oper(void)
{
	string s = "a string";
	string *p = &s;
	auto n1 = s.size();
	auto n2 =  (*p).size();
	auto n3 = p->size();
	auto n4 = s.end() - s.begin();
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
	int max = 1;
	int c = 1;
	string pre("");
	for (auto s : vs)
	{
		if (s.compare(pre) == 0)
		{
			++c;
			if (c > max)
				max = c;
		}
		else
		{
			pre = s;
			c = 1;
		}
	}
	cout << "max continue same time: " << max << endl;
}
/***************/
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	c11_var();
	c11_type();
	test_string();
	test_vector();
	test_array();
	test_stringcmp();
	test_stringsch();
	test_strtovec();
	return 0;
}

