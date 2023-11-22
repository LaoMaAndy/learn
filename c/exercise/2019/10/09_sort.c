/* 
 * sort.c
 */
#include "../../c/head.h"

/*
int main() {
	printf("It's ok\n");
	return 0;
}
*/
void swap(int v[], int i, int j);
void quicksort(int v[], int left, int right) {
	int last, i;

	if (left >= right)
		return;
	swap(v, left, (left / 2 + right /2 ));
	last = left;
	for (i = left + 1; i <= right; ++i)
		if (v[left] < v[i])
			swap(v, ++last, i);
	swap(v, left, last);
	quicksort(v, left, last - 1);
	quicksort(v, last + 1, right);
}
void qksort(int v[], int n) {
	quicksort(v, 0, n - 1);
}
void insort(int v[], int n) {
	int i, j, temp;

	for (i = 1; i < n; ++i) {
		temp = v[i];
		for (j = i; j > 0 && temp < v[j - 1]; --j)
			v[j] = v[j - 1];
		v[j] = temp;
	}
}
void shsort(int v[], int n) {
	int gap, i, j;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (j = i - gap; j >= 0 && v[j] >v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}
int get_max(int v[], int n) {
	int max, i;

	for (max = v[0], i = 0; i < n; ++i)
		if (v[i] > max)
			max = v[i];
	return max;
}
void radix_count(int v[], int temp[], int count[], int n, int radix, int div) {
	int i, idx;

	for (i = 0; i < radix; ++i)
		count[i] = 0;
	for (i = 0; i < n; ++i) {
		idx = v[i] / div % radix;
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
	int *temp, *count;
	int max, div;

	temp = (int *) malloc(n * sizeof(int));
	count =(int *) malloc(radix * sizeof(int));
	if (temp == NULL || count == NULL)
		return;
	max = get_max(v, n);
	for (div = 1; max / div > 0; div *= radix)
		radix_count(v, temp, count, n, radix, div);
	free(temp);
	free(count);
}
void rdsort(int v[], int n) {
	radix_sort(v, n, 2048);
}
void heapfy(int v[], int n, int head) {
	int temp, child;
	
	for (temp = v[head]; head * 2 + 1 < n; child = head) {
		child = head * 2 + 1;
		if (child + 1 < n && v[child] < v[child + 1])
			++child;
		if (temp < v[child])
			v[head] = v[child];
		else
			break;
	}
	v[head] = temp;
}
void hpsort(int v[], int n) {
	int i;

	for (i = n / 2; i >= 0; --i)
		heapfy(v, n, i);
	for (i = n - 1; i > 0; --i) {
		swap(v, 0, i);
		heapfy(v, i, 0);
	} 
}
void merge(int v[], int left, int mid, int right) {
	int *temp;
	int i, j, k;

	temp = (int *) malloc(sizeof(int) * (right - left + 1));
	if (temp == NULL)
		return;
	i = left;
	j = mid + 1;
	k = 0;
}
