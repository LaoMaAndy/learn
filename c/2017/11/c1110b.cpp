/*
funciont: var_type, string_type, vector_type, array_type
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
	const int * const h = &e;
	const int * const &i = h;
	constexpr int j = e * 20;
	typedef int k[10];
	typedef int *l[10];
	typedef int (*m)[10];
	typedef int n(int);
	typedef int (*o[10])(int);
	using p = vector<m>;
	using q = p*;
	p r;
	q s;
	auto t = r.begin();
	auto u = s->end();
	decltype(*s) v = r;
	decltype((s)) w = s;
	void (*Signal(int sig, void (*handler)(int)))(int);
}
void string_type(void)
{
	string s("4372819");
	string t("fjkdasl");
	string r;
	r = s + t;
	r = s;
	s.empty();
	s.size();
	s.push_back('c');
	bool i = (s == t);
}
void vector_type(void)
{
	vector<int> v(10);
	vector<int> v2(10, 2);
	vector<int> v3{10};
	vector<int> v4{10, 12};
	vector<int> v5 = {10};
	ptrdiff_t a = v.begin() - v.end();
	auto p = &v;
	auto n1 = v.size();
	auto n2 = v.end() - v.begin();
	auto n3 = p->size();
	auto n4 = (*p).size();
	for (auto &i : v)
		i = i + 1;
	for (auto i = v.begin(); i != v.end(); ++i)
		*i = *i + 2;
	for (auto i = 0; i < v.size(); ++i)
		v[i] = v[i] + 3;
}
void array_type(void)
{
	int a[20];
	int b[4][5];
	vector<int> v(begin(a), end(a));
	int i = 1, j = 0;
	for (auto p = v.begin(); p != v.end(); ++p)
		*p = i + j, i = j, j = *p;
	for (auto i : v)
		COUT_VAR(i);
	for (auto &row : b)
		for (auto &col : row)
			COUT_VAR(col);
}
int main(void)
{
	array_type();
	return 0;
}


