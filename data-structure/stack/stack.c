/* stack_int.c */
#include "stack.h"

#define STACK_MIN_SIZE 2
struct stack
{
	elem *base, *top;
	int cap;
} ;
typedef struct stack stack;

int ElemSize(void)
{
	return sizeof(elem);
}
void ElemCopy(elem *dest, elem *src)
{
	*dest = *src;
}
stack *NewStack(void)
{
	stack *s;
	elem *base;

	s = (stack *) malloc(sizeof(stack));
	base = (elem *) malloc(sizeof(STACK_MIN_SIZE * ElemSize()));
	if (s == NULL || base == NULL)
		Exit("malloc() return NULL");
	s->cap = STACK_MIN_SIZE;
	s->top = s->base = base;
	printf("Stack Size: %d\n", s->cap);
	return s;
}
static void ExpandStack(stack *s)
{
	elem *base;

	printf("ExandStack(): %4d -> %4d\n", s->cap, 2 * s->cap);
	base = (elem *) realloc(s->base, s->cap * 2 * ElemSize());
	if (base == NULL)
		Exit("realloc() return NULL");
	s->cap *= 2;
	s->top = base + (s->top - s->base);
	s->base = base;
}
void FreeStack(stack *s)
{
	free(s->base);
	free(s);
}
void DelStack(stack *s)
{
	while (!IsEmpty(s))
		Pop(s);
}
int IsEmpty(stack *s)
{
	return (s->top == s->base);
}
void Push(stack *s, elem e)
{
	if (s->top - s->base >= s->cap)
		ExpandStack(s);
	*s->top = e;
	++s->top;
}
elem Pop(stack *s)
{
	return *--s->top;
}
elem Top(stack *s)
{
	return *(s->top - 1);
}
int StackSize(stack *s)
{
	return s->top - s->base;
}
int StackCap(stack *s)
{
	return s->cap;
}