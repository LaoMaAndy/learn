/*
function: var_type, string_type, vector_type, array_type
*/
#include "0head.cpp"

void var_type(void)
{
	int a = 10;
	int &b = a;
	int *c = &a;
	const int d = 20;
	const int &e = d;
	const int *f = &a;
	const int * const g = &d;
	constexpr int h = *g * 20;
}

int main(void)
{
	var_type();
	return 0;
}


