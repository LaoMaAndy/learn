
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
}

void bubblesort(int v[], int n)
{
	int i, j, temp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1])
			{
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
}

#include <stdio.h>

int main(int argc, int argv[])
{
	int v[] = {17, 12, 20, 0, 12, 10, 8, 6, 4, 2, 0, 1, 3, 5, 7, 9, 11};
	int n = sizeof(v) / sizeof(v[0]);
	int i;

	printf("\nBefore sort: ");
	for (i = 0; i < n; i++)
		printf(" %d", v[i]);

	//bubblesort(v, n);
	shellsort(v, n);

	printf("\nAfter sort:  ");
	for (i = 0; i < n; i++)
		printf(" %d", v[i]);

	printf("\n");
	return 0;
}

