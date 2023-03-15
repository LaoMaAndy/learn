/* mem.c */
#include "template/head.h"
#include "template/mem.h"

void *mem_alloc(unsigned nbyte)
{
	header *p, *prep;
	unsigned nu;

	nu = (nbyte + sizeof(header) - 1) / sizeof(header) + 1;
	if ((prep = mem_freep) == NULL)
	{
		mem_base.s.next = mem_freep = prep = &mem_base;
		mem_base.s.size = 0;
	}
	for (p = prep->s.next; ; prep = p, p = p->s.next)
	{
		if (p->s.size >= nu)
		{
			if (p->s.size == nu)
				prep->s.next = p->s.next;
			else
			{
				p->s.size -= nu;
				p += p->s.size;
				p->s.size = nu;
			}
			mem_freep = prep;
			return (void *) (p + 1);
		}
		if (p == mem_freep)
			if ((p = mem_more(nu)) == NULL)
				return NULL;
	}
}
static header *mem_more(unsigned nunit)
{
	char *cp, *sbrk(int);
	header *up;

	if (nunit < NALLOC)
		nunit = NALLOC;
	cp = sbrk(nunit * sizeof(header));
	if (cp == (char *) -1)
		return NULL;
	up = (header *) cp;
	up->s.size = nunit;
	mem_free((void *) (up + 1));
	return mem_freep;
}
void mem_free(void *ap)
{
	header *bp, *p;
	
	bp = (header *) ap - 1;
	for (p = mem_freep; !(bp > p && bp < p->s.next); p = p->s.next)
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
	mem_freep = p;
	//printf("--mem_free(%3d), address: %p\n",bp->s.size, p);
	//printf("--mem_free(%3d), mem_fre: %p\n",bp->s.size, mem_freep);
}
