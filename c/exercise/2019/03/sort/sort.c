#include <stdlib.h>
void swap(int v[], int i, int j);

int binsearch(int x, int v[], int n)
{
	int high, low, mid;
	int r;

	high = n;
	low = 0;
	while (low < high)
	{
		mid = low + (high - low) / 2;
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
void qksort2(int v[], int n)
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
	qksort2(v, last);
	qksort2(v + last + 1, n - last - 1);
}
void quicksort(int v[], int left, int right)
{
	int last, i;

	if (left >= right)
		return ;
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
void insort(int v[], int n)
{
	int i, j, temp;

	for (i = 1; i < n; ++i)
	{
		temp = v[i];
		for (j = i; j > 0 && temp < v[j - 1]; --j)
			v[j] = v[j - 1];
		v[j] = temp;
	}
}
static int get_max(int v[], int n)
{
	int max, i;

	max = v[0];
	for (i = 1; i < n; ++i)
		if (v[i] > max)
			max = v[i];
	return max;
}
static void radix_count(int v[], int n, int radix, int exp)
{
	int *data, *count, i, id;

	count = (int *) malloc(radix * sizeof(int));
	data = (int *) malloc(n * sizeof(int));
	if (count == NULL || data == NULL)
		return;
	for (i = 0; i < radix; ++i)
		count[i] = 0;
	for (i = 0; i < n; ++i)
		++count[(v[i] / exp) % radix];
	for (i = 1; i < radix; ++i)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; --i)
	{
		id = (v[i] / exp) % radix;
		data[count[id] - 1] = v[i];
		--count[id];
	}
	for (i = 0; i < n; ++i)
		v[i] = data[i];
	free(count);
	free(data);
}
void radix_sort(int v[], int n, int radix)
{
	long exp;
	int max = get_max(v, n);

	for (exp = 1; max / exp > 0; exp *= radix)
		radix_count(v, n, radix, exp);
}
void rdsort(int v[], int n)
{
	radix_sort(v, n, 2048);
}
static void heapify(int v[], int n, int head)
{
	int child, temp;

	for (temp = v[head]; 2 * head + 1 < n; head = child)
	{
		child = 2 * head + 1;
		if (child < n - 1 && v[child + 1] > v[child])
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
	for (i = n - 1; i >= 0; --i)
	{
		swap(v, 0, i);
		heapify(v, i, 0);
	}
}
