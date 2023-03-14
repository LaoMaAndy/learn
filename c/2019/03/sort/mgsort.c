/* merge sort */
static void merge(int v[], int temp[], int left, int center, int right);

static void mergesort(int v[], int temp[], int left, int right)
{
	int center;

	if (left < right)
	{
		center = (left + right) / 2;
		mergesort(v, temp, left, center);
		mergesort(v, temp, center + 1, right);
		merge(a, temp, left, center + 1, right);
	}
}
static merge(int v[], int temp[], int left, int right, int end)
{
	int i, left_end, n, temp_pos;

	left_end = right - 1;
	temp_pos = left;
	n = end - left + 1;

	while ()
}
void mgsort(int v[], int n)
{
	int *temp;

	temp = (int *) malloc(n * sizeof(int));
	if (temp == NULL)
		return;
	mergesort(v, temp, 0, n - 1);
	free(temp);
}
