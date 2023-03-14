/* exercise 3.5.c */
#include "../list/list.h"

list *ListOR(list *a, list *b)
{
	list *c;
	node *ap, *bp, *cp;

	c = NewList();
	ap = First(a);
	bp = First(b);
	cp = Head(c);

	for ( ; ap != Head(a) && bp != Head(b); cp = Next(cp))
	{
		if (ElemComp(NodeElem(ap), NodeElem(bp)) < 0)
		{
			Insert(c, cp, NodeElem(ap));
			ap = Next(ap);
			continue;
		}
		else if (ElemComp(NodeElem(ap), NodeElem(bp)) > 0)
		{
			Insert(c, cp, NodeElem(bp));
			bp = Next(bp);
			continue;
		}
		else
		{
			Insert(c, cp, NodeElem(ap));
			ap = Next(ap);
			bp = Next(bp);
		}
	}
	for ( ; ap != Head(a); ap = Next(ap))
	{
		Insert(c, cp, NodeElem(ap));
		cp = Next(cp);
	}
	for ( ; bp != Head(b); bp = Next(bp))
	{
		Insert(c, cp, NodeElem(bp));
		cp = Next(cp);
	}
	return c;
}

void test_or(void)
{
	list *s, *t;
	int v1[] = {0, 3, 4, 6, 12, 20, 21};
	int n1 = sizeof(v1) / sizeof(*v1);
	int v2[] = {1, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int n2 = sizeof(v2) / sizeof(*v2);
	elem_ptr *e1, *e2;
	int i = 1;

	e1 = MakeElems(v1, v1, n1);
	e2 = MakeElems(v2, v2, n2);
	s = MakeList(e1, n1);
	t = MakeList(e2, n2);
	PrnList(s);
	PrnList(t);

	list *c = ListOR(s, t);
	PrnList(c);
}
int main()
{
	test_or();
	return 0;
}