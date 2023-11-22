#include "list_double.h"

struct node
{
	elem *eptr;
	struct node *next, *prev;
};
int NodeSize(void)
{
	return sizeof(struct node);
}
node *NewNode(elem *e)
{
	node *p;
	elem *new_elem;

	p = (node *) malloc(sizeof(*p));
	new_elem = ElemNew();
	if (p == NULL || new_elem == NULL)
		Exit("malloc() return NULL");
	if (e != NULL)
		ElemCopy(new_elem, e);
	SetNodeElem(p, new_elem);
	SetNext(p, p);
	SetPrev(p, p);
	return p;
}
node *Next(node *s)
{
	return s->next;
}
node *Prev(node *s)
{
	return s->prev;
}
void SetNext(node *p, node *next_p)
{
	p->next = next_p;
}
void SetPrev(node *p, node *prev_p)
{
	p->prev = prev_p;
}
elem *NodeElem(node *p)
{
	return p->eptr;
}
node *SetNodeElem(node *p, elem *v)
{
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
	printf("Prev  Addr:%15p, ",Prev(p));
	ElemPrn(NodeElem(p));
	printf("\n");
}
