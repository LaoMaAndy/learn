/*
 * prototype. data structure: stack (stk)
 */

struct stkinfo
{
	void *base, *top;
	int unit, size;
};
typedef struct stkinfo stktype;

stktype *stkinit(int n, int unit);
void *stkpush(stktype *s, const void *d);
void *stkpop(stktype *s);
void *stkpopc(stktype *s, void *dest);
void *stkgetop(const stktype *s);
void *stkgetn(const stktype *s, int n);
void stkfree(stktype *s);
int  stkreset(stktype *s);
int  stkresize(stktype *s, int n);
int  stkcount(const stktype *s);
int  stkmax(const stktype *s);
int  stkise(const stktype *s);

/*
 *implementation
 */
#include <stdlib.h>		/* need malloc(), realloc(), free() */

stktype *stkinit(int n, int unit)
{
	stktype *s;

	s = (stktype *)malloc(sizeof(stktype));
	if (s == 0)
		return (stktype *) 0;
	s->base = malloc(n * unit);
	if (s->base == 0)
	{
		free(s);
		return (stktype *) 0;
	}
	s->top = s->base;
	s->unit = unit;
	s->size = n * unit;
	return  s;
}

void *stkpush(stktype *s, const void *data)
{
	if (s->top - s->base + s->unit > s->size)
	{
		void *t = realloc(s->base, s->size << 1);
		if (t == 0)
			return (void *) data;
		s->top = t + (s->top - s->base);
		s->base = t;
		s->size <<= 1;
	}
	for (int i = 0; i < s->unit; i++)
		((char *) s->top)[i] = ((char *) data)[i];
	s->top += s->unit;
	return (void *) data;
}

void *stkpop(stktype *s)
{
	if (s->top <= s->base)
		return (void *) 0;
	s->top -= s->unit;
	return s->top;
}

void *stkpopc(stktype *s, void *dest)
{
	int i;
	
	if (s->top <= s->base)
		return (void *) 0;
	s->top -= s->unit;
	for (i = 0; i < s->unit; i++)
		((char *)dest)[i] = ((char *)s->top)[i];
}

void *stkgetop(const stktype *s)
{
	void *p = s->top - s->unit;
	return p >= s->base ? p : (void *) 0;
}

void *stkgetn(const stktype *s, int n)
{
	void *p = s->top - (n + 1) * s->unit;
	return p >= s->base ? p : (void *) 0;
}

void stkfree(stktype *s)
{
	if (s->base != 0)
		free(s->base);
	free(s);
}

int stkreset(stktype *s)
{
	s->top = s->base;
	return 1;
}

int stkresize(stktype *s, int n)
{
	void *p = realloc(s->base, s->unit * n);
	if (p == 0)
		return 0;
	s->top = s->top - s->base + p;
	s->base = p;
	s->size = n * s->unit;
	return n;
}

int stkcount(const stktype *s)
{
	return (s->top - s->base) / s->unit;
}

int stkmax(const stktype *s)
{
	return s->size / s->unit;
}

int stkise(const stktype *s)
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
	stktype *t;
	info i, j;

	t = stkinit(1, sizeof(info));
	i.a = 12;
	i.b = 'a';
	j.a = 0;
	j.b = 'z';
	stkpush(t, &i);
	j = *(info *)stkpop(t);
	printf("struct j.a: %d\n", j.a);
	printf("struct j.b: %c\n", j.b);
	stkfree(t);
}

void test_stk2(void)
{
	stktype *buffer;

	buffer = stkinit(1, sizeof(char));
	if (buffer == (stktype *) 0)
		exit(1);
	
}
#define TTYPE char
void test_stk(void)
{
	stktype *t;
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
	printf("stktype count %c\n", stkcount(t));
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
