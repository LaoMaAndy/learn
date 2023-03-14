void qksort(int v[], int left, int right)
{
	void swap(int v[], int i, int j);
	int i, last;

	if (left >= right)
		return ;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left; i <= right; i++)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	qksort(v, left, last - 1);
	qksort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void shsort(int v[], int n)
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

void bbsort(int v[], int n)
{
	int i, j, temp;

	for (i = 0; i < n; i++)
		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1])
			{
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
}
#include <stdio.h>
int main(int argc, char * argvv[])
{
	int v[] = {12, 10, 8, 6, 4, 2, 12, 0, 1, 3, 5, 7, 1, 9};
	int n = sizeof(v) / sizeof(v[0]);
	int i;

	for (i = 0; i < n; i++)
		printf("%3d", v[i]);
	printf("\n");

	//qksort(v, 0, n - 1);
	//shsort(v, n);
	bbsort(v, n);

	for (i = 0; i < n; i++)
		printf("%3d", v[i]);
	printf("\n");

	return 0;
}

