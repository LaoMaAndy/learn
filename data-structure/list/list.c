/* list.c */
#include "list.h"

struct header
{
	int size;  		//never used
	node *dumb;
};
int ListHeaderSize(void)
{
	return sizeof(struct header);
}
list *NewList(void)
{
	list *s;

	s = (list *) malloc(ListHeaderSize());
	if (s == NULL)
		Exit("malloc() return NULL");
	s->dumb = NewNode(NULL);
	return s;
}
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

	for (p = First(s); p != Head(s); p = Next(p))
		;
	return p;
}
int IsEmpty(list *s)
{
	return (Next(Head(s)) == Head(s));
}
int IsLast(list *s, node *p)
{
	return (Next(p)== Head(s));
}

void FreeList(list *s)
{
	node *p, *temp;

	for (p = First(s); p != Head(s); p = temp)
	{
		temp = Next(p);
		FreeNode(p);
	}
	FreeNode(Head(s));
	free(s);
}
list *DupList(list *s)
{
	list *newp;
	node *dest, *src, *new_node;

	if ((newp = NewList()) == NULL)
		Exit("NewList() return NULL");
	for (dest = Head(newp), src = First(s); src != Head(s); src = Next(src), dest = Next(dest))
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
	p = Head(s);
	PrnNode(p, -1);
	//PrnNodeId(Head(s), -1);
	for (p = First(s); p != Head(s); p = Next(p), ++i)
	{
		PrnNode(p, i);
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
int Count(list *s)
{
	node *p;
	int i = 0;

	for (i = 0, p = First(s); p != Head(s); p = Next(p))
		++i;
	return i;
}
void DelList(list *s)
{
	node *p, *temp;

	for (p = First(s); p != Head(s); p = temp)
	{
		temp = Next(p);
		FreeNode(p);
	}
	SetNext(Head(s), Head(s));
}
void Traverse(list *s, void func(node *))
{
	node *p;

	for (p = First(s); p != Head(s); p = Next(p))
		func(p);
}
