/* base_sort.c */
#include "template/head.h"

/* 基数排序法 */
// 需备注

int Base(int val, int base, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		val /= base;
	return val % base;
}

void bsort(int v[], int n, int base, int time)
{
	int *bt;
	int *next;
	int *prev;
	int *val;
	int i, t, index, cur;

	bt = (int *) malloc(base * sizeof(int));
	next = (int *) malloc(n * sizeof(int));
	prev = (int *) malloc(n * sizeof(int));
	val = (int *) malloc(n * sizeof(int));

	if (bt == NULL || next == NULL || prev == NULL || val == NULL)
	{
		printf("malloc() return NULL\n");
		return ;
	}
	for (t = 0; t < time; ++t)
	{
		//printf("=========  time :%d  =========\n", t);
		for (i = 0; i < base; ++i)	
		{
			bt[i] = -1;						// bucket set to be empty
		}
		for (i = 0; i < n; ++i)
		{
			val[i] = v[i];					// copy value
			index = Base(v[i], base, t);	// get bucket value
			if (bt[index] == -1) 			// it's an empty bucket
			{
				bt[index] = i;				// set start value;
				prev[i] = next[i] = i;		// loop chain
			}
			else							// not empty
			{
				cur = bt[index];
				next[i] = cur;				// set current node
				prev[i] = prev[cur];		// intsert into before current node
				next[prev[cur]] = i;		// be carefull to the order
				prev[cur] = i;
			}
		}
		for (index = i = 0; i < base; ++i)	//copy value, for each bucket
		{
			if (bt[i] == -1)				// if bucket is empty, next
				continue;
			cur = bt[i];					// locate the first
			do
			{
				v[index++] = val[cur];		// copy value
				cur = next[cur];			// move cursor
			} while(cur != bt[i]);			// back to the first, quit loop
		}
	}
	free(bt);
	free(next);
	free(prev);
	free(val);
}
