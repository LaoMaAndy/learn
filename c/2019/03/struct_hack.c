/* struct hack */
#include <stdio.h>
#include <stdlib.h>

struct elem
{
	int id, val;
};
typedef struct elem elem;
struct vector
{
	size_t size;
	elem data[0];
};
typedef struct vector vector;

vector *Make(int n)
{
	vector *p;

	p = (vector *) malloc(sizeof(vector) + n * sizeof(elem));
	return p;
}
void test_vector()
{
	vector *p = Make(100);
	int i;
}

int main()
{

	test_vector();
	return 0;
}
