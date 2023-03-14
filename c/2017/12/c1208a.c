/*
function: swap, sort, search
*/
#define NEED_FILE
#include "0head.c"

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void quicksort(int v[], int left, int right)
{
	int i, last;

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
	int i, last;
	
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
void shsort(int v[], int n)
{
	int gap, i, j;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (j = i - gap; j >= 0 && v[i] > v[j + gap]; j -= gap)
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
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	int r;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		r = v[mid] - x;
		if (r > 0)
			high = mid - 1;
		else if (r < 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
int bins2(int x, int v[], int n)
{
	int low, high, mid;
	int r;

	low = 0;
	high = n;
	while (low < high)
	{
		mid  = low + (high - low) / 2;
		r = v[mid] - x;
		if (r > 0)
			high = mid;
		else if (r < 0)
			low = mid = 1;
		else
			return mid;
	}
	return -1;
}

void test(void (*sort)(int [], int))
{
	int v[] = {12, 10, 8, 6, 4, 2, 0, 1, 3, 5, 7, 9, 11, 13};
	int n = sizeof(v) / sizeof(v[0]);
	int i;

	for (i = 0; i < n; i++)
		printf("%3d", v[i]);
	printf("\n");

	sort(v, n);

	for (i = 0; i < n; i++)
		printf("%3d", v[i]);
	printf("\n");
	printf("binsearch(0, v, n): %3d\n", binsearch(0, v, n));
	printf("binsearch(11, v, n): %3d\n", binsearch(11, v, n));
	printf("binsearch2(0, v, n): %3d\n", binsearch(0, v, n));
	printf("binsearch2(13, v, n): %3d\n", binsearch(13, v, n));
	printf("binsearch2(7, v, n): %3d\n", binsearch(7, v, n));
}



/*
 * Main function
 */

int main(int argc, char *argv[])
{
	PRN_CAL(test(qksort));
	PRN_CAL(test(shsort));
	PRN_CAL(test(bbsort));
	PRN_CAL(test(qksort2));

	return 0;
}
