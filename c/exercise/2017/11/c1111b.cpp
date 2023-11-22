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
	const int e = 10;
	const int *f = &a;
	const int * const g = &e;
	const int &h = e;
	const int *&i = f;
	const int * const &j = g;
	constexpr int k = e;
	typedef int l[10];
	typedef int *m[10];
	typedef int (*n)[10];
	typedef int o(int);
	typedef int (*p)(int);
	typedef int (*r[10])(int);
	typedef int (*(*s)[10])(int);
	using t = vector<p>;
	using u = t*;
	t v;
	u w;
	auto x = v.end();
	auto y = w->begin();
	decltype(*w) z = v;
	decltype((w)) z1 = w;
	void (*signal(int sig, void (*handler)(int)))(int);
}	
void string_type(void)
{
	string s("123213");
	string t("badjkaf");
	string r;
	
	r = s + t;
	r = s;
	s.size();
	s.empty();
	auto i = s.begin();
	s.push_back('c');
	auto b = (s == t);
}
void vector_type(void)
{
	vector<int> v(10);
	vector<int> v2(10, 2);
	vector<int> v3{10};
	vector<int> v4{10, 2};
	vector<int> v5 = {10};
	auto p = &v;
	auto n1 = v.size();
	auto n2 = v.end() - v.begin();
	auto n3 = p->size();
	auto n4 = (*p).size();
	ptrdiff_t t = v.begin() - v.end();
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
	for (auto i : v)
		COUT_VAR(i);
	int n = 0;
	for (auto &row : b)
		for (auto &col : row)
			COUT_VAR(col);
}

int main(void)
{
	var_type();
	string_type();
	vector_type();
	array_type();
	return 0;
}
