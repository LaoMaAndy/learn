/* list and operate */
#include "../list/list.h"

list *ListAnd(list *a, list *b)
{
	list *c;
	node *ap, *bp, *cp;

	c = NewList();
	ap = First(a);
	bp = First(b);
	cp = Head(c);

	for ( ; ap != Head(a) && bp != Head(b); )
	{
		if (ElemComp(NodeElem(ap), NodeElem(bp)) < 0)
		{
			ap = Next(ap);
			continue;
		}
		else if (ElemComp(NodeElem(ap), NodeElem(bp)) > 0)
		{
			bp = Next(bp);
			continue;
		}
		else
		{
			Insert(c, cp, NodeElem(ap));
			cp = Next(cp);
			ap = Next(ap);
			bp = Next(bp);
		}
	}
	return c;
}
void test_and(void)
{
	list *s, *t;
	int v1[] = {1, 3, 4, 6, 12, 20};
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

	list *c = ListAnd(s, t);
	PrnList(c);
}

int main()
{
	test_and();
	return 0;
}