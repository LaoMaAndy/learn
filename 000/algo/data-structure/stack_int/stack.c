#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../error/error.h"

struct stack
{
	int *top, *base;
	int size;
};
typedef struct stack stack;

stack *init(int n)
{
	int *p;
	stack *s;

	p = (int *) malloc(n * sizeof(*p));
	s = (stack *) malloc(sizeof(*s));
	if (p == NULL || s == NULL)
		Exit("malloc() return NULL");
	s->top = s->base = p;
	s->size = n;
	return s;
}
void push(stack *s, int v)
{
	if (s->top - s->base >= s->size)
		Exit("stack overflow");
	*s->top++ = v;
}
int pop(stack *s)
{
	if (s->top == s->base)
		Exit("stack empty");
	return *--s->top;	
}
int gettop(stack *s)
{
	if (s->top == s->base)
		Exit("stack empty");
	return *(s->top - 1);
}
int height(stack *s)
{
	return s->top - s->base;
}
void prnstack(stack *s)
{
	int *p;
	int i;

	for (i = s->top - s->base - 1, p = s->top - 1; p >= s->base; --p, --i)
		printf("[%3d] %3d\n", i, *p);
	printf("----- stack height: %3d ------\n", height(s));
}
void test_stack()
{
	stack *s;
	int i;

	s = init(20);
	prnstack(s);
	for (i = 0; i < 20; ++i)
		push(s, i);
	prnstack(s);
	pop(s);
	prnstack(s);
}
int main()
{
	test_stack();
	return 0;
}