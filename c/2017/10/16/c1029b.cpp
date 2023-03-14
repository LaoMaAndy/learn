/*
function: var_type, string_type, vector_type, array_type
*/
#include "0head.cpp"
void var_type(void)
{
	int a = 10;
	int *ap = &a;
	int &ar = a;
	int *&apr = ap;
	const int b = a;
	const int *bp = &b;
	const int &br = b;
	const int *bpr = bp;
	const int *const bcp = &b;
	constexpr int c = 0;
	typedef const unsigned long int CUL;
	using vint = vector<int>;
	vint vi;
	vint *vip;
	auto tb = vi.begin();
	auto te = vi.end();
	decltype(vi.size()) size;
	decltype(*vip) vr = vi;
	decltype((vip)) vp = vip;
}
void string_type(void)
{
	string s("123456");
	string t("abcdefg");
	string r;
	s.size();
	s.empty();
	s.push_back('a');
	s[0];
	r = s + t;
	r = s;
	bool b;
	b = (s == t);
	b = (s != t);
	b = (s > t);
	b = (s < t);
}
void vector_type(void)
{
	vector<int> v(10, 1);
	vector<int> v2(10);
	vector<int> v3{10};
	vector<int> v4 = {10, 2, 2};
	vector<int> v5{10, 20};
	ptrdiff_t d = v.end() - v.begin();
	auto vp = &v;
	auto n1 = v.size();
	auto n2 = (*vp).size();
	auto n3 = vp->size();
	auto n4 = v.cend() - v.cbegin();
	for (auto &i : v)
		i = i + 1;
	for (auto ca = v.begin(); ca != v.end(); ++ca)
		*ca = *ca * 2;
	for (auto i = v.size() - 1; i > 0; --i)
		v[i] = v[i] + 1;
	for (auto i : v)
		COUT_VAR(i);
}
void array_type(void)
{
	int a[20];
	int b[4][5];
	int i = 1, j = 0;
	for (auto p = begin(a); p < end(a); ++p)
		*p = i + j, i = j, j = *p;
	vector<int> vi(begin(a), end(a));
	for (auto n : vi)
		COUT_VAR(n);
	for (auto &row : b)
		for (auto &col : row)
			COUT_VAR(col);
}
void fun_type(void)
{
	typedef int *ip;
	typedef int foo(int, int);
	typedef foo *foop;
	typedef int (*FP)(int, int);
	vector<FP> vf;
	vector<foo*> vfp;
	vector<int *> vip;
}
//test these functions:
int main() {
	var_type();
	string_type();
	vector_type();
	array_type();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

	
	

