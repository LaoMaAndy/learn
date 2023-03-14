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
	return newp;
}
void DelNext(list *s, node *p)
{
	node *temp;

	temp = Next(p);
	SetNext(p, Next(Next(p)));
	FreeNode(temp);
}
node *DelCurNode(list *s, node *cur)
{
	node *p, *r;

	if (cur == Head(s))
		return Next(cur);
	for (p = First(s); p != Head(s); p = Next(p))
		if (Next(p) == cur)
			break;
	if (Next(p) == Head(s))
		return Next(p);
	r = Next(cur);
	DelNext(s, p);
	return r;
}
