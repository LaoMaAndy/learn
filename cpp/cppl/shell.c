#include <stdio.h>

void shellsort(int v[], int n)
{
	int gap, i, l, temp;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (l = i - gap; l >= 0 && v[l] > v[l + gap]; l -= gap)
			{
				temp = v[l];
				v[l] = v[l + gap];
				v[l + gap] = temp;
			}
}

int main(void)
{
	int v[] = {12, 10, 8, 6, 4, 2, 11, 9, 7, 5, 3, 1};
	int n = (sizeof(v) / sizeof(v[0]));
	int i;

	for (i = 0; i < n; ++i)
		printf("%d ", v[i]);
	printf("\n");

	shellsort(v, n);
	for (i = 0; i < n; ++i)
		printf("%d ",v[i]);
	printf("\n");

	return 0;
}
