/*
 * data structure: stack
 st: stack. 
 sl: sequence list
 cl: circular linked list
 dl: double linked list
 sc: single chain list
 dc: double chain list
 bt: binary tree

 sequence list
 chain list
 stack
 queue
 binary tree
 ...
 */

#define ST_TYPE int

ST_TYPE		*st_base, *st_top;
ST_TYPE		st_invalid;
int 		st_size;
int			st_init(int size);
ST_TYPE		st_push(ST_TYPE d);
ST_TYPE		st_pop(void);
ST_TYPE		st_getop(void);
void		st_free(void);
int 		st_count(void);
int 		st_remain(void);

/*
 * implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
		perror("Stack error: init, malloc return 0.\n");
	return 0;
}

ST_TYPE st_push(ST_TYPE d)
{
	if (st_top - st_base < st_size)
		*st_top++ = d;
	else
		perror("Stack error: push, full.\n");
	return d;
}

ST_TYPE st_pop(void)
{
	if (st_top > st_base)
		return *--st_top;
	else
		perror("Stack error: pop, empty.\n");
	return st_invalid;
}

ST_TYPE st_getop(void)
{
	if (st_top > st_base)
		return *(st_top - 1);
	else
		perror("Stack error: getop, empty.\n");
	return st_invalid;
}

void st_free(void)
{
	if (st_base != (ST_TYPE *) 0)
		free(st_base);
}

int st_count(void)
{
	return st_top - st_base;
}

int st_remain(void)
{
	return st_size - (st_top - st_base);
}

/*
 * test 
 */

#include "00prn.h"
void test_stack(void)
{
	int i;

	PRN_FUN(st_init(10), d);
	for (i = 0; i <= st_size; i++)
		PRN_FUN(st_push(i), d);
	PRN_STR(---------------);
	PRN_FUN(st_getop(), d);
	PRN_FUN(st_count(), d);
	PRN_FUN(st_remain(), d);
	PRN_STR(--------------);
	for (i = 0; i <= st_size; i++)
		PRN_FUN(st_pop(), d);
	
	st_free();
}

/*
 * main function
 */

int main(int argc, char *argv[])
{
	test_stack();

	return 0;
}

