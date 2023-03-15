/*
 * data structure. stack. 10
 */
#define STKDATA int

typedef struct stk_info
{
	STKDATA *base, *top;
	int size;
} *stkptr;

stkptr 	stkinit		(int n);
int 	stkresize	(stkptr s, int n);
int 	stkpush		(stkptr s, STKDATA d);
int 	stkpop		(stkptr s, STKDATA *dp);
int 	stkgetop	(stkptr s, STKDATA *dp);
int 	stkgetn		(stkptr s, STKDATA *dp, int n);
void 	stkfree		(stkptr s);
void 	stkreset	(stkptr s);
int 	stkcount	(stkptr s);
int 	stkmax		(stkptr s);

/*
 * implementation
 */
#include <stdlib.h>		/* need malloc(), realloc() */

stkptr stkinit(int n)
{
	stkptr p;

	p = (stkptr) malloc(sizeof(struct stk_info));
	if (p == 0)
		return (stkptr) 0;
	p->base = (STKDATA *) malloc (n * sizeof(STKDATA));
	if (p->base == 0)
	{
		free(p);
		return (stkptr) 0;
	}
	p->top = p->base;
	p->size = n;
	return p;
}

int stkresize(stkptr s, int n)
{
	STKDATA *temp;
	int i;
	
	temp = (STKDATA *) realloc (s->base, n * sizeof(STKDATA));
	if (temp == 0)
		return 0;
	i = s->top - s->base;
	s->top = (i < n ? temp + i : temp + n);
	s->base = temp;
	s->size = n;
	return n;
}

int stkpush(stkptr s, STKDATA d)
{
	if (s->top - s->base + 1 > s->size)
		if (!stkresize(s, s->size * 2))
			return 0;
	*s->top++ = d;
	return 1;
}

int stkpop(stkptr s, STKDATA *dp)
{
	if (s->top <= s->base)
		return 0;
	*dp = *--s->top;
	return 1;
}

int stkgetop(stkptr s, STKDATA *dp)
{
	if (s->top <= s->base)
		return 0;
	*dp = *(s->top - 1);
	return 1;
}

int stkgetn(stkptr s, STKDATA *dp, int n)
{
	if (s->top - n <= s->base)
		return 0;
	*dp = *(s->top - n - 1);
	return 1;
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

int stkcount(stkptr s)
{
	return s->top - s->base;
}

int stkmax(stkptr s)
{
	return s->size;
}

/*
 * test 
 */
#include "00prn.h"

STKDATA test_d1 = 1;
STKDATA test_d2 = 7;
STKDATA test_d3 = 222;
STKDATA test_d4;

void inc_data(STKDATA *d)
{
	*d += 1;
}
void prn_data(STKDATA d)
{
	printf("%5.2d", d);
}

void test_stk(void)
{
	stkptr t;
	int i;

	PRN_SEN(t = stkinit(1));
	if (t == 0)
		exit(1);
	printf("--push 1st--");
	stkpush(t, test_d1);
	printf("value: ");
	prn_data(test_d1);
	printf(" stkcount(t), stkmax(t): %3d, %3d\n", stkcount(t), stkmax(t));
	printf("--push 2nd--");
	stkpush(t, test_d2);
	printf("value: ");
	prn_data(test_d2);
	printf(" stkcount(t), stkmax(t): %3d, %3d\n", stkcount(t), stkmax(t));
	PRN_STR(---- stkpush() ---);
	for (i = 0; i < 12; i++)
	{
		stkpush(t, test_d3);
		printf("%3d: ", i + 1);
		prn_data(test_d3);
		printf(" stkcount(t), stkmax(t): %3d, %3d\n", stkcount(t), stkmax(t));
		inc_data(&test_d3);
	}
	PRN_STR(----stkresize()-------);
	PRN_CAL(stkresize(t, 10));
	PRN_FUN(stkmax(t), d);
	PRN_FUN(stkcount(t), d);
	PRN_STR(----stkgetop()-------);
	stkgetop(t, &test_d4);
	printf("stkgetop(t, &test_d4): ");
	prn_data(test_d4);
	printf("\n");
	PRN_STR(----stkgetn()-------);
	for (i = 0; stkgetn(t, &test_d4, i) != 0; i++)
	{
		printf("stkgetn %3d: ", i);
		prn_data(test_d4);
		printf("\n");
	}
	PRN_STR(----stkpop()-------);
	for (i = 0; stkpop(t, &test_d4) != 0; i++)
	{
		printf("pop %3d times: ", i + 1);
		prn_data(test_d4);
		printf("\n");
	}
	PRN_STR(-----stkreset()------);
	PRN_CAL(stkreset(t));
	PRN_FUN(stkcount(t), d);
	PRN_FUN(stkmax(t), d);
	stkfree(t);
}

/*
 * main function
 */

int main(int argc, char *argv[])
{
	test_stk();
	return 0;
}

