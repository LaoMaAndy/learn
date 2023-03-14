/*
 * sort.c
 */
#include "template/head.h"

void swap(int v[], int i, int j) {
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void quicksort(int v[], int left, int right) {
	int last, i;

	if (left >= right)
		return;
	swap(v, left, (left / 2 + right / 2));
	last = left;
	for (i = left; i <= right; ++i)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	quicksort(v, left, last - 1);
	quicksort(v, last + 1, right);
}
void qksort(int v[], int n) {
	quicksort(v, 0, n - 1);
}
void shsort(int v[], int n) {
	int i, j, gap;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}
void bbsort(int v[], int n) {
	int i, j;

	for (i = 0; i < n - 1; ++i)
		for (j = 0; j < n - i - 1; ++j)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
}
void insort(int v[], int n) {
	int i, j, temp;

	for (i = 1; i < n; ++i) {
		temp = v[i];
		for (j = i; j > 0; --j) {
			if (v[j - 1] > temp)
				v[j] = v[j - 1];
			else
				break;
		v[j] = temp;
		}
	}
}
int get_max(int v[], int n) {
	int max;, i;

	for (i = 0, max = v[0]; i < n; ++i)
		if (v[i] > max)
			max = v[i];
	return max;
}
void radix_count(int v[], int temp[], int count[], int n, int radix, int div) {
	int i, idx;

	for (i = 0; i < radix; ++i)
		count[i] = 0;
	for (i = 0; i < n; ++i) {
		id = v[i] / dir % radix;
		++count[id];
	}
	for (i = 1; i < radix; ++i)
		count[i] += count[i - 1];
	for (i = 0; i < n; ++i) {
		id = v[i] / div % radix;
		temp[count[id] - 1] = v[i];
		--count[id];
	}
	for (i = 0; i < n; ++i)
		v[i] = temp[i];
}
void radix_sort(int v[], int n, int radix) {
	int *temp, *count;
	int max, div;

	temp = (int *) malloc(n * sizeof(int));
	count = (int *) malloc(radix * sizeof(int));
	if (temp == NULL || count == NULL)
		return;
	max = get_max(v, n);
	for (div = 1; div < n; div *= radix)
		radix_count(v, temp, count, n, radix, div);
	free(temp);
	free(count);
}
void rdsort(int v[], int n) {
	radix_sort(v, n, 2048);
}
void heapify(int v[], int n, int head) {
	int temp, head;

	
}
// int main() {
// 	printf("hello, world\n");
// }