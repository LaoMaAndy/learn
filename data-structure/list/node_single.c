#include "list.h"

struct node
{
	elem *eptr;
	struct node *next;
};
int NodeSize(void)
{
	return sizeof(struct node);
}
node *NewNode(elem *e)
{
	node *p;
	elem *new_elem;

	p = (node *) malloc(NodeSize());
	if (p == NULL)
		Exit("malloc() return NULL");
	new_elem = ElemNew();
	if (e != NULL)
		ElemCopy(new_elem, e);
	SetNodeElem(p, new_elem);
	SetNext(p, p);
	return p;
}
node *Next(node *s)
{
	return s->next;
}
void SetNext(node *p, node *next_p)
{
	p->next = next_p;
}
elem *NodeElem(node *p)
{
	return p->eptr;
}
node *SetNodeElem(node *p, elem *v)
{
	if (p->eptr != NULL)
		free(p->eptr);
	p->eptr = v;
	return p;
}
void PrnNode(node *p, int id)
{
	if (id == -1)
		printf("[%5s]", "head");
	else
		printf("[%5d]", id);
	printf("Node  Addr:%15p, ", p);
	printf("Next  Addr:%15p, ",Next(p));
	ElemPrn(NodeElem(p));
	printf("\n");
}
