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
	const int e = 20;
	const int *f = &a;
	const int &g = e;
	const int *&h = f;
	const int * const i = &a;
	const int * const &j = f;
	constexpr int k = 3 * e;
	typedef int l[20];
	typedef int *m[20];
	typedef int (*n)[20];
	typedef int *(*o)[20];
	typedef int p(int);
	typedef int *q(int);
	typedef int (*q1)(int);
	typedef int (*r[20])(int);
	using s = vector<q1>;
	using t = s*;
	s u;
	t v = &u;
	auto  w = u.begin();
	auto x = v->end();
	decltype(*v) y = u;
	decltype((v)) z = v;
	void (*Signal (int sig, void *handler(int)))(int);
}
void string_type(void)
{
	string s("1322178");
	string t("fdjask");
	string r;
	r = s + t;
	r = s;
	r.size();
	r.empty();
	bool a = (r > s);
}
void vector_type(void)
{
	vector<int> v(10);
	vector<int> v2(10, 2);
	vector<int> v3{10};
	vector<int> v5{10, 2};
	vector<int> v4 = {10};
	auto p = &v;
	auto n = v.size();
	auto n1 = v.end() - v.begin();
	auto n2 = p->size();
	auto n3 = (*p).size();
	for (auto &i : v)
		i = i * 2;
	for (auto i = 0; i < v.size(); ++i)
		v[i] = v[i] * 2;
	for (auto i = v.begin(); i != v.end(); ++i)
		*i = *i * 2;
}
void array_type(void)
{
	int a[20];
	int b[5][4];
	int i = 1, j = 0;
	for (auto p = begin(a); p != end(a); ++p)
		*p = i + j, i = j, j = *p;
	vector<int> v(begin(a), end(a));
	for (auto fibonacci : v)
		COUT_VAR(fibonacci);
	i = 0;
	for (auto &row : b)
		for (auto &col : row)
			COUT_VAR(col);
}
int main(void)
{
	array_type();
	return 0;
}
