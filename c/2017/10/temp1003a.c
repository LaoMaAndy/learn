/*
 Prototype. sort. search
 */

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
	for(i = left + 1; i < right; i++)
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
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}

void bbsort(int v[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (v[mid] > x)
			high = mid - 1;
		else if (v[mid] < x)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int bins2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (v[mid] > x)
			high = mid;
		else if (v[mid] < x)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}


/* 
 * test these functions
 */
#include <stdio.h>

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
	printf("binsearch(11, v, n): %3d\n", binsearch(11, v, n));
	printf("binsearch2(0, v, n): %3d\n", binsearch(0, v, n));
	printf("binsearch2(13, v, n): %3d\n", binsearch(13, v, n));
}

/*
 * Main function
 */
#define PRN_FUN(fun) printf("Testing function: "#fun"\n");fun

int main(int argc, char *argv[])
{
	PRN_FUN(test(qksort));
	PRN_FUN(test(shsort));
	PRN_FUN(test(bbsort));

	return 0;
}



