#include <stdio.h>
#include <stdlib.h>
/* 
 * data structure: stack
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
ST_TYPE st_getop(void)
{
	if (st_top > st_base)
		return *(st_top - 1);
	else
		perror("stack get top error: stack empty.\n");
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
int st_max(void)
{
	return st_size;
}

#include "00prn.h"
int main(int argc, char *argv[])
{
	PRN_FUN(st_init(100), d);
	PRN_FUN(st_count(), d);
	PRN_FUN(st_remain(), d);
	PRN_FUN(st_push(12), d);
	PRN_FUN(st_count(), d);
	PRN_FUN(st_remain(), d);
	PRN_FUN(st_getop(), d);
	PRN_FUN(st_pop(), d);
	PRN_FUN(st_remain(), d);
	return 0;
}

/*
 type, name, max_size
 */

