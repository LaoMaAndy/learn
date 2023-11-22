/*
 * binsearch()
 */

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


#include <stdio.h>
int main(void)
{
	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(v) / sizeof(v[0]);

	printf("binsearch(4, v, n): %d\n", binsearch(4, v, n));
	printf("bin(5, v, n): %d\n", binsearch(5, v, n));
	printf("bin(0, v, n): %d\n", binsearch(0, v, n));
	printf("bin(10, v, n): %d\n", binsearch(10, v, n));

	return 0;
}

