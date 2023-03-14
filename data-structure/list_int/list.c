#include "list.h"

struct node
{
	elem val;
	struct node *next, *prev;
};
/*-----list Operation-------------*/
node *Head(list *s)
{
	return s;
}
node *First(list *s)
{
	return Next(s);
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
node *Insert(list *s, node *p, elem v)
{
	node *newp;

	newp = NewNode(v);
	SetNext(newp, Next(p));
	SetNext(p, newp);
	SetPrev(Next(newp), newp);
	SetPrev(newp, p);
	return newp;
}
list *NewList(void)
{
	list *s;

	s = NewNode(MakeElem(-1));
	return s;
}
void DelNext(list *s, node *p)
{
	node *temp;

	if (Next(p) == Head(s))
		return ;
	temp = Next(p);
	SetNext(p, Next(Next(p)));
	SetPrev(Next(p), p);
	FreeNode(temp);
}
node *DelCurNode(list *s, node *p)
{
	node *r;	

	if (p == Head(s))
		return Next(p);
	SetNext(Prev(p), Next(p));
	SetPrev(Next(p), Prev(p));
	r = Next(p);
	FreeNode(p);
	return r;
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
}
list *DupList(list *s)
{
	list *newp;
	node *dest, *src, *new_node;

	newp = NewList();
	for (dest = Head(newp), src = First(s); src != Head(s); src = Next(src), dest = Next(dest))
		Insert(newp, dest, NodeElem(src));
	printf("DuoList OK\n");
	return newp;
}
list *MakeList(elem *v, int n)
{
	list *s;
	node *p;
	int i;

	s = NewList();
	for (i = 0, p = Head(s); i < n; ++i, p = Next(p))
		Insert(s, p, MakeElem(v[i]));
	return s;
}
void PrnList(list *s)
{
	node *p;
	int i = 0;

	printf("----Print List-------\n");
	p = Head(s);
	PrnNode(p, -1);
	for (p = First(s); p != Head(s); p = Next(p), ++i)
	{
		PrnNode(p, i);
	}
	printf("Node Count: %3d\n\n", Count(s));
}

node *Find(list *s, elem v)
{
	return Next(FindPre(s, v));
}
node *FindPre(list *s, elem v)
{
	node *p;

	if (!IsEmpty(s))
		for (p = Head(s); !IsLast(s, p); p = Next(p))
			if (ElemComp(NodeElem(Next(p)), v) == 0)
				return p;
	return NULL;
}
void DelNode(list *s, elem v)
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

/*-----node Operation-------------*/
node *NewNode(elem e)
{
	node *p;

	p = (node *) malloc(sizeof(*p));
	if (p == NULL)
		Exit("malloc() return NULL");
	p->val = e;
	SetNext(p, p);
	SetPrev(p, p);
	return p;
}
void FreeNode(node *p)
{
	free(p);
}
node *Next(node *s)
{
	return s->next;
}
node *Prev(node *s)
{
	return s->prev;
}
void SetNext(node *p, node *next_p)
{
	p->next = next_p;
}
void SetPrev(node *p, node *prev_p)
{
	p->prev = prev_p;
}
elem NodeElem(node *p)
{
	return p->val;
}
void PrnNode(node *p, int id)
{
	if (id == -1)
		printf("[%5s]", "head");
	else
		printf("[%5d] ", id);
	printf("Addr:%15p, ", p);
	printf("Next:%15p, ",Next(p));
	printf("Prev:%15p, ",Prev(p));
	ElemPrn(NodeElem(p));
	printf("\n");
}
void NodeProc(node *p)
{
	p->val *= 2;
}
/* --------- elem ------------ */
void ElemPrn(elem e)
{
	printf("Val: %5d", e);
}
elem MakeElem(int i)
{
	return i;
}
int ElemComp(elem x, elem y)
{
	return (x - y);
}
elem *MakeElems(int index[], int n)
{
	elem *p;
	int i;

	p = (elem *) malloc(n * sizeof (*p));
	if (p == NULL)
		Error("malloc() return NULL");
	for (i = 0; i < n; ++i)
		p[i] = MakeElem(index[i]);
	return p;
}
