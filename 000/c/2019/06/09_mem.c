/* 
 * mem.c 
 */
#include "template/head.h"

void *mem_alloc(unsigned nc)
{
	header *pre, *p;
	unsigned nu;

	nu = (nc + sizeof(header) - 1) / sizeof(header) + 1;
	if ((pre = mem_freep) == NULL)
	{
		pre = mem_freep = mem_base.s.next = &mem_base;
		mem_base.s.size = 0;
	}
	for (p = pre->s.next;  ; pre = p, p = p->s.next)
	{
		if (p->s.size >= nu)
		{
			if (p->s.size == nu)
				pre->s.next = p->s.next;
			else
			{
				p->s.size -= nu;
				p += p->s.size;
				p->s.size = nu;
			}
			mem_freep = pre;
			return (void *) (p + 1);
		}
		if (p == mem_freep)
			if ((p = mem_more(nu)) == NULL)
				return NULL;
	}
}
header *mem_more(unsigned nu)
{
	char *cp;
	header *hp;

	if (nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(header));
	if (cp == (char *) -1)
		return NULL;
	hp = (header *) cp;
	hp->s.size = nu;
	mem_free((void *) (hp + 1));
	return mem_freep;
}
void mem_free(void *vp)
{
	header *p, *fp;

	fp = (header *) vp - 1;
	for (p = mem_freep; !(fp > p && fp < p->s.next); p = p->s.next)
		if (p >= p->s.next && (fp > p || fp < p->s.next))
			break;
	if (fp + fp->s.size == p->s.next)
	{
		fp->s.size += p->s.next->s.size;
		fp->s.next = p->s.next->s.next;
	}
	else
		fp->s.next = p->s.next;
	if (p + p->s.size == fp)
	{
		p->s.size += fp->s.size;
		p->s.next = fp->s.next;
	}
	else
		p->s.next = fp;
	mem_freep = p;
}
