/* test_base_sort.c */
#include "head.h"

int Base(int val, int base, int n);
void rdsort(int v[], int n, int radix);

static void prn_node(int *v, int  *next, int *prev, int *val, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		printf("node[%3d] next: %3d, Prev: %3d, Val: %3d --> %3d\n", i, next[i], prev[i], val[i], v[i]);
}
static void prn_bucket(int *b, int n)
{
	int j;
	char c;

	for (j = 0; j < n; ++j)
	{
		c = (j % 4 == 3) ? '\n' : ' ';
		printf("bucket[%3d] start:%3d \n", j, b[j]);
	}
	printf("\n");
}
void test_result(int v[], int n)
{
	int i;

	printf("..Test sort result");
	fflush(stdout);
	for (i = 0; i < n - 1; ++i)
		if (v[i] > v[i + 1])
		{
			printf("\t---- Error\n");
			return;
		}
	printf("---- OK\n");

}
void test_rsort(int v[], int n, int base)
{
	int i;

	printf("Before sort: ");
	for (i = 0; i < n; ++i)
		printf("%5d", v[i]);
	printf("\n");
	rdsort(v, n, base);
	printf("After  sort: ");
	for (i = 0; i < n; ++i)
		printf("%5d", v[i]);
	//printf("\n");
	for (i = 0; i < n - 1; ++i)
		if (v[i] > v[i + 1])
		{
			printf("---- Error\n");
			return;
		}
	printf("---- OK\n");
}
void test_rdsort(int v[], int n, int base)
{
	int i;

	printf("Before sort: ");
	for (i = 0; i < n; ++i)
		printf("%5d", v[i]);
	printf("\n");
	rdsort(v, n, base);
	printf("After  sort: ");
	for (i = 0; i < n; ++i)
		printf("%5d", v[i]);
	//printf("\n");
	for (i = 0; i < n - 1; ++i)
		if (v[i] > v[i + 1])
		{
			printf("---- Error\n");
			return;
		}
	printf("---- OK\n");
}
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void bbsort(int v[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; ++i)
		for (j = 0; j < n - i - 1; ++j)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
}
void Qksort(int v[], int n)
{
	int last, i;

	if (n <= 1)
		return;
	swap(v, 0, rand() % n);
	last = 0;
	for (i = 1; i < n; ++i)
		if (v[i] < v[0])
			swap(v, ++last, i);
	swap(v, 0, last);
	Qksort(v, last);
	Qksort(v + last + 1, n - last - 1);
}
void shsort(int v[], int n)
{
	int gap, i, j;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = 0; i < n; ++i)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}
void sort_bb(int *v, int n)
{
	time_t start_t, end_t;
	double t;

	printf("bubble sort");
	fflush(stdout);
	time(&start_t);
	bbsort(v, n);
	time(&end_t);
	printf("...OK  ");
	test_result(v, n);
	t = difftime(end_t, start_t);
	printf("********Timer: %4.1f\n", t);

}
void sort_shell(int *v, int n)
{
	time_t start_t, end_t;
	double t;

	printf("shell sort");
	fflush(stdout);
	time(&start_t);
	shsort(v, n);
	time(&end_t);
	printf("...OK  ");
	test_result(v, n);
	t = difftime(end_t, start_t);
	printf("********Timer: %4.1f\n", t);

}
void sort_quick(int *v, int n)
{
	time_t start_t, end_t;
	double t;

	printf("quick sort");
	fflush(stdout);
	time(&start_t);
	Qksort(v, n);
	time(&end_t);
	printf("...OK  ");
	test_result(v, n);
	t = difftime(end_t, start_t);
	printf("********Timer: %4.1f\n", t);

}
void sort_radix(int *v, int n, int bucket)
{
	time_t start_t, end_t;
	double t;

	printf("radix sort");
	fflush(stdout);
	time(&start_t);
	rdsort(v, n, bucket);
	time(&end_t);
	printf("...OK  ");
	test_result(v, n);
	t = difftime(end_t, start_t);
	printf("********Timer: %4.1f\n", t);
}
void Compare()
{
	int *v;
	int n = 100 * 100 * 100 * 30;
	//int n = 100 * 100 * 100 * 100 * 10;
	//int n = 2147483646;
	int i;

	printf("MAX_INT: %10d\n", INT_MAX);
	printf("n =    : %10d\n", n);

	v = (int *) malloc(n * sizeof(int));
	if (v == NULL)
	{
		printf("malloc() return NULL\n");
		return;
	}
	if (n <= 100 * 100 * 10)
	{
		printf("Alloc int arrays.\n");
		for (i = 0; i < n; ++i)
			v[i] = rand() % n;
		printf("Starting sort.. ");
		sort_bb(v, n);
	}

	printf("Alloc int arrays.\n");
	for (i = 0; i < n; ++i)
		v[i] = rand() % n;
	printf("Starting sort.. ");
	sort_shell(v, n);

	printf("Alloc int arrays.\n");
	for (i = 0; i < n; ++i)
		v[i] = rand() % n;
	printf("Starting sort.. ");
	sort_quick(v, n);

	printf("Alloc int arrays.\n");
	for (i = 0; i < n; ++i)
		v[i] = rand() % n;
	printf("Starting sort.. ");
	sort_radix(v, n, 1000);
	free(v);
}
int main()
{
	int v1[] = {64,8, 216, 512, 27, 729, 0, 1, 343, 125};
	int v2[] = {1, 21, 31, 41, 51, 61, 71, 8, 9, 10};
	int v3[] = {9, 8, 7, 6, 11, 21, 31, 10, 100, 12};
	int v4[] = {9, 7, 7, 6, 6, 1, 5, 4, 0, 3};
	int v5[] = {99, 11, 7, 6, 22, 10, 12, 98, 0, 3, 55, 56, 77, 32, 23};
	int n1 = sizeof(v1) / sizeof(*v1);
	int n2 = sizeof(v2) / sizeof(*v2);
	int n3 = sizeof(v3) / sizeof(*v3);
	int n4 = sizeof(v4) / sizeof(*v4);
	int n5 = sizeof(v5) / sizeof(*v5);

	test_rdsort(v1, n1, 5);
	test_rdsort(v2, n2, 10);
	test_rdsort(v3, n3, 8);
	test_rdsort(v4, n4, 15);
	test_rdsort(v5, n5, 20);

	Compare();
	return 0;
}
