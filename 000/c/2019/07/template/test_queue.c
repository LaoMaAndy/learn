#include "head.h"

void push(void *p);
int isempty();
void *pop();
void *top();
extern int ssize;

void init_order(int v[], int n)
{
	int i;

	for (i = 0; i < n; ++i)
		v[i] = i;
}
void init_rand(int v[], int n)
{
	int i;

	init_order(v, n);
	for (i = 0; i < n; ++i)
		swap(v, i, rand() % n);
}
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void test_stack()
{
	int n = ssize;
	int v[n];
	int i, j, a, b, c, ok = 1;
	int *p;

	init_order(v, n);
	a = isempty();
	for (i = 0; i < n; ++i)
	{
		push(&v[i]);
		if (*(int *)top() != v[i])
			ok = 0;
		//printf("%3d: %d\n", i, n);
	}
	if (ok == 1)
		printf("top() ...ok\n");
	else
		printf("top() ...error\n");
	b = isempty();
	push(NULL);
	ok = 1;
	for (i = n - 1; i >= 0; --i)
	{
		p = (int *) pop();
		if (p != NULL && i != *p)
			ok = 0;
	}
	pop();
	c = isempty();
	if (a == 1 && b == 0 && c == 1)
		printf("isempty() ...OK\n");
	else
		printf("isempty() ...Err\n");
	if (ok) 
		printf("=== stack ...ok\n");
	else
		printf("=== stack ...error\n");
}

void enque(void *p);
void *deque();
int qempty();
void *front();
extern int qsize;

void test_que(void)
{
	int n = qsize - 1;
	int v[qsize];
	int i, a, b, c, ok;
	int *p;

	init_order(v, n);
	a = qempty();
	for (i = 0; i < n; ++i)
		enque(&v[i]);
	if (*(int *)front() == 0)
		printf("front() ...ok\n");
	enque(NULL);
	b = qempty();
	ok = 1;
	for (i = 0; i < n; ++i)
	{
		p = (int *) deque();
		if (p != NULL && *p != i)
			ok = 0;
	}
	deque();
	c = qempty();
	if (a == 1 && b == 0 && c == 1)
		printf("qempty() ...OK\n");
	else
		printf("qempty() ...Err\n");
	if (ok) 
		printf("=== queue ...ok\n");
	else
		printf("=== queue ...error\n");
}
int main()
{
	test_stack();
	test_que();
	return 0;
}