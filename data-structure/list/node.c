/* node common code */
#include "list.h"


void FreeNode(node *p)
{
	ElemFree(NodeElem(p));
	free(p);
}
void NodeProc(node *p)
{
	void ElemProc(elem *e);
	ElemProc(NodeElem(p));
}
