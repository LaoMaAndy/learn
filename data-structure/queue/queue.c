/* queue.c */
#include "queue.h"

#define MIN_QUEUE_ELEM 32
typedef int elem;
struct queue
{
	elem *begin;
	elem *end;
	elem *front;
	elem *rear;
};
typedef struct queue queue;
int ElemSize(void);
int ElemComp(elem a, const elem b);
void PrnElem(elem e);

int ElemSize(void)
{
	return sizeof(elem);
}
int ElemComp(elem a, const elem b)
{
	return a - b;
}
void PrnElem(elem e)
{
	printf("%6d ", e);
}

queue *NewQue(int n)
{
	queue *q;
	elem *e;
	q = (queue *) malloc(sizeof(queue));
	e = (elem *) malloc((n + 1) * sizeof(elem));
	if (q == NULL || e == NULL)
		Exit("malloc() return NULL");
	q->begin = q->front = q->rear = e;
	q->end = q->begin + n + 1;
	return q;
}
queue *Realloc(queue *q, int n)
{
	elem *temp;
	if (n < q->end - q->begin)
		return q;
	temp = realloc(q->begin, n * sizeof(elem));
	if (temp == NULL)
		Exit("malloc() return NULL");
	
}
queue *EnQue(queue *q, elem m)
{
	
}
elem *DeQue(queue *q);
elem *GetFront(queue *q);
void Print(queue *v);