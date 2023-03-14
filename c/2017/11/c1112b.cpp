/*
function: var_type, string_type, vector_type, array_type
*/
#include "0head.cpp"

void var_type(void)
{
	int a;
	int *b = &a;
	int &c = a;
	int *&d = b;
	const int e = 20;
	const int *f = &a;
	const int &g = e;
	const int *&h = f;
	const int * const i = &e;
	const int * const &j = f;
	const int * const *k = &f;
	constexpr int l = e * 20;
	typedef int m[20];
	typedef int *n[20];
	typedef int (*o)[20];
	typedef int *(*p)[20];
	typedef int q(int);
	typedef int (*r)(int);
	typedef int (*s[20])(int);
	typedef int *(*t[20])(int);
	using u = vector<r>;
	using v = u*;
	u w;
	v x = &w;
	auto y = w.begin();
	auto z = x->end();
	decltype(*x) z1 = w;
	decltype((x)) z2 = x;
	void (*Signal(int sig, void *handler(int)))(int);
}
void string_type(void)
{
	string s("123214");
	string t("13721i9");
	string r = s + t;
	r = s;
	r.push_back('t');
	r.size();
	r.empty();
	bool b = (s == r);
}
void vector_type(void)
{
	vector<int> v(10);
	vector<int> v1(10, 2);
	vector<int> v3{10};
	vector<int> v4{10, 2};
	vector<int> v5 = {10, 2};
	auto p = &v;
	ptrdiff_t d = p->end() - p->begin();
	auto n = v.size();
	auto n1 = v.end() - v.begin();
	auto n2 = p->size();
	auto n3 = (*p).size();
	for (auto &i : v)
		i = i * 2;
	for (auto i = v.begin(); i != v.end(); ++i)
		*i = *i * 2;
	for (auto i = 0; i < v.size(); ++i)
		v[i] = v[i] * 2;
}

void array_type(void)
{
	int a[20];
	int b[4][5];
	int i = 1, j = 0;
	for (auto p = begin(a); p < end(a); ++p)
		*p = i + j, i = j, j = *p;
	vector<int> v(begin(a), end(a));
	for(auto fibonacci : v)
		COUT_VAR(fibonacci);
	i = 0;
	for (auto &row : b)
		for (auto &col : row)
			col = i++;
}


int main(void)
{
	var_type();
	string_type();
	vector_type();
	array_type();
}

