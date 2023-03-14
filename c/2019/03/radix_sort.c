/* radix sort */
#include "template/head.h"

static int get_max(int a[], int n)
{
	int i, max;

	max = a[0];
	for (i = 1; i < n; ++i)
		if(a[i] > max)
			max = a[i];
	return max;
}
static void radix_count(int v[], int n, int radix, int exp)
{
	int *temp;
	int *bk;
	int i;

	temp = (int *) malloc(n * sizeof(int));
	bk = (int *) malloc(radix * sizeof(int));
	if (temp == NULL || bk == NULL)
		return ;
	for (i = 0; i < radix; ++i)
		bk[i] = 0; 
	for (i = 0; i < n; ++i)
		++bk[(v[i] / exp) % radix];
	for (i = 1; i < radix; ++i)
		bk[i] += bk[i - 1];
	for (i = n - 1; i >= 0; --i)
	{
		temp[bk[(v[i] / exp) % radix] - 1] = v[i];
		--bk[(v[i] / exp) % radix];
	}
	for (i = 0; i < n; ++i)
		v[i] = temp[i];
	free(temp);
	free(bk);
}
void rdsort(int v[], int n, int radix)
{
	long exp;
	int max = get_max(v, n);

	for (exp = 1; max / exp > 0; exp *= radix)
		radix_count(v, n, radix, exp);
}