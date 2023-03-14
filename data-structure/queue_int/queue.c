#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../error/error.h"

struct queue
{
	int *front, *rear;
	int *base, *top;
	int size;
};
typedef struct queue queue;

queue *init(int n)
{
	int *p;
	queue *q;

	p = (int *) malloc(n * sizeof(int));
	q = (queue *) malloc(sizeof(*q));
	if (p == NULL || q == NULL)
		Exit("malloc() return NULL");
	q->size = n;
	q->front = q->rear = q->base = p;
	q->top = p + n;
	return q;
}
void enque(queue *q, int v)
{
	int *next = q->rear;
	
	++next;
	if (next == q->top)
		next = q->base;
	if (next == q->front)
		Exit("Queue is full");
	*q->rear = v;
	q->rear = next;
}
int deque(queue *q)
{
	int v;

	if (q->front == q->rear)
		Exit("Queue if empty");
	v = *q->front++;
	if (q->front > q->top)
		q->front = q->base;
	return v;
}
void prnque(queue *q)
{
	int *next;
	int i;

	for (i = 0, next = q->front; next != q->rear; ++i)
	{
		printf("[%3d] %4d\n", i, *next);
		++next;
		if (next == q->top)
			next = q->base;
	}
	printf("---------\n");
}
void test_queue()
{
	queue *q;
	int i;

	q = init(21);
	prnque(q);
	for (i = 0; i < 20; ++i)
		enque(q, i);
	prnque(q);
	deque(q);
	prnque(q);
}
int main()
{
	test_queue();
	return 0;
}