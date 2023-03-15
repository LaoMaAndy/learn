/* shellsort.c */
#include <stdio.h>

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void shellsort(int v[], int n)
{
	int i, j, gap;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}

void quicksort(int v[], int left, int right)
{
	int last, i;

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; ++i)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	quicksort(v, left, last - 1);
	quicksort(v, last + 1, right);
}

void qksort(int v[], int n)
{
	quicksort(v, 0, n - 1);
}

int binsearch(int x, int v[], int n)
{
	int high, low, mid;
	int r;

	high = n;
	low = 0;
	while(low < high)
	{
		mid = (high + low) / 2;
		r = mid - x;
		if (r > 0)
			high = mid;
		else if (r < 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}


void test(void s(int [], int))
{
	int v[] = {1, 3, 5, 7, 9, 11, 12, 10, 8, 6, 4, 2, 0, 13};
	int n = sizeof(v) / sizeof(*v);
	int i, j;

	printf("Original data: \n");
	for (i = 0; i < n; ++i)
		printf("%d\t", v[i]);
	printf("\n");
	s(v, n);
	printf("after sort: \n");
	for (i = 0; i < n; ++i)
		printf("%d\t", v[i]);
	printf("\n");
	for (i = 0; i < n; ++i)
	{
		j = binsearch(v[i], v, n);
		if (j == -1 || v[i] != v[j])
			printf("search algorithm error:");
	}
	printf("bin search OK\n");

}

#define TEST(a) {printf("testing function: "#a"\n");test(a);}
int main()
{
	//test(shellsort);
	//test(qksort);
	TEST(shellsort);
	TEST(qksort);
	return 0;
}
