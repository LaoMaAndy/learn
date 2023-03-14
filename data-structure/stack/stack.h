/* stack.h */
#ifndef _STACK_HEAD_
#define _STACK_HEAD_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../error/error.h"

typedef int elem;
int ElemSize(void);
void ElemCopy(elem *dest, elem *src);

struct stack;
typedef struct stack stack;

stack *NewStack(void);
elem Top(stack *s);
elem Pop(stack *s);
void Push(stack *s, elem e);
int IsEmpty(stack *s);

int StackSize(stack *s);
int StackCap(stack *s);
void DelStack(stack *s);
void FreeStack(stack *s);
static void ExpandStack(stack *s);

#endif