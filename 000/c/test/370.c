/* 370.c */
#include <stdio.h>

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
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
void qksort2(int v[], int n)
{
	int last, i;

	if (n <= 1)
		return;
	swap(v, 0, n / 2);
	last = 0;
	for (i = 1; i < n; ++i)
		if (v[i] < v[0])
			swap(v, ++last, i);
	swap(v, last, 0);
	qksort2(v, last);
	qksort(v + last + 1, n - last - 1);
}
void shsort(int v[], int n)
{
	int gap, i, j;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}
void bbsort(int v[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; ++i)
		for (j = 0; j < n - i - 1; ++j)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
}

void test_sort(void (*sort)(int [], int))
{
	int v[] = {1, 3, 5, 7, 9, 11, 10, 8, 6, 4, 2, 10, 0, 20, 30};
	int n = sizeof(v) / sizeof(*v);
	int i, j;

	printf("Sort:\n");
	for (i = 0; i < n; ++i)
		printf("%d  ", v[i]);
	sort(v, n);
	printf("\n");
	for (i = 0; i < n; ++i)
		printf("%d  ", v[i]);
	printf("\n");
}
int main()
{
	test_sort(qksort);
	test_sort(qksort2);
	test_sort(shsort);
	test_sort(bbsort);

	return 0;
}


		
