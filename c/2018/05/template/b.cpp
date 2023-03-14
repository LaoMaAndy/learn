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
	const int e = 3;
	const int *f = &e;
	const int &g = e;
	const int * const h = &a;
	const int * const &i = f;
	constexpr int j = e * 2;
	typedef int k[20];
	typedef int *l[20];
	typedef int (*m)[20];
	typedef int *(*n)[20];
	typedef int o(int);
	typedef int *p(int);
	typedef int (*q)(int);
	typedef int *(*r)(int);
	typedef int (*s[20])(int);
	using t = vector<s>;
	using u = t*;
	t v;
	u w = &v;
	auto x = v.begin();
	auto y = w->end();
	decltype(*w) z = v;
	decltype((w)) z1 = w;
	void (*Signal(int sig, void *handler(int)))(int);	
}
void string_type(void)
{
	string s("123213");
	string t("fdjka");
	string r;

	r = s + t;
	r.push_back('t');
	r.size();
	r.empty();
	bool b = (s == t);
}
void vector_type(void)
{
	vector<int> v(10);
	vector<int> v1(10, 2);
	vector<int> v2{10};
	vector<int> v3{10, 2};
	vector<int> v4 = {10};
	vector<int> v5 = {10, 2};
	auto p = &v;
	ptrdiff_t n = p->end() - p->begin();
	auto n1 = v.size();
	auto n2 = v.end() - v.begin();
	auto n3 = p->size();
	auto n4 = (*p).size();
	for (auto &i : v)
		i = i * 2;
	for (auto i = v.begin(); i != v.end(); ++i)
		*i = *i * 2;
	for (auto i = 0; i != v.size(); ++i)
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
	for (auto fibo : v)
		COUT_VAR(fibo);
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



