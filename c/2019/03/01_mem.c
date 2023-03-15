/* mem.c */
#include "template/head.h"

void *mem_alloc(unsigned nb)
{
	unsigned nu;
	header *pre, *p;

	nu = (nb + sizeof(header) - 1) / sizeof(header) + 1;
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
	header *p;

	if (nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(header));
	if (cp == (char *) -1)
		return NULL;
	p = (header *) cp;
	p->s.size = nu;
	mem_free((void *) (p + 1));
	return mem_freep;
}
void mem_free(void *vp)
{
	header *p, *mp;

	mp = (header *) vp - 1;
	for (p = mem_freep; !(mp > p && mp < p->s.next); p = p->s.next)
		if (p >= p->s.next && (mp > p || mp < p->s.next))
			break;
	if (mp + mp->s.size == p->s.next)
	{
		mp->s.size += p->s.next->s.size;
		mp->s.next = p->s.next->s.next;
	}
	else
		mp->s.next = p->s.next;
	if (p + p->s.size == mp)
	{
		p->s.size += mp->s.size;
		p->s.next = mp->s.next;
	}
	else
		p->s.next = mp;
	mem_freep = p;
}