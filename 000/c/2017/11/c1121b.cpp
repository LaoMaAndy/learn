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
	const int e = 30;
	const int &f = e;
	const int *g = &a;
	const int * const h = &a;
	constexpr int i = e;
	typedef int j[10];
	typedef int *k[10];
	typedef int (*l)[10];
	typedef int m(int);
	typedef int (*n)(int);
	typedef int (*o[10])(int);
}
