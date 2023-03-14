/* list.c */
#include "list.h"

struct header
{
	int size;
	node *dumb;
};
node *Head(list *s)
{
	return s->dumb;
}
node *First(list *s)
{
	return Next(s->dumb);
}
node *Last(list *s)
{
	node *p;

	for (p = First(s); p != NULL; p = Next(p))
		;
	return p;
}
int IsEmpty(list *s)
{
	return (Next(Head(s)) == NULL);
}
int IsLast(list *s, node *p)
{
	return (Next(p)== NULL);
}
list *NewList(void)
{
	list *s;

	s = (list *) malloc(sizeof(*s));
	if (s == NULL)
		Exit("malloc() return NULL");
	s->dumb = NewNode(NULL);
	return s;
}
void FreeList(list *s)
{
	node *p;

	for (p = First(s); p != NULL; p = Next(p))
		FreeNode(p);
	free(s);
}
node *Insert(list *s, node *p, elem *v)
{
	node *newp;

	if ((newp = NewNode(v)) == NULL)
		Exit("NewNode() return NULL");
	SetNext(newp, Next(p));
	SetNext(p, newp);
	return newp;
}
list *DupList(list *s)
{
	list *newp;
	node *dest, *src, *new_node;

	if ((newp = NewList()) == NULL)
		Exit("NewList() return NULL");
	for (dest = Head(newp), src = First(s); src != NULL; src = Next(src), dest = Next(dest))
		Insert(newp, dest, NodeElem(src));
	return newp;
}
list *MakeList(elem_ptr *v, int n)
{
	list *s;
	node *p;
	int i;

	s = NewList();
	for (i = 0, p = Head(s); i < n; ++i, p = Next(p))
		Insert(s, p, v[i]);
	return s;
}
void PrnList(list *s)
{
	node *p;
	int i = 0;

	printf("----Print List-------\n");
	printf("[%4s] ", "head");
	printf("Node  Addr:%15p, ", Head(s));
	printf("Next  Addr:%15p"  , Next(Head(s)));
	printf("\n");
	//PrnNodeId(Head(s), -1);
	for (p = First(s); p != NULL; p = Next(p), ++i)
	{
		PrnNodeId(p, i);
	}
	printf("Node Count: %3d\n\n", Count(s));
}

node *Find(list *s, elem *v)
{
	return Next(FindPre(s, v));
}
node *FindPre(list *s, elem *v)
{
	node *p;

	if (!IsEmpty(s))
		for (p = Head(s); !IsLast(s, p); p = Next(p))
			if (ElemComp(NodeElem(Next(p)), v) == 0)
				return p;
	return NULL;
}
void DelNode(list *s, elem *v)
{
	node *p;

	p = FindPre(s, v);
	if (p != NULL)
		DelNext(s, p);
}
void DelNext(list *s, node *p)
{
	node *temp;

	temp = Next(p);
	SetNext(p, Next(Next(p)));
	if (Next(p) != NULL)
		SetPrev(Next(p), p);
	FreeNode(temp);
}
int Count(list *s)
{
	node *p;
	int i = 0;

	for (i = 0, p = First(s); p != NULL; p = Next(p))
		++i;
	return i;
}
void DelList(list *s)
{
	node *p, *temp;

	for (p = First(s); p != NULL; p = temp)
	{
		temp = Next(p);
		FreeNode(p);
	}
	SetNext(Head(s), NULL);
}
void Traverse(list *s, void func(node *))
{
	node *p;

	for (p = First(s); p != NULL; p = Next(p))
		func(p);
}
