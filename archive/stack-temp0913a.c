/*
 * prototype. data structure: stack (stk)
 */
/*
 * 由于使用了 void *类型，编译时， 需要添加 gcc -Wpointer-arith 选项
 *   对void *类型的算数运算进行警告.
 *  由于 gcc 默认将void * 和 char * 同等看待，
 *  因此在默认情况下，gcc对于void *的算数运算，没有提示信息。
 */

typedef struct stk_info
{
	void *base, *top;
	int unit, size;
} *stkptr;

stkptr stkinit(int n, int unit);
void *stkpush(stkptr s, void *d);
void *stkpop(stkptr s);
int  stkpopc(stkptr s, void *dest);
void *stkgetop(const stkptr s);
void *stkgetn(const stkptr s, int n);
void stkfree(stkptr s);
int  stkreset(stkptr s);
int  stkresize(stkptr s, int n);
int  stkcount(const stkptr s);
int  stkmax(const stkptr s);
int  stkise(const stkptr s);

/*
 *implementation
 */
#include <stdlib.h>		/* need malloc(), realloc(), free() */
#include <stdio.h>		/* need fprintf() */

stkptr stkinit(int n, int unit)
{
	stkptr s;

	s = (stkptr)malloc(sizeof(stkptr));
	if (s == 0)
		return (stkptr) 0;
	s->base = malloc(n * unit);
	if (s->base == 0)
	{
		free(s);
		return (stkptr) 0;
	}
	s->top = s->base;
	s->unit = unit;
	s->size = n * unit;
	return  s;
}

void *stkpush(stkptr s, void *data)
{
	char *top = (char *)s->top;
	char *base = (char *)s->base;
	char *temp;
	char *d = (char *)data;
	int unit = s->unit;

	if (top - base + unit > s->size)
	{
		temp = (char *)realloc(base, s->size << 1);
		if (temp == 0)
		{
			fprintf(stderr, "Stack error. %s : realloc return 0.\n", __func__);
			return data;
		}
		top = temp + (top - base);
		s->base = temp;
		s->size <<= 1;
	}
	while(unit-- > 0)
		*top++ = *d++;
	s->top = top;
	return  data;
}

void *stkpop(stkptr s)
{
	char *top = s->top;

	if (top <= (char *)s->base)
		return (void *) 0;
	top -= s->unit;
	s->top = top;
	return top;
}

int stkpopc(stkptr s, void *dest)
{
	char *top = s->top;
	char *d = dest;
	int unit = s->unit;
	
	if (top <= (char *)s->base)
		return 0;
	top -= unit;
	while (unit-- > 0)
		*d++ = *top++;
	s->top = top - unit;
	return unit;
}

void *stkgetop(const stkptr s)
{
	void *p = (char *)s->top - s->unit;
	return p >= s->base ? p : (void *) 0;
}

void *stkgetn(const stkptr s, int n)
{
	void *p = (char *)s->top - (n + 1) * s->unit;
	return p >=  s->base ?  p : (void *) 0;
}

void stkfree(stkptr s)
{
	if (s->base != 0)
		free(s->base);
	free(s);
}

int stkreset(stkptr s)
{
	s->top = s->base;
	return 1;
}

int stkresize(stkptr s, int n)
{
	char *p = (char *)realloc(s->base, s->unit * n);
	if (p == 0)
	{
		fprintf(stderr, "stack error. %s : realloc return 0.\n", __func__);
		return 0;
	}
	s->top = (char *)s->top - (char *)s->base + p;
	s->base = p;
	s->size = n * s->unit;
	return n;
}

int stkcount(const stkptr s)
{
	return ((char *)s->top - (char *)s->base) / s->unit;
}

int stkmax(const stkptr s)
{
	return s->size / s->unit;
}

int stkise(const stkptr s)
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
	stkptr t;
	info i, j;

	t = stkinit(1, sizeof(info));
	i.a = 12;
	i.b = 'a';
	j.a = 0;
	j.b = 'z';
	stkpush(t, &i);
	//j = *(info *)stkpop(t);
	stkpopc(t, &j);
	printf("struct j.a: %d\n", j.a);
	printf("struct j.b: %c\n", j.b);
	stkfree(t);
}

void test_stk2(void)
{
	stkptr buffer;

	buffer = stkinit(1, sizeof(char));
	if (buffer == 0)
		exit(1);
	
}
#define TTYPE char
void test_stk(void)
{
	stkptr t;
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
	printf("stkptr count %c\n", stkcount(t));
	printf("---------------\n");
	i = 0;
	void *p;
	while ((p = stkgetn(t, i)) != (void *) 0)
		printf("getn(%d): %c\n", i++, *(TTYPE *)p);
	i = 0;
	while (!stkise(t))
		printf("pop %d times: %c\n", ++i, *(TTYPE *)stkpop(t));
	printf("\n");
	stkfree(t);
}

int main(int argc, char *argv[])
{
	test_stk();
	return 0;
}
