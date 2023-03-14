/* test_base_sort.c */
#include "head.h"
#define MASS_TEST_TIME (100 * 100 * 100 * 100 * 1)
#define LESS_TEST_TIME 50
#define LESS_TEST_REPEAT (100 * 100 * 100 * 1)
#define REGU_TEST_TIME 20

void swap(int v[], int i, int j);
void hpsort(int v[], int n);
void rdsort(int v[], int n);
void mgsort(int v[], int n);
void qksort(int v[], int n);
void qksort2(int v[], int n);
void shsort(int v[], int n);
void insort(int v[], int n);
void bbsort(int v[], int n);
int binsearch(int x, int v[], int n);
char *kmp_search(const char *dest, const char *sub);

void test_binsearch(void)
{
	int n = 100;
	int v[n];
	int i, r;

	for (i = 0; i < n; ++i)
		v[i] = 2 * i;
	for (i = 0; i < n; ++i)
	{
		r = binsearch(v[i], v, n);
		if (v[r] != v[i])
		{
			printf("Binsearch Error\n");
			return;
		}
	}
	printf("Binsearch OK\n");
}
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
void mass_sort(int n, void (*sort)(int *, int))
{
	int i;
	int *v;
	time_t start_t, end_t;
	double t;

	printf("\nMAX_INT:%10d, ", INT_MAX);
	printf("\nn  =   :%10d, ", n);

	v = (int *) malloc(n * sizeof(int));
	if (v == NULL)
	{
		printf("malloc() return NULL\n");
		return;
	}
	printf("Start...");
	fflush(stdout);
	for (i = 0; i < n; ++i)
		v[i] = rand() % INT_MAX;
	time(&start_t);
	sort(v, n);
	time(&end_t);
	printf("Finished.");
	test_sort_result(v, n);
	t = difftime(end_t, start_t);
	printf(" Time: %4.1f", t);
	printf("\n");
	free(v);
}
void less_sort(int n, int m, void (*sort)(int *, int))
{
	int i, j;
	int v[n];
	time_t start_t, end_t;
	double t = 0;

	printf("\tn:%4d, repeat: %4d ", n, m);
	printf("Start...");
	fflush(stdout);
	for (j = 0; j < LESS_TEST_REPEAT; ++j)
	{
		for (i = 0; i < n; ++i)
			v[i] = rand() % INT_MAX;
		time(&start_t);
		sort(v, n);
		time(&end_t);
		t += difftime(end_t, start_t);
	}
	printf("Finished.");
	test_sort_result(v, n);
	printf(" Time: %4.1f", t);
	printf("\n");
}
#define TEST_REGU_SORT(n, fun)  		do{printf(""#fun"(). ");regu_sort(n, fun);}while(0)
#define TEST_MASS_SORT(n, fun)  		do{printf(""#fun"(). ");mass_sort(n, fun);}while(0)
#define TEST_LESS_SORT(n, m, fun)  		do{printf(""#fun"(). ");less_sort(n, m, fun);}while(0)
void test_regu()
{
	int n = REGU_TEST_TIME;

	TEST_REGU_SORT(n, hpsort);
	// TEST_REGU_SORT(n, mgsort);
	TEST_REGU_SORT(n, qksort);
	TEST_REGU_SORT(n, qksort2);
	TEST_REGU_SORT(n, shsort);
	TEST_REGU_SORT(n, insort);
	TEST_REGU_SORT(n, bbsort);
	TEST_REGU_SORT(n, rdsort);
}
void test_mass()
{
	int n = MASS_TEST_TIME;

	// if (n <= 100 * 100 * 10)
	// 	TEST_MASS_SORT(n, bbsort);
	// if (n <= 100 * 100 * 30)
	// 	TEST_MASS_SORT(n, insort);
	// if (n <= 100 * 100 * 100 * 50)
	// 	TEST_MASS_SORT(n, shsort);
	// if (n <= 100 * 100 * 100 * 100 * 5)
	// {
	// 	TEST_MASS_SORT(n, rdsort);
	// 	TEST_MASS_SORT(n, qksort);
	// 	TEST_MASS_SORT(n, hpsort);
	// 	// TEST_MASS_SORT(n, mgsort);
	// }
	// if (n > 100 * 100 * 100 * 100 * 5)
	// 	printf("Amount is too much\n");
	TEST_MASS_SORT(n, rdsort);
}
//void less_sort(int n, int m, void (*sort)(int *, int))
void test_less()
{
	int n = LESS_TEST_TIME;
	int m = LESS_TEST_REPEAT;

	TEST_LESS_SORT(n, m, hpsort);
	// TEST_LESS_SORT(n, m, mgsort);
	TEST_LESS_SORT(n, m, qksort);
	TEST_LESS_SORT(n, m, qksort2);
	TEST_LESS_SORT(n, m, shsort);
	TEST_LESS_SORT(n, m, insort);
	TEST_LESS_SORT(n, m, rdsort);
	//TEST_LESS_SORT(n, m, bbsort);
}
int main()
{
	test_regu();
	//test_mass();
	//test_less();
	test_binsearch();
	return 0;
}
