/* 30 int less than 50 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 11
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
int main()
{
	int i, v[NUM];
	int j;

	for (j = 0; j < 20; ++j)
	{
		srand(time(NULL));
		for (i = 0; i < NUM; ++i)
			v[i] = i + 1;
		for (i = 0; i < NUM; ++i)
			swap(v, i, rand() % NUM);
		for (i = 0; i < NUM; ++i)
			printf("%d, ", v[i]);
		printf("\n");
	}
	return 0;
}