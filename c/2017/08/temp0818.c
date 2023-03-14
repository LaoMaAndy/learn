/*
 * Comment: prototype
 */
#include <stdio.h>

void swap(int v[], int i, int j);
void quicksort(int v[], int left, int right);
void qksort(int v[], int n);
void shsort(int v[], int n);
void bbsort(int v[], int n);
void test(void (*foo)(int[], int));

#define TESTING(foo) printf("Testing function "#foo"\n");foo

/*
 * Comment: implementation
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
	for (i = left + 1; i <= right; i++)
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

void test(void(*foo)(int [], int))
{
	int v[] = {12, 10, 8, 6, 4, 2, 12, 0, 1, 3, 5, 7, 9, 11, 0};
	int n = sizeof(v) / sizeof(v[0]);
	int i;
	
	for (i = 0; i < n; i++)
		printf("%3d", v[i]);
	printf("\n");

	foo(v, n);

	for (i = 0; i < n; i++)
		printf("%3d", v[i]);
	printf("\n");
}

/*
 * Comment: main function
 */

int main(int argc, char *argv[])
{
	TESTING(test(shsort));
	TESTING(test(bbsort));
	TESTING(test(qksort));
	return 0;
}

