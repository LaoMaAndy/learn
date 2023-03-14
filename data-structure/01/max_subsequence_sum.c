#include "../dsaa.h"

int max_sub(const int v[], int n)
{
	int max_sub, max_val, sum, i;

	max_sub = max_val = v[0];
	for (i = 0, sum = 0; i < n; ++i)
	{
		if (v[i] > max_val)
			max_val = v[i];
		sum += v[i];
		if (sum > max_sub)
			max_sub = sum;
		else if (sum < 0)
			sum = 0;
	}
	return max_sub > max_val ? max_sub : max_val;
}
int test_max_sub()
{
	int v[][8] = {	{4	, -3, 5, -2, -1, 2, 6, -2}, 
					{-1	, -2, -3, -5, -10}
				  };
	int n = sizeof(v) / sizeof(*v);
	int m = sizeof(*v) / sizeof(**v);
	int max, i, j;

	for (i = 0; i < n; ++i)
	{
		printf("Sequence: ");
		for (j = 0; j < m; ++j)
			printf("%d  ", v[i][j]);
		printf("\n");
		max = max_sub(v[i], m);
		printf("MaxSub is :%d\n", max);
	}
}
int main()
{
	test_max_sub();
	return 0;
}


		
