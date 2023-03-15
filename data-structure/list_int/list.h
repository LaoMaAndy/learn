/* list.h */
#ifndef _LIST_INT_HEAD_FILE_
#define _LIST_INT_HEAD_FILE_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../error/error.h"

// data structure and function to elem
typedef int elem;
void ElemPrn(elem e);
int ElemComp(elem x, elem y);
elem MakeElem(int i);
elem *MakeElems(int index[], int n);

// Data structure and function to node
typedef struct node node;
elem NodeElem(node *p);
void PrnNode(node *p, int id);
void SetPrev(node *p, node *prev_p);
void SetNext(node *p, node *next_p);
node *Prev(node *s);
node *Next(node *s);
node *NewNode(elem e);
void FreeNode(node *p);
void NodeProc(node *p);

// data structure and function to list
typedef struct node list;
node *Head(list *s);
node *First(list *s);
node *Last(list *s);
int IsEmpty(list *s);
int IsLast(list *s, node *p);
node *Insert(list *s, node *p, elem v);
list *NewList(void);
void DelNext(list *s, node *p);
node *DelCurNode(list *s, node *p);
void FreeList(list *s);
list *DupList(list *s);
list *MakeList(elem *v, int n);
void PrnList(list *s);
node *Find(list *s, elem v);
node *FindPre(list *s, elem v);
void DelNode(list *s, elem v);
int Count(list *s);
void DelList(list *s);
void Traverse(list *s, void func(node *));

#endif
