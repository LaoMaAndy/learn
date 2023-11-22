/* stack queue */
#include "template/head.h"

void *stack[20];
int ssize = sizeof(stack) / sizeof(*stack);
void **sptr = stack;

void push(void *p)
{
	if (sptr - stack >= ssize)
		printf("stack full\n");
	else
		*sptr++ = p;
}
void *pop()
{
	if (sptr == stack)
	{
		printf("stack empty\n");
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

void *queue[20];
int qsize = sizeof(queue) / sizeof(*queue);
void **qfront = queue;
void **qrear = queue;

void enque(void *p)
{
	void **next = qrear + 1;

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
	void *p = *qfront;

	if (qfront == qrear)
		printf("queue empty\n");
	else
	{
		++qfront;
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