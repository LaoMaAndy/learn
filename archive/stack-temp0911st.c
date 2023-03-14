#include <stdio.h>
#include <stdlib.h>
/*
 * prototype: stack
 */


struct	stack_info
{
	void *base, *top;
	int n, size;
};
typedef struct stack_info stack;

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
	return s->top;
}

void *stkgetop(const stack *s)
{
	if (s->top > s->base)
		return (s->top - s->size);
	fprintf(stderr, "stack error: getop, empty.\n");
	return s->top;
}

void *stkgetn(const stack *s, int n)
{
	void *p;
	
	if ((p = s->top - n  * s->size) <= s->base)
		return s->base;
	if (s->top > s->base)
		return (s->top - (n + 1) * s->size);
	fprintf(stderr, "stack error: getn, empty.\n");
	return s->top;
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

int stkremain(const stack *s)
{
	return s->n - (s->top - s->base) / s->size;
}

int stkmax(const stack *s)
{
	return s->n;
}

void test_stk(void)
{
	stack *t;
	float d = 1.0;
	int i;

	t = stkinit(1, sizeof(float));
	if (t == (void *) 0)
		exit(1);
	printf("init count: %d\n", stkcount(t));
	printf("init remain:%d\n", stkremain(t));
	d = 1234.0;
	stkpush(t, &d);
	printf("push 1st\n");
	printf("init count: %d\n", stkcount(t));
	printf("init remain:%d\n", stkremain(t));
	d = 5678.0;
	stkpush(t, &d);
	printf("push 2nd\n");
	printf("init count: %d\n", stkcount(t));
	printf("init remain:%d\n", stkremain(t));
	for (i = 0, d = 1.0; i < 11; i++)
	{
		printf("push: %f", *(float *)stkpush(t, &d));
		printf("\tgetop: %f", *(float *)stkgetop(t));
		printf("\tcount: %d", stkcount(t));
		printf("\tremain:%d\n", stkremain(t));
		d += 1.2;
	}
	printf("---------------\n");
	printf("stack count %d\n", stkcount(t));
	printf("---------------\n");
	for (i = 0; i < 15; i++)
	{
		printf("getn: %f\n", *(float *)stkgetn(t, i));
	}
	for (i = 0; i < 15; i++)
	{
		printf("pop: %f\n", *(float *)stkpop(t));
	}
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

 
