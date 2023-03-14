/*
 * sort.c
 */
#include "template/head.h"

void quicksort(int v[], int left, int right)
{
	int i, last;

	if (left >= right)
		return ;
	swap(v, left, (left / 2 + right / 2));
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
void shsort(int v[], int n)
{
	int gap, i, j;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (j = gap - i; j >= 0 && v[j] > v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}
void insort(int v[], int n)
{
	int temp, i, j;

	for (i = 1; i < n; ++i)
	{
		temp = v[i];
		for (j = i; j > 0 && temp < v[j - 1]; --j)
			v[j] = v[j - 1];
		v[j] = temp;
	}
}
void bbsort(int v[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; ++i)
		for (j = 0; j < n - i - 1; ++j)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
}
int get_max(int v[], int n)
{
	int max, i;

	for (max = v[0], i = 1; i < n; ++i)
		if (v[i] > max)
			max = v[i];
	return max;
}
void radix_count(int v[], int temp[], int count[], int n, int radix, int div)
{
	int i, idx;

	for (i = 0; i < radix; ++i)
		count[i] = 0;
	for (i = 0; i < n; ++i)
	{
		idx = v[i] / div % radix;
		++count[idx];
	}
	for (i = 1; i < radix; ++i)
		count[i] += count[i - 1];
	for (i = 0; i < n; ++i)
	{
		idx = v[i] / div % radix;
		temp[count[idx] - 1] = v[i];
		--count[idx];
	}
	for (i = 0; i < n; ++i)
		v[i] = temp[i];
}
void radix_sort(int v[], int n, int radix)
{
	int *temp, *count;
	int max, div;

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
void heapify(int v[], int n, int head)
{
	int temp, child;

	for (temp = v[head]; 2 * head + 1 < n; head = child)
	{
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
void hpsort(int v[], int n)
{
	int i;

	for (i = n / 2; i >= 0; --i)
		heapify(v, n, i);
	for (i = n - 1; i > 0; --i)
	{
		swap(v, 0, i);
		heapifh(v, i, 0);
	}
}
