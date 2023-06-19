/*
 * sort.c 
 */
#include "template/head.h"

void quicksort(int v[], int left, int right) {
	int last, i;

	if (left >= right)
		return;
	swap(v, left, (left / 2 + right / 2));
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
void shsort(int v[], int n) {
	int gap, i, j;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}
void insort(int v[], int n) {
	int temp, i, j;

	for (i = 1; i < n; ++i) {
		temp = v[i];
		for (j = i; j > 0; --j)
			if (v[j - 1] > temp)
				v[j] = v[j - 1];
			else
				break;
		v[j] = temp;
	}
}
void bbsort(int v[], int n) {
	int i, j;

	for (i = 0; i < n - 1; ++i)
		for (j = 0; j < n - i - 1; ++j)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
}
int get_max(int v[], int n) {
	int i, max;

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
		idx = v[i] / div % radix;
		++count[idx];
	}
	for (i = 1; i < radix; ++i)
		count[i] += count[i - 1];
	for (i = 0; i < n; ++i) {
		idx = v[i] / div % radix;
		temp[count[idx] - 1] = v[i];
		--count[idx];
	}
	for (i = 0; i < n; ++i)
		v[i] = temp[i];
}
void radix_sort(int v[], int n, int radix) {
	int div, max;
	int *temp, *count;

	temp = (int *) malloc(n * sizeof(int));
	count = (int *) malloc(radix * sizeof(int));
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
void heapify(int v[], int n, int head) {
	int temp, child;

	for (temp = v[head]; head * 2 + 1 < n; head = child) {
		child = head * 2 + 1;
		if (child + 1 < n && v[child + 1] > v[child])
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
		heapify(v, n, i);
	for (i = n - 1; i >= 0; --i) {
		swap (v, 0, i);
		heapify(v, i, 0);
	}
}
void merge(int v[], int left, int mid, int right) {
	int *temp, i, j, k;

	temp = (int *) malloc((right - left + 1) * sizeof(int));
	if (temp == NULL)
		return;
	i = left;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= right)
		temp[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
	while (i <= mid)
		temp[k++] = v[i++];
	while (j <= right)
		temp[k++] = v[j++];
	for (i = 0; i < k; ++i)
		v[left + i] = temp[i];
	free(temp);
}
void merge_sort(int v[], int left, int right) {
	int mid;

	if (left >= right)
		return;
	mid = left / 2 + right / 2;
	merge_sort(v, left, mid);
	merge_sort(v, mid + 1, right);
	merge(v, left, mid, right);
}
void mgsort(int v[], int n) {
	merge_sort(v, 0, n - 1);
}
void getlps(const char *s, int *p) {
	int len, i, j;

	len = strlen(s);
	p[0] = 0;
	for (i = 1, j = 0; i < len; ) {
		if (s[i] == s[j]) {
			++j;
			p[i] = j;
			++i;
		}
		else if (j != 0)
			j = p[j - 1];
		else {
			p[i] = 0;
			++i;
		}
	}
}
int kmp_search(const char *dest, const char *sub) {
	int d_len, s_len, d, s, *lps;

	d_len = strlen(dest);
	s_len = strlen(sub);
	lps = (int *) malloc(s_len * sizeof(int));
	if (lps == NULL)
		return -1;
	getlps(sub, lps);
	for (d = s = 0; d < d_len && s < s_len; ) {
		if (dest[d] == sub[s]) {
			++d;
			++s;
		}
		else if (s != 0)
			s = lps[s - 1];
		else
			++d;
	}
	free(lps);
	return (s == s_len) ? (d - s) : -1;
}
