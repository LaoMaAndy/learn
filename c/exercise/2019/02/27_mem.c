/* mem.c */
#include "template/head.h"
#include "template/mem.h"

void *mem_alloc(unsigned nb)
{
	unsigned n;
	header *pre, *p;

	n = (nb + sizeof(header) - 1) / sizeof(header) + 1;
	if ((pre = mem_freep) == NULL)
	{
		pre = mem_freep = mem_base.s.next = &mem_base;
		mem_base.s.size = 0;
	}
	for (p = pre->s.next;  ; pre = p, p = p->s.next)
	{
		if (p->s.size >= n)
		{
			if (p->s.size == n)
				pre->s.next = p->s.next;
			else
			{
				p->s.size -= n;
				p += p->s.size;
				p->s.size = n;
			}
			mem_freep = pre;
			return (void *) (p + 1);
		}
		if (p == mem_freep)
			if ((p = mem_more(n)) == NULL)
				return NULL;
	}
}
static header *mem_more(unsigned nu)
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