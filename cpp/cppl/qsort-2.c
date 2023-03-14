#include <stdio.h>

void quicksort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

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

void quicksort_v2(int v[], int left, int right)
{
	void swap(int v[], int i, int j);
	int last, i;

	if (left >= right)
		return;
	
	for (last = left, i = right; i > last; )
		if (v[i] >= v[left])
			i--;
		else if (v[last] <= v[left])
			last++;
		else
			swap(v, last, i);
			
	swap(v, left, last);

	quicksort_v2(v, left, last - 1);
	quicksort_v2(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
	int temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int main(int argc, char *argv[])
{
	int v[] = {12, 14, 11, 13, 10, 8, 6, 13, 14, 7, 10, 12, 8, 9, 1 , 4, 2, 1, 3, 5, 7, 9};
	int left = 0;
	int right = sizeof(v) / sizeof(v[0]) - 1;
	int i;

	printf("Befort sort: \n");
	for (i = 0; i <= right; i++)
		printf(" %3d", v[i]);
	printf("\n");
	
	//quicksort(v, left, right);
	quicksort_v2(v, left, right);

	printf("After sort: \n");
	for (i = 0; i <= right; i++)
		printf(" %3d", v[i]);
	printf("\n");
}
	
