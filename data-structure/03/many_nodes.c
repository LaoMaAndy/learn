/* many nodes */
#include "../list/list.h"

void test_many_nodes(void)
{
	int max = 100000;
	int i;
	list *s;
	node *p;
	elem *e;

	s = NewList();
	p = Head(s);

	for (i = 0; i < max; ++i)
	{
		e = MakeElem(i, 0, "aaa", "bbb");
		Insert(s, p, e);
		p = Next(p);
	}
	PrnList(s);
	DelList(s);
	FreeList(s);
}
int main()
{
	test_many_nodes();
	return 0;
}