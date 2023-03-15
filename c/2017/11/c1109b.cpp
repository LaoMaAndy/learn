/*
function: var_type, string_type, vector_type, array_type
*/
#include "0head.cpp"

void var_type(void)
{
	int a = 0;
	int *b = &a;
	int &c = a;
	int *&d = b;
	const int e = 10;
	const int *f = &e;
	const int &g = e;
	const int *&h = f;
	const int * const i = &e;
	const int * const &j = f;
	constexpr int k = e * 20;
	typedef int l[10];
	typedef int *m[20];
	typedef int (*n)[20];
	typedef int (*o)(int);
	typedef int (*p[10])(int);
	using q = vector<o>;
	using r = q*;
	q s;
	r t;
	decltype(*t) u = s;
	decltype((t)) v = t;
	auto w = s.begin();
	auto x = t->end();
	void (*Signal(int sig, void (*handler)(int)))(int);
}
void string_type(void)
{
	string s("12342178");
	string t("abjdks");
	string r;

	r = s + t;
	r = s;
	s.size();
	s.empty();
	s.push_back('s');
	bool i = (s == t);
}
void vector_type(void)
{
	vector<int> v(10);
	vector<int> v2(10, 2);
	vector<int> v3{10};
	vector<int> v4{10, 2};
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
		*i = *i * 2;
	for (auto i = 0; i < v.size(); ++i)
		v[i] = v[i] + 3;
}
void array_type()
{
	int a[20];
	int b[5][4];
	vector<int> v(begin(a), end(a));
	int i = 1, j = 0;
	for (auto p = begin(a); p < end(a); ++p)
		*p = i + j, i = j, j = *p;
	for (auto i : a)
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
