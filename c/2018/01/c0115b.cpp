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
	const int * const h = &a;
	const int * const &i = f;
	constexpr int j = e * 2;
	typedef int k[20];
	typedef int *l[20];
}
