/* list_double.c */
#include "list.h"
#include "list_double.h"

node *Insert(list *s, node *p, elem *v)
{
	node *newp;

	if ((newp = NewNode(v)) == NULL)
		Exit("NewNode() return NULL");
	SetNext(newp, Next(p));
	SetNext(p, newp);
	SetPrev(Next(newp), newp);
	SetPrev(newp, p);
	return newp;
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