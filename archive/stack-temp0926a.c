/*
 * data structure
 */
#include <stdlib.h>

#define VCTD double
#define VCD_INIT_SIZE 512

typedef struct vct_info
{
	VCTD *base;
	int cur, size;
} vct;

vct *vctinit(int n)
{
	vct *p;

	p = (vct *) malloc(sizeof(vct));
	if (p == 0)
		return (vct *) 0;
	if (n == 0)
		n = VCD_INIT_SIZE;
	p->base = (VCTD *) malloc (n * sizeof(VCTD));
	if (p->base == 0)
	{
		free(p);
		return 0;
	}
	p->cur = 0;
	p->size = n;
	return p;
}
	
int vctresize(vct *v, int n)
{
	VCTD *dp;
	int i;

	dp = (VCTD *) realloc(v->base, n * sizeof(VCTD));
	if (dp == 0)
		return 0;
	v->base = dp;
	if (v->cur > n)
		v->cur = n;
	v->size = n;
	return 1;
}

int vctapd(vct *v, VCTD d)
{
	if (v->cur > v->size)
		if (!vctresize(v, v->size * 2))
			return 0;
	*(v->base + v->cur++) = d;
	return 1;
}
		
int vctail(vct *v, VCTD *dp)
{
	if (v->cur > 0)
	{
		*dp = *(v->base + --v->cur);
		return 1;
	}
	return 0;
}

int vctset(vct *v, int n, VCTD d);
int vctget(vct *v, int n, VCTD *dp);
int vctins(vct *v, int n, VCTD d);
int vctdel(vct *v, int n);
int vctsets(vct *v, int start, int n, VCTD d);
int vctdels(vct *v, int start, int n);
int vctinss(vct *v, int start, int n, VCTD d);
void vctfree(vct *v);
void vctreset(vct *v);
int vctcur(vct *v);
int vctsetcur(vct *v);
int vctmax(vct *v);

/*
 * data structure: stack
 */
#include <stdlib.h>
#define STKD int
typedef struct stk_info
{
	STKD *top, *base;
	int size;
} stk;
stk *stkinit(int n);
int stkresize(stk *s, int n);
int stkpush(stk *s, STKD d);
int stkpop(stk *s, STKD *dp);
int stkgetop(stk *s, STKD *dp);
int stkgetn(stk *s, STKD *dp, int n);
void stkfree(stk *s);
void stkreset(stk *s);
void stkreset(stk *s);
int stkcount(stk *s);
int stkmax(stk *s);


stk *stkinit(int n)
{
	stk *p; 

	p = (stk *) malloc(sizeof(stk));
	if (p == 0)
		return (stk *) 0;
	p->base = (STKD *) malloc (n * sizeof(STKD));
	if (p->base == 0)
	{
		free(p);
		return (stk *) 0;
	}
	p->top = p->base;
	p->size = n;
	return p;
}

int stkresize(stk *s, int n)
{
	STKD *dp;
	int i;
	
	dp = (STKD *) realloc(s->base, n * sizeof(STKD));
	if (dp == 0)
		return 0;
	i = s->top - s->base;
	if (i > n)
		i = n;
	s->base = dp;
	s->top = dp + i;
	s->size = n;
	return n;
}

int stkpush(stk *s, STKD d)
{
	if (s->top - s->base >= s->size)
		if (!stkresize(s, s->size *2))
			return 0;
	*s->top++ = d;
	return 1;
}

int stkpop(stk *s, STKD *dp)
{
	if (s->top > s->base)
	{
		*dp = *--s->top;
		return 1;
	}
	return 0;
}

int stkgetop(stk *s, STKD *dp)
{
	if (s->top > s->base)
	{
		*dp = *(s->top - 1);
		return 1;
	}
	return 0;
}

int stkgetn(stk *s, STKD *dp, int n)
{
	if (s->top - n > s->base)
	{
		*dp = *(s->top - 1 - n);
		return 1;
	}
	return 0;
}

void stkfree(stk *s)
{
	if (s->base != 0)
		free(s->base);
	free(s);
}

void stkreset(stk *s)
{
	s->top = s->base;
}

int stkcount(stk *s)
{
	return s->top - s->base;
}

int stkmax(stk *s)
{
	return s->size;
}


/*
 * test 
 */
#include "00prn.h"

STKD test_d1 = 1;
STKD test_d2 = 7;
STKD test_d3 = 222;
STKD test_d4;

void inc_data(STKD *d)
{
	*d += 1;
}
void prn_data(STKD d)
{
	printf("%5.2d", d);
}

void test_stk(void)
{
	stk *t;
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


