/*
 * sort.c
 */
#include "head.h"

void quicksort(int v[], int left, int right) {
	int last, i;

	if (left >= right)
		return;
	swap(v, left, left / 2 + right / 2);
	last = left;	
	for (i = left + 1; i <= right; ++i)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	quicksort(v, left, last - 1);
	quicksort(v, last + 1, right);
}
void qksort(int v[], int n) {
	quicksort(v, 0, n - 1);
}
void insort(int v[], int n) {
	int temp, i, j;

	for (i = 1; i < n; ++i)
	{
		temp = v[i];
		for (j = i; j > 0 && v[j - 1] > temp; --j)
			v[j] = v[j - 1];
		v[j] = temp;
	}
}