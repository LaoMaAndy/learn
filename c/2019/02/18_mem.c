/* mem.c */
#include "template/head.h"

union header_union
{
	struct 
	{
		union header_union *next;
		unsigned size;
	} s;
	long align_never_use;
};
typedef union header_union header;
static header base, *freep = NULL;
#define NALLOC 1024

static header *morecore(unsigned nu);
void mem_free(void *ap);

void *mem_alloc(unsigned nbyte)
{
	header *p, *prevp;
	unsigned nunits;

	nunits = (nbyte + sizeof(header) - 1) / sizeof(header) + 1;
	if ((prevp = freep) == NULL)
	{
		base.s.next = freep = prevp = &base;
		base.s.size = 0;
	}
	for (p = prevp->s.next; ; prevp = p, p = p->s.next)
	{
		if (p->s.size >= nunits)
		{
			if (p->s.size == nunits)
				prevp->s.next = p->s.next;
			else
			{
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *) (p + 1);
		}
		if (p == freep)
			if ((p = morecore(nunits)) == NULL)
				return NULL;
	}
}
static header *morecore(unsigned nu)
{
	char *cp, *sbrk(int);
	header *up;
	
	if (nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(header));
	if (cp == (char *) -1)
		return NULL;
	up = (header *) cp;
	up->s.size = nu;
	mem_free((void *)(up + 1));
	return freep;
}
void mem_free(void *ap)
{
	header *bp, *p;

	bp = (header *) ap - 1;
	for (p = freep; !(bp > p && bp < p->s.next); p = p->s.next)
		if (p >= p->s.next && (bp > p || bp < p->s.next))
			break;
	if (bp + bp->s.size == p->s.next)
	{
		bp->s.size += p->s.next->s.size;
		bp->s.next = p->s.next->s.next;
	}
	else
		bp->s.next = p->s.next;
	if (p + p->s.size == bp)
	{
		p->s.size += bp->s.size;
		p->s.next = bp->s.next;
	}
	else
		p->s.next = bp;
	freep = p;
}



int main(void)
{
	char *p;
p = (char *) mem_alloc(1024);
	if (p != NULL)
		mem_free(p);
	printf("Ok\n");
	return 0;
}
