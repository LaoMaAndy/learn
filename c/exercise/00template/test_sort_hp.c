/* test_base_sort.c */
#include "head.h"
#define REGU_TEST_TIME 200

void swap(int v[], int i, int j);
void hpsort(int v[], int n);
void rdsort(int v[], int n);
void mgsort(int v[], int n);
void qksort(int v[], int n);
void shsort(int v[], int n);
void insort(int v[], int n);
void bbsort(int v[], int n);

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void test_sort_result(int v[], int n)
{
	int i;

	printf(" Result");
	for (i = 0; i < n - 1; ++i)
		if (v[i] > v[i + 1])
		{
			printf("..Error.");
			return;
		}
	printf("..OK.");
}
void regu_sort(int n, void (*sort)(int [], int))
{
	int v[n];
	int i;

	for (i = 0; i < n; ++i)
		v[i] = rand() % 100;
	printf("\tTotal:%4d", n);
	sort(v, n);
	test_sort_result(v, n);
	printf("\n");
}
#define TEST_REGU_SORT(n, fun)  		do{printf(""#fun"(). ");regu_sort(n, fun);}while(0)
void test_regu()
{
	int n = REGU_TEST_TIME;

	TEST_REGU_SORT(n, qksort);
	TEST_REGU_SORT(n, shsort);
	TEST_REGU_SORT(n, insort);
	TEST_REGU_SORT(n, bbsort);
	TEST_REGU_SORT(n, rdsort);
	TEST_REGU_SORT(n, hpsort);
}


int main()
{
	test_regu();
	return 0;
}
