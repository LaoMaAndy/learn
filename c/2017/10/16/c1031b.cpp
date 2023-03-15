/*
function: var_type, string_type, vector_type, array_type
*/
#include "0head.cpp"
void var_type(void)
{
	int a = 10;
	int *b = &a;
	int &c = a;
	int *&d = b;
	int * const e = &a;
	int * const &f = b;
	const int g = 20;
	const int &h = g;
	const int *i = &g;
	const int *&j = i;
	const int * const k = &g;
	const int * const &l = i;
	constexpr int m = g;
	typedef int n[10];
	typedef int *o[10];
	typedef int (*p)[10];
	typedef int (*q)(int, int);
	using r = vector<q>;
	using s = r*;
	r t;
	s u;
	auto v = t.begin();
	auto w = t.end();
	decltype(*u) x = t;
	decltype((u)) y = u;
	void (*Signal(int sig, void (*handler)(int)))(int);
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
	bool b = (s == t) && (s != t) || (s > t) || (s < t);
}
void vector_type(void)
{
	vector<int> v(10, 1);
	vector<int> v2(20);
	vector<int> v3{20};
	vector<int> v4{10, 10};
	vector<int> v5 = {10, 10};
	ptrdiff_t d = v.end() - v.begin();
	auto p = &v;
	auto n1 = v.size();
	auto n2 = v.end() - v.begin();
	auto n3 = (*p).size();
	auto n4 = p->size();
	for (auto &i : v)
		i = i + 1;
	for (auto i = v.begin(); i != v.end(); ++i)
		*i = *i * 2;
	for (auto i = 0; i < v.size(); ++i)
		v[i] = v[i] * 3;
}
void array_type(void)
{
	int a[20];
	int b[4][5];
	int i = 1, j = 0;
	for (auto p = begin(a); p < end(a); ++p)
		*p = i + j, i = j, j = *p;
	vector<int> vi(begin(a), end(a));
	for (auto i : vi)
		COUT_VAR(i);
	for (auto &row : b)
		for (auto &col : row)
			COUT_VAR(col);
}

int main()
{
	array_type();
	return 0;
}
