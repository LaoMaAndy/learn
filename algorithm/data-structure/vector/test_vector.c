/* test_vector.c */
#include "vector.h"

void test_vector()
{
	int v[] = {12, 43, -9, 1, 3, 0, 213};
	int n = sizeof(v) / sizeof(*v);
	vector *src, *dest;

	dest = MakeVector(v, n);
	printf("Dest Vector:\n");
	Print(dest);
	src = MakeN(20);
	printf("Src vector: \n");
	Print(src);
	VCopy(dest, src);
	printf("After VCopy\n");
	Print(dest);
	return ;
}
void test_cat()
{
	int v1[] = {12, 43, -9, 1, 3, 0, 213};
	int n1 = sizeof(v1) / sizeof(*v1);
	int v2[] = {1, 2, 3, 4, 5};
	int n2 = sizeof(v2) / sizeof(*v2);
	vector *src, *dest;

	src = MakeVector(v1, n1);
	dest = MakeVector(v2, n2);
	Print(src);
	Print(dest);
	printf("After VCat()\n");
	VCat(dest, src);
	Print(dest);

}
int main()
{
	test_vector();
	test_cat();
	return 0;
}