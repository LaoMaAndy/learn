/*
 * prototype. 3 methods of sort. quick sort, shell sort, bubble sort
 * binsearch()
 */

void quicksort(int v[], int left, int right);
void qksort(int v[], int n);
void shsort(int v[], int n);
void bbsort(int v[], int n);
void swap(int v[], int n);
int binsearch(int x, int v[], int n);

/*
 * implementation
 */

void quicksort(int v[], int left, int right)
{
	int i, last;

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1, i <= right; i++)
		if (v[i] < v[left])
			swap(v[i], ++last, i);
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
		for (i = 0; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap])
				swap(v, j, j +gap);
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
		mid = (low + high ) / 2;
		if (v[mi] > x)
			high = mid - 1;
		else if (v[mid] < x)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}


