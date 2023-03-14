/*
 * queue.c 
 */
#include "template/head.h"

void *stack[200];
int ssize = sizeof(stack) / sizeof(*stack);
void **sptr = stack;

void push(void *p)
{
	if (sptr - stack >= ssize)
	{
		printf("stack full\n");
		return;
	}
	*sptr++ = p;
}
void *pop()
{
	if (sptr == stack)
	{
		printf("stack empty\n");
		return NULL;
	}
	return *--sptr;
}
int isempty()
{
	return (sptr == stack);
}
void *top()
{
	return *(sptr - 1);
}

void *queue[200];
int qsize = sizeof(queue) / sizeof(*queue);
void **qfront = queue;
void **qrear = queue;

void enque(void *p)
{
	void **next = qrear + 1;

	if (next - queue >= qsize)
		next = queue;
	if (next == qfront)
	{
		printf("queue is full\n");
		return;
	}
	*qrear = p;
	qrear = next;
}
void *deque()
{
	void *p = *qfront;

	if (qfront == qrear)
	{
		printf("queue empty\n");
		return NULL;
	}
	if (++qfront - queue >= qsize)
		qfront = queue;
	return p;
}
int qempty()
{
	return (qfront == qrear);
}
void *front()
{
	return *qfront;
}