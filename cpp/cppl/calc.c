#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	double n, r;

	printf("Please input the ratio:");
	scanf("%lf", &r);

	for (i = 0, n = 1; i < 100; i++, n *=  (1 - r))
		printf("%3d : %5.3f\n", i, n);
}

void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n ; i++)
			for (j = i - gap; j >= 0 && v[i] > v[i + gap]; j -= gap);
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

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mi])
			high = mid - 1;
		else if (x > m[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int my_strlen(char s[])
{
	int i;

	for (i = 0 ; s[i] != '\0'; i++)
		;
	return i;
}

void reverse(char s[])
{
	int i, j, temp;

	for (i = 0, j = strlen(s); i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void qsort(char *v[], int left, int right)
{
	int i, last;

	if  (left >= right)
		return ;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}







