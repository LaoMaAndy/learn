#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* user function */
void test_list()
{
	int vint[] = {12, 483, 41, 5, 1, 23, 5, 7, 9, 21, 35, 6, -1, 34};
	int n = sizeof(vint) / sizeof(*vint);
	elem_ptr *v;
	list *s1, *s2;
	int i;

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
	node *p = Find(s1, d);
	if (p == NULL)
		Exit("P is NULL");
	PrnNode(p);
	printf("\n");
	node *p1 = FindPre(s1, d);
	PrnNode(p1);
	DelNode(s1, d);
	printf("\n");
	PrnList(s1);
	printf("--------DelNode(), 41 --------- \n");


	void NodeProc(node *p);
	Traverse(s2, NodeProc);
	PrnList(s2);
	printf("--------Traverse(), Elem Double--------- \n");

	DelList(s2);
	PrnList(s2);
	printf("--------DelList() --------- \n");
}

int main()
{
	test_list();

	return 0;
}

