/* base_sort.c */
#include "template/head.h"

struct node
{
	int prev, next;
	int val;
};
typedef struct node node;
struct bucket
{
	int start, count;
};
typedef struct bucket bucket;

static void prn_node(node *p, int n, int v[]);
static void prn_bucket(bucket *b, int n);
int Base(int val, int base, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		val /= base;
	return val % base;
}
void test_base()
{
	int v[] = {256, 12, 0, 11, 4, 1024};
	int n = sizeof(v) / sizeof(*v);
	int i, j;

	for (i = 0; i < n; ++i)
	{
		printf("Val: %5d, ", v[i]);
		for (j = 0; j < 5; ++j)
			printf("Base(%d):%2d  ", j, Base(v[i], 10, j));
		printf("\n");
	}
}
void bsort(int v[], int n, int base, int time)
{
	bucket bt[base];
	node nod[n];
	int i, j, b, index, cur;

	for (b = 0; b < time; ++b)
	{
		printf("=========  time :%d  =========\n", b);

		for (i = 0; i < base; ++i)	
		{
			bt[i].start = -1;						// bucket set to be empty
			bt[i].count = 0;
		}
		for (i = 0; i < n; ++i)
		{
			index = Base(v[i], base, b);			// get bucket value
			nod[i].val = v[i];
			++bt[index].count;
			if (bt[index].start == -1) 				// empty bucket
			{
				bt[index].start = i;				// set start value;
				nod[i].prev = nod[i].next = i;		// loop chain
			}
			else									// other elem
			{
				cur = bt[index].start;
				nod[i].next = cur;					// set current nod 
				nod[i].prev = nod[cur].prev;			// 
				nod[cur].prev = i;
				nod[nod[nod[cur].prev].prev].next = i;
			
			}
		}
		// return;
		for (i = 0; i < base; ++i)
		{
			if (bt[i].start == -1)
				continue;
			cur = bt[i].start;
				printf("bt[i].start): %3d bucket: %4d -->", i, bt[i].start);
			do
			{
				printf("%3d ", v[cur]);
				cur = nod[cur].next;
			} while(cur != bt[i].start);
			printf("\n");
		}
		for (index = i = 0; i < base; ++i)
		{
			if (bt[i].start == -1)
				continue;
			cur = bt[i].start;
			do
			{
				v[index++] = nod[cur].val;
				cur = nod[cur].next;
			} while(cur != bt[i].start);
		}
		printf("v: ");
		for (i = 0; i < n; ++i)
		{
			printf("%4d\t", v[i]);
		}
		printf("\n");
	}
}
static void prn_node(node *p, int n, int v[])
{
	int i;

	for (i = 0; i < n; ++i)
		printf("node[%3d] next: %3d, Prev: %3d, Val: %3d --> %3d\n", i, p[i].next, p[i].prev, p[i].val, v[i]);
}
static void prn_bucket(bucket *b, int n)
{
	int j;
	char c;

	for (j = 0; j < n; ++j)
	{
		c = (j % 4 == 3) ? '\n' : ' ';
		printf("bucket[%3d] start:%3d, Count:%3d \n", j, b[j].start, b[j].count);
	}
	printf("\n");
}
void test_bsort(void)
{
	//int v[] = {64, 8, 216, 512, 27, 729, 0, 1, 343, 125};
	//int v[] = {1, 21, 31, 41, 51, 61, 71, 8, 9, 10};
	int v[] = {9, 8, 7, 6, 11, 21, 31, 10, 100, 12};
	int n = sizeof(v) / sizeof(*v);
	int base = 10;
	int time = 3;

	bsort(v, n, base, time);
}
int main()
{
	test_base();
	test_bsort();
	return 0;
}
