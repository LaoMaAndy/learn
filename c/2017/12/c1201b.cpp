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
	const int *f = &e;
	const int &g = e;
	const int *&h = f;
	const int * const i = &a;
	constexpr int j = e * 3;
	typedef int k[10];
	typedef int *l[10];
	typedef int (*m)[10];
	typedef int n(int);
	typedef int (*o)(int);
	typedef int *p(int);
	typedef int *(*q[10])(int); 
	typedef int *(*((*r)[10]))(int);
	using s = vector<q>;
	using t = s*;
	s u;
	t v = &u;
	auto w = u.begin();
	auto x = v->end();
	decltype(*v) y = u;
	decltype((v)) z = v;
	void (*Signal(int sig, void *handler(int)))(int);	
}
void string_type(void)
{
	string s("12354");
	string t("afdjks");
	string r;
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
	vector<int> v2{10};
	vector<int> v3{10, 2};
	vector<int> v4 = {10, 2};
	auto p = &v;
	ptrdiff_t d = p->end() - p->begin();
	auto n1 = v.size(); auto n2 = v.end() - v.begin();
	auto n3 = p->size();
	auto n4 = (*p).size();
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
	for (auto fibonacci : v)
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

