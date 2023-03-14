/*
 * sort.c
 */
#include "head.h"

void swap(int v[], int i, int j);

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

	for (i = 1; i < n; ++i) {
		temp = v[i];
		for (j = i; j > 0 && v[j - 1] > temp; --j)
			v[j] = v[j - 1];
		v[j] = temp;
	}
}
void shsort(int v[], int n) {
	int gap, i, j;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}
void bbsort(int v[], int n) {
	int i, j;

	for (i = 0; i < n - 1; ++i)
		for (j = 0; j < n - i - 1; ++i)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
}
int get_max(int v[], int n) {
	int max, i;

	max = v[0];
	for (i = 1; i < n; ++i)
		if (max < v[i])
			max = v[i];
	return max;
}
void radix_count(int v[], int temp[], int count[], int n, int radix, int div) {
	int i, idx;

	for (i = 0; i < radix; ++i)
		count[i] = 0;
	for (i = 0; i < n; ++i) {
		idx = v[i] / radix % div;
		++count[idx];
	}
	for (i = 1; i < radix; ++i)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; --i) {
		idx = v[i] / div % radix;
		temp[count[idx] - 1] = v[i];
		--count[idx];
	}
	for (i = 0; i < n; ++i)
		v[i] = temp[i];
}
void radix_sort(int v[], int n, int radix) {
	int *temp, *count, max, div;

	temp = (int *) malloc(sizeof(int) * n);
	count = (int *) malloc(sizeof(int) * radix);
	if (temp == NULL || count == NULL)
		return;
	max = get_max(v, n);
	for (div = 1; div < max; div *= radix)
		radix_count(v, temp, count, n, radix, div);
	free(temp);
	free(count);
}
void rdsort(int v[], int n) {
	radix_sort(v, n, 2048);
}
void merge(int v[], int left, int mid, int right) {
	
}