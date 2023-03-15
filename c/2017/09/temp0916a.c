/*
 * data structure: stack, 10
 */

#define STKD float

typedef struct stk_info
{
	STKD *top, *base;
	int size;
} stkhead;


stkhead *stkinit(int n);
int		stkresize(stkhead *s, int n);
int 	stkpush(stkhead *s, STKD d);
int 	stkpop(stkhead *s, STKD *dp);
int 	stkgetop(stkhead *s, STKD *dp);
int 	stkgetn(stkhead *s, STKD *dp, int n);
void 	stkfree(stkhead *s);
void 	stkreset(stkhead *s);
int 	stkcount(stkhead *s);
int 	stkmax(stkhead *s);

/*
 * implementation
 */
#include <stdlib.h> 	/* need malloc(), realloc() */

stkhead *stkinit(int n)
{
	stkhead *p;

	p = (stkhead *) malloc(sizeof(stkhead));
	if (p == 0)
		return (stkhead *) 0;
	p->base = (STKD *) malloc(n * sizeof(STKD));
	if (p->base == 0)
	{
		free(p);
		return (stkhead *) 0;
	}
	p->top = p->base;
	p->size = n;
	return p; 
}

int stkresize(stkhead *s, int n)
{
	STKD *temp;
	int i;

	temp = (STKD *) realloc(s->base, n * sizeof(STKD));
	if (temp == 0)
		return 0;
	i = s->top - s->base;
	if (i > n) 
		i = n;
	s->base = temp;
	s->top = temp + i;
	s->size = n;
}

int stkpush(stkhead *s, STKD d)
{
	if (s->top - s->base + 1 > s->size)
		if (!stkresize(s, 2 * s->size))
			return 0;
	*s->top++ = d;
	return 1;
}

int stkpop(stkhead *s, STKD *d)
{
	if (s->top <=  s->base)
		return 0;
	*d = *--s->top;
	return 1;
}

int stkgetop(stkhead *s, STKD *d)
{
	if (s->top <= s->base)
		return 0;
	*d = *(s->top - 1);
	return 1;
}

int stkgetn(stkhead *s, STKD *d, int n)
{
	if (s->top - n <= s->base)
		return 0;
	*d = *(s->top - n - 1);
	return 1;
}

void stkfree(stkhead *s)
{
	if (s->base != 0)
		free(s->base);
	free(s);
}

void stkreset(stkhead *s)
{
	s->top = s->base;
}

int stkcount(stkhead *s)
{
	return s->top - s->base;
}

int stkmax(stkhead *s)
{
	return s->size;
}


/*
 * test 
 */
#include "00prn.h"

STKD test_d1 = 1.0;
STKD test_d2 = 7.0;
STKD test_d3 = 222.33;
STKD test_d4;

void inc_data(STKD *d)
{
	*d += 2;
}
void prn_data(STKD d)
{
	printf("%5.2f", d);
}

void test_stk(void)
{
	stkhead *t;
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

