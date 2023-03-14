/*
 * prototype: data structure -- stack
 */

struct stack_info
{
	void *top, *base;
	int n, size;
};
typedef struct stack_info stack;

stack	*stkinit(int n, int size);
void	*stkpush(stack *s, const void *d);
void 	*stkpop(stack *s);
void 	*stkgetop(const stack *s);
void 	*stkgetn(const stack *s, int n);
void 	stkfree(stack *s);
int		stkcount(const stack *s);
int 	stkmax(const stack *s);
int		stkempty(const stack *s);

/*
 * implementation
 */
#include <stdlib.h>

stack *stkinit(int n, int size)
{
	stack *p;

	p = (stack *) malloc(sizeof(stack));
	if (p == 0)
		return (stack *) 0;
	p->base = malloc(n * size);
	if (p->base == 0)
	{
		free(p);
		return (stack *) 0;
	}
	p->top = p->base;
	p->n = n;
	p->size = size;
	return p;
}

void *stkpush(stack *s, const void *d)
{
	if (s->top - s->base + s->size > s->n * s->size)
	{
		void *t = realloc(s->base, s->n * s->size * 2);
		if (t == 0)
			return (void *) d;
		s->top = t + (s->top - s->base);
		s->base = t;
		s->n *= 2;
	}
	for (int i = 0; i < s->size; i++)
		((char *) s->top)[i] = ((const char *) d)[i];
	s->top += s->size;
	return (void *) d;
}

void *stkpop(stack *s)
{
	if (s->top > s->base)
	{
		s->top -= s->size;
		return s->top;
	}
	return (void *) 0;
}

void *stkgetop(const stack *s)
{
	void *p;

	p = s->top - s->size;
	return p >= s->base ? p : (void *) 0;
}

void *stkgetn(const stack *s, int n)
{
	void *p;

	p = s->top - (n + 1) * s->size;
	return p >= s->base ? p : (void *) 0;
}

void stkfree(stack *s)
{
	if (s->base != 0)
		free(s->base);
	free(s);
}

int stkcount(const stack *s)
{
	return (s->top - s->base) / s->size;
}

int stkmax(const stack *s)
{
	return s->n;
}

int stkempty(const stack *s)
{
	return s->top == s->base;
}

/*
 * test
 */
#include "00prn.h"

struct some_info
{
	int a;
	char b;
};
typedef struct some_info info;

void test_stk1(void)
{
	stack *t;
	info i, j;

	t = stkinit(1, sizeof(info));
	i.a = 12;
	i.b = 'a';
	stkpush(t, &i);
	j = *(info *)stkpop(t);
	printf("struct j.a: %d\n", j.a);
	printf("struct j.b: %c\n", j.b);
	stkfree(t);
}

void test_stk2(void)
{
	stack *buffer;

	buffer = stkinit(1, sizeof(char));
	if (buffer == (stack *) 0)
		exit(1);
	
}
#define TTYPE char
void test_stk(void)
{
	stack *t;
	TTYPE d = 'a';
	int i;

	PRN_CAL(test_stk1());
	PRN_SEN(t = stkinit(1, sizeof(TTYPE)));
	if (t == (void *) 0)
		exit(1);
	PRN_FUN(stkcount(t), d);
	PRN_FUN((stkmax(t) - stkcount(t)), d);
	PRN_SEN(d = 'a');
	PRN_SEN(stkpush(t, &d));
	PRN_STR(---push 1st---);
	PRN_FUN(stkcount(t), d);
	PRN_FUN((stkmax(t) - stkcount(t)), d);
	PRN_SEN(d = 'b');
	PRN_SEN(stkpush(t, &d));
	PRN_STR(---push 2nd---);
	PRN_FUN(stkcount(t), d);
	PRN_FUN((stkmax(t) - stkcount(t)), d);
	for (i = 0, d = 'A'; i < 6; i++)
	{
		printf("push: %c", *(TTYPE *)stkpush(t, &d));
		printf("\tgetop: %c", *(TTYPE *)stkgetop(t));
		printf("\tcount: %d", stkcount(t));
		printf("\tremain:%d\n", stkmax(t) - stkcount(t));
		d += 1;
	}
	printf("---------------\n");
	printf("stack count %c\n", stkcount(t));
	printf("---------------\n");
	i = 0;
	void *p;
	while ((p = stkgetn(t, i)) != (void *) 0)
		printf("getn(%d): %c\n", i++, *(TTYPE *)p);
	i = 0;
	while (!stkempty(t))
		printf("pop %d times: %c\n", ++i, *(TTYPE *)stkpop(t));
	printf("\n");
	stkfree(t);
}

int main(int argc, char *argv[])
{
	test_stk();
	return 0;
}

