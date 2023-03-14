#include "elem.h"

char *strdup(const char *s)
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}
/* elem date-type, which should be defined by user */
struct elem
{
	int id, val;
	char *str, *def;
};
typedef elem *elem_ptr;

int ElemSize(void)
{
	return sizeof(stuct elem);
}
elem *ElemNew(void)
{
	elem *p;

	p = (elem *) malloc(sizeof(*p));
	if (p == NULL)
		Error("malloc() return NULL");
	p->id = p->val = 0;
	p->str = p->def = NULL;
	return p;
}
void ElemFree(elem *p)
{
	free(p->str);
	free(p->def);
	free(p);
}
int ElemComp(const elem *x, const elem *y)
{
	return (x->id - y->id);
}
elem *ElemCopy(elem *dest, const elem *src)
{
	dest->id = src->id;
	dest->val = src->val;
	dest->str = strdup(src->str);
	dest->def = strdup(src->def);
	return dest;
}
void ElemPrn(const elem *e)
{
	printf(" %6d, %6d, %-10s, %-10s", e->id, e->val, e->str, e->def);
}
/* some function used to manipulate elem , defined by user */
elem *MakeElem(int i, int v, const char *str, const char *def)
{
	elem *p;

	p = ElemNew();
	p->id = i;
	p->val = v;
	p->str = strdup(str);
	p->def = strdup(def);
	return p;
}
elem_ptr *MakeElems(int index[], int value[], int n)
{
	elem_ptr *p;
	int i;

	p = (elem_ptr *) malloc(n * sizeof (*p));
	if (p == NULL)
		Error("malloc() return NULL");
	for (i = 0; i < n; ++i)
		p[i] = MakeElem(index[i], value[i], "word", "def");
	return p;
}
int ElemIndex(elem *e)
{
	return e->id;
}
int ElemVal(elem *e)
{
	return e->val;
}
elem *SetElemIndex(elem *e, int i)
{
	e->id = i;
}
elem *SetElemVal(elem *e, int v)
{
	e->val = v;
}
void ElemProc(elem *e)
{
	e->id *= 10;
}
