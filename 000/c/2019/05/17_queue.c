/* queue.c */
#include "template/head.h"

void *stack[21];
int ssize = sizeof(stack) / sizeof(*stack);
void **sptr = stack;

void push(void *p)
{
	if (sptr - stack >= ssize)
		printf("stack ful\n");
	else
		*sptr++ = p;
}
void *pop()
{
	if (sptr == stack)
	{
		printf("stack empty");
		return *sptr;
	}
	else
		return *--sptr;
}
void *top()
{
	return *(sptr - 1);
}
int isempty()
{
	return (sptr == stack) ? 1 : 0;
}

void *queue[22];
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
	void *p;

	if (qfront == qrear)
	{
		printf("queue tempty\n");
		return *qfront;
	}
	else
	{
		p = *qfront++;
		if (qfront - queue >= qsize)
			qfront = queue;
	}
	return p;
}
void *front()
{
	return *qfront;
}
int qempty()
{
	return (qfront == qrear) ? 1 : 0;
}