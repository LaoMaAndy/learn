/*
function: val, string, vector, array, func
*/
#include "0head.cpp"
void var_type(void)
{
	int a = 1;
	int *pa = &a;
	int &rp = a;
	int *&rpa = pa;
	const int b = 10;
	const int *pb = &b;
	const int &rb = b;
	const int *&rpb = pb;
	constexpr int c = b + 1;
	typedef int d10[10];
	typedef int (*e10)[10];
	typedef int (*f)(int, int);
	using vf = vector<f>;
	using pvf = vf*;
	vf g;
	pvf pg;
	auto tga = g.begin();
	auto tgb = g.end();
	decltype(*pg) rg = g;
	decltype((pg)) rpg = pg;
}
void string_type(void)
{
	string s("123456");
	string t("abcdef");
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
	vector<int> v4{10, 12};
	vector<int> v5 = {10, 20};
	ptrdiff_t d = v.end() - v.begin();
	auto pv = &v;
	auto n1 = v.size();
	auto n3 = v.end() - v.begin();
	auto n2 = (*pv).size();
	auto n4 = pv->size();
	for (auto &i : v)
		i = i + 1;
	for (auto i = v.begin(); i != v.end(); ++i)
		*i = *i * 2;
	for (auto i = 0; i < v.size(); ++i)
		v[i] = v[i] * 2;
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
int main() {
	var_type();
	string_type();
	vector_type();
	array_type();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

