/*
 * queue.c
 */
#include "template/head.h"

void *stack[20];
int ssize = sizeof(stack) / sizeof(*stack);
void **sptr = stack;

void push(void *p)
{
	if (sptr - stack >= ssize)
		printf("stack is full\n");
	else 
		*sptr++ = p;
}
void *pop()
{
	if (sptr == stack)
	{
		printf("stack empyt\n");
		return *sptr;
	}
	return *--sptr;
}
int isempty()
{
	return (sptr == stack) ? 1 : 0;
}
void *top()
{
	return *(sptr - 1);
}

void *queue[20];
int qsize = sizeof(queue) / sizeof(*queue);
void **qfront = queue;
void **qrear = queue;

void enque(void *p)
{
	void **next;

	next = qrear + 1;
	if (next - queue >= qsize)
		next = queue;
	if (next == qfront)
		printf("queue full\n");
	else
	{
		*qrear = p;
		qrear = next;
	}
}
void *deque()
{
	void *r = NULL;

	if (qfront == qrear)
		printf("queue empty\n");
	else 
	{
		r = *qfront++;
		if (qfront - queue >= qsize)
			qfront = queue;
	}
	return r;
}
int qempty()
{
	return (qfront == qrear) ? 1 : 0;
}
void *front()
{
	return *qfront;
}