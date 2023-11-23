#include <stdio.h>
#include <stdlib.h>
/*
 * a simple stack data structure
 */
#define ST_DEC(name, size, type)		\
type *name##_base, *name##_top;			\
type name##_invalid;						\
int name##_size = size;					\
int name##_init()						\
{										\
	name##_base = (type *) malloc(sizeof(type) * name##_size);	\
	if (name##_base != (type *) 0)		\
	{									\
		name##_top = name##_base;		\
		return name##_size;				\
	}									\
	else								\
		printf("stack init error: malloc return 0.\n");	\
	return 0;							\
}										\
type name##_push(type d)				\
{										\
	if (name##_top - name##_base < name##_size)		\
		*name##_top++ = d;				\
	else								\
		printf("stack push error: stack full.\n");	\
	return d;							\
}										\
type name##_pop(void)					\
{										\
	if (name##_top > name##_base)		\
		return *--name##_top;			\
	else								\
		printf("stack pop error: Stack empty.\n");	\
	return name##_invalid;				\
}										\
void name##_free(void)					\
{										\
	if (name##_base != (type *) 0)		\
		free(name##_base);				\
}										\
type name##_get(void)					\
{										\
	if (name##_top > name##_base)		\
		return *(name##_top - 1);		\
	else								\
		printf("stack get top error: stack empty.\n");	\
	return name##_invalid;				\
}										\
int name##_count(void)				\
{										\
	return name##_top - name##_base;	\
}										\
int name##_remain(void)					\
{										\
	return name##_size - (name##_top - name##_base);	\
}										\
int name##_max(void)					\
{										\
	return name##_size;					\
}										\

/* 
 * data structure
 * stack
 */
#define ST_TYPE int
ST_TYPE 	*st_base, *st_top;
ST_TYPE  	st_invalid;
int 		st_size;
ST_TYPE 	st_init(int size);
ST_TYPE 	st_push(ST_TYPE);
ST_TYPE 	st_pop(void);
ST_TYPE 	st_getop(void);
void		st_free(void);
int 		st_count(void);
int 		st_remain(void);
int 		st_max(void);

int st_init(int size)
{
	st_base = (int *) malloc(sizeof(ST_TYPE) * size);
	if (st_base != (ST_TYPE *) 0)
	{
		st_top = st_base;
		st_size = size;
		return size;
	}
	else
		perror("stack init error: malloc return 0.\n");
	return 0;
}

ST_TYPE st_push(ST_TYPE d)
{
	if (st_top - st_base < st_size)
		*st_top++ = d;
	else
		perror("stack push error: stack full.\n");
	return d;
}

ST_TYPE st_pop(void)
{
	if (st_top > st_base)
		return *--st_top;
	else
		perror("stack pop error: Stack empty.\n");
	return st_invalid;
}

void st_free(void)
{
	if (st_base != (ST_TYPE *) 0)
		free(st_base);
}
int st_get(void)
{
	if (st_top > st_base)
		return *(st_top - 1);
	else
		perror("stack get top error: stack empty.\n");
	return -1;
}
int st_count(void)
{
	return st_top - st_base;
}
int st_remain(void)
{
	return st_size - (st_top - st_base);
}
int st_max(void)
{
	return st_size;
}

#include "00prn.h"

ST_DEC(my, 1, double)

struct aaa
{
	int a;
};

typedef struct aaa BB;
typedef int INT;

ST_DEC(sa, 2, INT)
ST_DEC(sb, 10, BB)

int main(int argc, char *argv[])
{
	PRN_FUN(my_init(), d);
	PRN_FUN(my_push(12.3), f);
	PRN_FUN(my_push(12.2), f);
	PRN_FUN(my_count(), d);
	PRN_FUN(my_remain(), d);
	PRN_FUN(my_pop(), f);
	PRN_FUN(my_pop(), f);
	PRN_STR(----------------);
	PRN_FUN(st_init(100), d);
	PRN_FUN(st_count(), d);
	PRN_FUN(st_remain(), d);
	PRN_FUN(st_push(12), d);
	PRN_FUN(st_count(), d);
	PRN_FUN(st_remain(), d);
	PRN_FUN(st_get(), d);
	PRN_FUN(st_pop(), d);
	PRN_FUN(st_remain(), d);
	PRN_FUN(st_max(), d);
	return 0;
}

/*
 type, name, max_size
 */

