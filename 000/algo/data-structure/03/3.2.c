/* exercise 3.2 */
#include "../list/list.h"

void e03_02(void)
{
	list *s, *t;
	int v1[] = {1, 3, 4, 6};
	int n1 = sizeof(v1) / sizeof(*v1);
	int v2[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int n2 = sizeof(v2) / sizeof(*v2);
	elem_ptr *e1, *e2;
	int i = 1;

	e1 = MakeElems(v1, v1, n1);
	e2 = MakeElems(v2, v2, n2);
	s = MakeList(e1, n1);
	t = MakeList(e2, n2);

	PrnList(s);
	PrnList(t);
	node *p, *q;
	q = First(t);
	i = 1;
	for (p = First(s); p != Head(s); p = Next(p))
	{
		for ( ; i < ElemIndex(NodeElem(p)); ++i, q = Next(q))
			;
		PrnNode(q, i);
	}
}
int main()
{
	e03_02();
	return 0;
}