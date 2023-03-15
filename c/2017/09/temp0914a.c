/*
 * prototype. data structure: stack (stk)
 */

#define STKTYPE double

typedef struct stk_info
{
	STKTYPE *base, *top;
	int size;
} *stkptr;

stkptr stkinit(int n);
STKTYPE stkpush(stkptr s, STKTYPE d);
STKTYPE stkpop(stkptr s);
STKTYPE stkgetop(const stkptr s);
STKTYPE stkgetn(const stkptr s, int n);
void stkfree(stkptr s);
void  stkreset(stkptr s);
int  stkresize(stkptr s, int n);
int  stkcount(const stkptr s);
int  stksize(const stkptr s);

#define stkise(ptr) ((ptr)->base == (ptr)->top)
#define stkvalid(ptr, n) ((ptr)->top - (n) > (ptr)->base)

/*
 *implementation
 */
#include <stdlib.h>		/* need malloc(), realloc(), free() */
#include <stdio.h>		/* need fprintf() */

stkptr stkinit(int n)
{
	stkptr s;

	s = (stkptr) malloc(sizeof(struct stk_info));
	if (s == 0)
		return (stkptr) 0;
	s->base = (STKTYPE *) malloc(n * sizeof(STKTYPE));
	if (s->base == 0)
	{
		free(s);
		return (stkptr) 0;
	}
	s->top = s->base;
	s->size = n;
	return  s;
}

STKTYPE stkpush(stkptr s, STKTYPE data)
{
	STKTYPE *temp;

	if (s->top - s->base  + 1 > s->size)
	{
		temp = (STKTYPE *)realloc(s->base, s->size * 2 * sizeof(STKTYPE));
		if (temp == 0)
		{
			fprintf(stderr, "Stack error. %s : realloc return 0.\n", __func__);
			return data;
		}
		s->top = temp + (s->top - s->base);
		s->base = temp;
		s->size *= 2;
	}
	*s->top++ = data;

	return  data;
}

STKTYPE stkpop(stkptr s)
{
	return *--s->top;
}

STKTYPE stkgetop(const stkptr s)
{
	return *(s->top - 1);
}

STKTYPE stkgetn(const stkptr s, int n)
{
	return *(s->top - n - 1);
}

void stkfree(stkptr s)
{
	if (s->base != 0)
		free(s->base);
	free(s);
}

void stkreset(stkptr s)
{
	s->top = s->base;
}

int stkresize(stkptr s, int n)
{
	STKTYPE *p;
	
	p = (STKTYPE *)realloc(s->base, n * sizeof(STKTYPE)); 
	if (p == 0)
	{
		fprintf(stderr, "stack error. %s : realloc return 0.\n", __func__);
		return 0;
	}
	s->top = s->top - s->base + p;
	s->base = p;
	s->size = n;
	return n;
}

int stkcount(const stkptr s)
{
	return s->top - s->base;
}

int stksize(const stkptr s)
{
	return s->size;
}
#include "00prn.h"
#define DATA_A 222.111
#define DATA_B 7.8

void test_stk(void)
{
	stkptr t;
	STKTYPE d = DATA_A;
	int i;

	PRN_SEN(t = stkinit(1));
	if (t == 0)
		exit(1);
	PRN_FUN(stkcount(t), d);
	PRN_FUN((stksize(t) - stkcount(t)), d);
	PRN_SEN(d = DATA_A);
	PRN_FUN(stkpush(t, d), f);
	PRN_STR(---push 1st---);
	PRN_FUN(stkcount(t), d);
	PRN_FUN((stksize(t) - stkcount(t)), d);
	PRN_SEN(d = DATA_B);
	PRN_SEN(stkpush(t, d));
	PRN_STR(---push 2nd---);
	PRN_FUN(stkcount(t), d);
	PRN_FUN((stksize(t) - stkcount(t)), d);
	PRN_STR(----push 6 times---);
	for (i = 0, d = DATA_A; i < 6; i++)
	{
		PRN_FUN(stkpush(t, d), f);
		PRN_FUN(stkgetop(t), f);
		PRN_FUN(stkcount(t), d);
		PRN_FUN(stksize(t) - stkcount(t), d);
		PRN_SEN(d += 1);
	}
	printf("---------------\n");
	PRN_FUN(stkcount(t), d);
	printf("---------------\n");
	i = 0;
	while (stkvalid(t, i))
	{
		PRN_FUN(stkgetn(t, i), f);
		i++;
	}
	i = 0;
	while (!stkise(t))
	{
		printf("pop %d times: ", ++i);
		PRN_FUN(stkpop(t), f);
	}
	printf("\n");
	stkfree(t);
}

int main(int argc, STKTYPE *argv[])
{
	test_stk();
	return 0;
}
