/*
function: Malloc, Free
*/
#define NEED_STRING
#include "0head.c"

typedef long ALIGN;
union header_union
{
	struct 
	{
		union header_union *next;
		unsigned size;
	} s;
	ALIGN x;
};
typedef union header_union header;

static header base;
static header *freep = NULL;
static header *morecore(unsigned nu);
void Malloc(unsigned ntypes);
void Freee(void *ap);

void Malloc(unsigned nb)
{
	header *p, *prevp;
	unsigned nu;
	
	nu = (nb + sizeof(header) - 1) /sizeof(header) + 1;
	if ((prevp = freep) == NULL)
	{
		base.s.next = freep = prevp = &base;
		base.s.size = 0;
	}
	for (p = prevp->s.next; ; prevp = p, p = p->s.next)
	{
		if (p->s.size >= nu)
		{
			if (p->s.size = nu)
			{
				if 
