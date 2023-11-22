#include "head.h"
#define TEST(a) {printf("testing function: "#a"\n");test(a);}

extern void quicksort(int v[], int left, int right);
extern void qksort(int v[], int n);
extern void qksort2(int v[], int n);
extern void shsort(int v[], int n);
extern void bbsort(int v[], int n);
extern int binsearch(int x, int v[], int n);
extern int bins2(int x, int v[], int n);

void test(void s(int [], int))
{
	int v[] = {1, 3, 5, 7, 9, 11, 12, 10, 8, 6, 4, 2, 0, 13, 20, 30};
	int n = sizeof(v) / sizeof(*v);
	int i, j;

	printf("Original data: \n");
	for (i = 0; i < n; ++i)
		printf("%d  ", v[i]);
	printf("\n");
	s(v, n);
	printf("after sort: \n");
	for (i = 0; i < n; ++i)
		printf("%d  ", v[i]);
	printf("\n");
	for (i = 0; i < n; ++i)
	{
		j = binsearch(v[i], v, n);
		if (j == -1 || v[i] != v[j])
		{
			printf("search algorithm error:\n");
			break;
		}
	}
	printf("bin search OK\n");
	printf("==============\n");

}

int main()
{
	TEST(qksort);
	TEST(qksort2);
	TEST(shsort);
	TEST(bbsort);

	return 0;
}
