/*
cpp basic: var_type, string_type, vector_type, array_type
*/
#include "0head.cpp"
void var_type(void)
{
	int a = 10;
	int *b = &a;
	int &c = a;
	int *&d = b;
	const int e = 20;
	const int *f = &e;
	const int &g = e;
	const int *&h = f;
	const int * const i = &e;
	const int * const &j = f;
	constexpr int k = e * 30;
	typedef int l[10];
	typedef int *m[10];
	typedef int (*n)[10];
	typedef int (*o)(int);
	typedef int (*p[10])(int);
	using r= vector<o>;
	using s = r*;
	r t;
	s u;
	auto v = t.begin();
	auto w = u->end();
	decltype(*u) x = t;
	decltype((u)) y = u;
	void (*Signal(int sig, void (*handler)(int)))(int);
}
void string_type(void)
{
	string s("11232142");
	string t("abde");
	string r;
	s.size();
	t.empty();
	r = s + t;
	s.push_back('t');
	r = s;
	bool b = (s == t);
}
void vector_type(void)
{
	vector<int> v(10);
	vector<int> v1(10, 2);
	vector<int> v2{10};
	vector<int> v3{10,2};
	vector<int> v5 = {12};
	ptrdiff_t d = v.begin() - v.end();
	auto p = &v;
	auto n1 = v.end() - v.begin();
	auto n2 = v.size();
	auto n3 = p->size();
	auto n4 = (*p).size();
	for (auto &i : v)
		i = i + 3;
	for (auto i = v.begin(); i != v.end(); ++i)
		*i = *i * 2;
	for (auto i = 0; i < v.size(); ++i)
		v[i] = v[i] + 1;
}
void array_type(void)
{
	int a[20];
	int b[5][4];
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
