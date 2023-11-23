#include "head.h"

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
static void radix_count(int v[], int temp[], int count[], int n, int radix, int div)
{
	int i, id;

	for (i = 0; i < radix; ++i)
		count[i] = 0;
	for (i = 0; i < n; ++i)
		++count[v[i] / div % radix];
	for (i = 1; i < radix; ++i)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; --i)
	{
		id = (v[i] / div) % radix;
		temp[count[id] - 1] = v[i];
		--count[id];
	}
	for (i = 0; i < n; ++i)
		v[i] = temp[i];
}
void radix_sort(int v[], int n, int radix)
{
	long div;
	int max = get_max(v, n);
	int *count, *data;

	count = (int *) malloc(radix * sizeof(int));
	data = (int *) malloc(n * sizeof(int));
	if (count == NULL || data == NULL)
		return;
	for (div = 1; max / div > 0; div *= radix)
		radix_count(v, data, count, n, radix, div);
	free(count);
	free(data);
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
static void merge(int v[], int left, int mid, int right)
{
	int *temp;
	int i, j, k;

	temp = (int *) malloc((right - left + 1) * sizeof(int));

	i = left;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= right)
		if (v[i] < v[j])
			temp[k++] = v[i++];
		else
			temp[k++] = v[j++];
	while (i <= mid)
		temp[k++] = v[i++];
	while (j <= right)
		temp[k++] = v[j++];
	for (i = 0; i < k; ++i)
		v[left + i] = temp[i];
	free(temp);
}
void mergesort(int v[], int left, int right)
{
	int mid;

	if (left >= right)
		return;
	mid = (left + right) / 2;
	mergesort(v, left, mid);
	mergesort(v, mid + 1, right);
	merge(v, left, mid, right);
}
void mgsort(int v[], int n)
{
	mergesort(v, 0, n - 1);
}
void getlps(const char *pat, int *lps)
{
	int pat_len = strlen(pat);
	int i, j;

	lps[0] = 0;
	for (i = 1, j = 0; i < pat_len; )
	{
		if (pat[i] == pat[j])
		{
			++j;
			lps[i] = j;
			++i;
		}
		else if (j != 0)
			j = lps[j - 1];
		else 
		{
			lps[i] = 0;
			++i;
		}
	}
}
int kmp_search(const char *txt, const char *pat)
{
	int txt_len = strlen(txt);	
	int pat_len = strlen(pat);
	int t, p;
	int *lps;

	lps = (int *) malloc(pat_len * sizeof(int));
	if (lps == NULL)
	{
		printf("malloc() return NULL\n");
		exit(1);
	}
	getlps(pat, lps);
	t = p = 0;
	for (t = p = 0; t < txt_len && p < pat_len;  )
	{
		if (pat[p] == txt[t])
		{ 
			++p;
			++t;
		}
		else if (p != 0) 
			p = lps[p - 1]; 
		else 
			++t;
	}
	free(lps);
	if (p == pat_len)
		return t - p;
	return -1;
}
