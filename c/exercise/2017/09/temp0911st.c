/*
 * prototype: stack
 */
#include <stdio.h>
#include <stdlib.h>

struct	stack_info
{
	void *base, *top;
	int n, size;
};
typedef struct stack_info stack;

stack 	*stkinit(int n, int size);
void 	*stkpush(stack *s, const void *);
void 	*stkpop(stack *s);
void 	*stkgetop(const stack *s);
void 	*stkgetn(const stack *s, int n);
void 	stkfree(stack *s);
int		stkcount(const stack *s);
int 	stkmax(const stack *s);
int 	stkempty(const stack *s);

/*
 * implementation
 */
stack *stkinit(int n, int size)
{
	stack *p = (stack *) malloc(sizeof(stack));

	if (p == (stack *) 0)
	{
		fprintf(stderr, "stack error: malloc(%zd) return 0\n", sizeof(stack));
		return (stack *) 0;
	}
	p->base = calloc(n, size);
	if (p->base == 0)
	{
		fprintf(stderr, "stack error: malloc(%d) return 0\n", n * size);
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
	if (s->top - s->base >= s->n * s->size)
	{
		void *t = realloc(s->base, s->n * 2 * s->size);
		if (t == (void *) 0)
		{
			fprintf(stderr, "stack error: push, full. realloc return 0.\n");
			return (void *) d;
		}
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
	fprintf(stderr, "stack error: pop, empty.\n");
	return (void *) 0;
}

void *stkgetop(const stack *s)
{
	if (s->top > s->base)
		return (s->top - s->size);
	fprintf(stderr, "stack error: getop, empty.\n");
	return (void*) 0;
}

void *stkgetn(const stack *s, int n)
{
	void *p;
	
	p = s->top - (n + 1) * s->size;
	if (p >= s->base)
		return p;
	if (s->top == s->base)
		fprintf(stderr, "stack error: getn, empty.\n");
	return (void *) 0;
}

void stkfree(stack *s)
{
	if (s->base != (void *) 0)
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


#define ST_TYPE int

ST_TYPE *st_base, *st_top;
ST_TYPE st_invalid;
int 	st_size;
int 	st_init(int size);
ST_TYPE	st_push(ST_TYPE d);
ST_TYPE st_pop(void);
ST_TYPE st_getop(void);
void	st_free(void);
int		st_count(void);
int 	st_remain(void);

/*
 * implementation
 */
#include <stdio.h>
#include <stdlib.h>

int st_init(int size)
{
	st_base = (ST_TYPE *) malloc(size * sizeof(ST_TYPE));
	if (st_base != (ST_TYPE *) 0)
	{
		st_top = st_base;
		st_size = size;
		return size;
	}
	else
		fprintf(stderr, "Stack error: malloc return 0.\n");
	return 0;
}

ST_TYPE st_push(ST_TYPE d)
{
	if (st_top - st_base < st_size)
		*st_top++ = d;
	else
		fprintf(stderr, "Stack error: full.\n");
	return d;
}

ST_TYPE st_pop(void)
{
	if (st_top > st_base)
		return *--st_top;
	else
		fprintf(stderr, "Stack error: empty.\n");
	return st_invalid;
}

ST_TYPE st_getop(void)
{
	if (st_top > st_base)
		return *(st_top - 1);
	else
		fprintf(stderr, "Stack error: empty.\n");
	return st_invalid;
}

int st_count(void)
{
	return st_top - st_base;
}

int st_remain(void)
{
	return st_size - (st_top - st_base);
}

void st_free(void)
{
	if (st_base != (ST_TYPE *) 0)
		free(st_base);
}

 
