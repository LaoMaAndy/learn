#include "list.h"

/* user function */
void test_list()
{
	int vint[] = {12, 483, 41, 5, 1, 23, 5, 7, 9, 21, 35, 6, -1, 34};
	int n = sizeof(vint) / sizeof(*vint);
	elem_ptr *v;
	list *s1, *s2;
	int i;
	node *p, *p1, *p2;

	v = MakeElems(vint, vint, n);
	for (i = 0; i < n; ++i)
	{
		ElemPrn(v[i]);
		printf("\n");
	}
	s1 = MakeList(v, n);
	printf("\n----------\n");
	s2 = DupList(s1);
	PrnList(s1);
	PrnList(s2);
	printf("--------DupList s1, s2 OK--------- \n");
	elem *d = MakeElem(41, 0, "aaa", "bbb");
	ElemPrn(d);
	printf("\n");
	p = Find(s1, d);
	if (p == NULL)
		Exit("P is NULL");
	PrnNode(p, 111);
	printf("\n");
	p1 = FindPre(s1, d);
	PrnNode(p1, 112);
	DelNode(s1, d);
	printf("\n");
	PrnList(s1);
	printf("--------DelNode(), 41 --------- \n");


	void NodeProc(node *p);
	Traverse(s2, NodeProc);
	PrnList(s2);
	printf("--------Traverse(), Elem Double--------- \n");

	p = First(s2);
	p2 = DelCurNode(s2, p);
	PrnList(s2);
	printf("--------DelCurNode(), Remove First Node --------- \n");	
	printf("Return node: ");
	PrnNode(p2, 0);

	for (p = First(s2); Next(p) != Head(s2); p = Next(p))
		;
	p2 = DelCurNode(s2, p);
	PrnList(s2);
	printf("--------DelCurNode(), Remove Last Node --------- \n");	
	printf("Return node: ");
	PrnNode(p2, 0);

	DelList(s2);
	PrnList(s2);
	printf("--------DelList() --------- \n");
}

int main()
{
	test_list();

	return 0;
}

