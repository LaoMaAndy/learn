/* dcl.c */
#include "template/head.h"

#define BUF_SIZE 100
int bufn = 0;
char buf[BUF_SIZE];
static int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
static void ungetch(int c)
{
	if (bufp >= BUF_SIZE)
		printf("Out of buf\n");
	else
		buf[bufp++] = c;
}

#define STACK_SIZE 4096
int stack_top = 0;
int stack[STACK_SIZE];

static void Push(int c)
{
	if (stack_top < STACK_SIZE)
		stack[stack_top++] = c;
	else
		printf("Push() error. overflow\n");
}
static int Pop()
{
	if (stack_top > 0)
		return stack[--stack_top];
	printf("")

}