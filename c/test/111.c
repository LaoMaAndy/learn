/* 111.c */
#include <unistd.h>
#include <stdio.h>

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
// comment:
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
//comment:
void qksort(int v[], int n)
{
	quicksort(v, 0, n - 1);
}
//comment:
void shsort(int v[], int n)
{
	int gap, i, j;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}
//comment:
void bbsort(int v[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; ++i)
		for(j = 0; j < n - i - 1; ++j)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
}
//comment:
int binsearch(int x, int v[], int n)
{
	int high, low, mid;
	int r;

	high = n;
	low = 0;
	while (low < high)
	{
		mid = (low + high) / 2;
		r = v[mid] - x;
		if (r > 0)
			high = mid;
		else if (r < 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}


void foo() 
{
	write(1, "hello, world\n", 13);
	_exit(0);
}
void test_sort(void sort(int[], int))
{
	int v[] = {1, 3, 5, 7, 9, 10, 8, 6, 4, 2, 11, 0, 20};
	int n = sizeof(v) / sizeof(*v);
	int i, j;

	printf("test sort: \n");
	for (i = 0; i < n; ++i)
		printf("%d  ", v[i]);
	printf("\n");
	sort(v, n);
	for (i = 0; i < n; ++i)
		printf("%d  ", v[i]);
	printf("\n");
}
int main()
{
	test_sort(qksort);
	test_sort(shsort);
	test_sort(bbsort);

	return 0;
}

	
