/* list.h */
#ifndef _LIST_COMMON_HEAD_FILE_
#define _LIST_COMMON_HEAD_FILE_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../error/error.h"
#include "../elem/elem.h"

/* node type can defined by user*/
struct node;
typedef struct node node;

/* user who defined node type, must implement these functions */
int NodeSize(void);
node *NewNode(elem *e);
void  FreeNode(node *p);
elem *NodeElem(node *s);
node *SetNodeElem(node *p, elem *v);
node *Next(node *s);
void SetNext(node *p, node *next_p);
void PrnNode(node *p, int id);

/* These functions different from vary implementation */
/* new/free a list/node*/
struct header;
typedef struct header list;

int  ListHeaderSize(void);
list *NewList(void);
void  FreeList(list *s);
void  DelList(list *s);
list *MakeList(elem_ptr *v, int n);
list *DupList(list *s);

/* return list information */
int IsEmpty(list *s);
int IsLast(list *s, node *p);

/* basic oprate */
node *First(list *s);
node *Head(list *s);
node *Last(list *s);

/* These functions are same even though different implementation */
/* find, insert, delete */
node *Find(list *s, elem *v);
node *FindPre(list *s, elem *v);
void DelNode(list *s, elem *v);
void DelNext(list *s, node *p);
node *DelCurNode(list *s, node *p);
node *Insert(list *s, node *p, elem *v);
void Traverse(list *s, void func(node *));

/* information print, debug */
void PrnList(list *s);
int  Count(list *s);

//void Swap(list *s, node *i, node *j);

#endif
