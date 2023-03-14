/* queue */
#include "template/head.h"

void *stack[20];
int ssize = sizeof(stack) / sizeof(*stack);
void **sptr = stack;

void push(void *p)
{
	if (sptr - stack >= ssize)
		printf("stack overflow\n");
	else
		*sptr++ = p;
}
void *pop()
{
	if (sptr <= stack)
	{
		printf("stack empty\n");
		return NULL;
	}
	return *--sptr;
}
void *top()
{
	return *(sptr - 1);
}
int isempty()
{
	return (sptr <= stack) ? 1 : 0;
}

void *queue[21];
int qsize = sizeof(queue) / sizeof(*queue) - 1;
void **qfront = queue;
void **qrear = queue;

void enque(void *p)
{
	void **next = qrear + 1;

	if (next - queue >= qsize + 1)
		next = queue;
	if (next == qfront)
		printf("queue is full\n");
	else
	{
		*qrear = p;
		qrear = next;
	}
}
void *deque()
{
	void *p = NULL;

	if (qfront == qrear)
		printf("queue is empty\n");
	else
	{
		p = *qfront++;
		if (qfront - queue >= qsize + 1)
			qfront = queue;
	}
	return p;
}
void *front()
{
	return (qfront == qrear) ? NULL : *qfront;
}
int qempty()
{
	return (qfront == qrear) ? 1 : 0;
}

