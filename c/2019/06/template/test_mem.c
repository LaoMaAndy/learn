/* test_mem.c */
#include "head.h"

unsigned  mem_size(int nbytes)
{
	unsigned nunits;

	nunits = (nbytes + sizeof(header) - 1) / sizeof(header) + 1;
	return nunits;
}
void test_mem_size()
{
	int i;

	for (i = 0; i < 100; ++i)
		printf("i:%4d, unit:%3d%c", i, mem_size(i), (i % 4 == 3) ? '\n' : '\t');
	printf("\n");
}
unsigned mem_chain_list(void)
{
	header *p = mem_freep;
	int i = 0;
	unsigned total = 0;

	printf("---Free Memory Chain--- \n");
	printf("Memory Base: %p\n", &mem_base);
	printf("mem_freep  : %p\n", mem_freep);
	do
	{
		printf("Memory Node %d\n", i);
		printf("\tNode address:%p\n", p);
		printf("\tNode size   :%3d(unit), %5ld(byte)\n", p->s.size,  (p->s.size * sizeof(header)));
		printf("\tNext node   :%p\n", p->s.next);
		p = p->s.next;
		++i;
		total += p->s.size;
	} while (p != mem_freep && p != NULL);
	return total;
}
unsigned mem_chain_size(void)
{
	unsigned total = 0;
	header *p = mem_freep;

	do {
		total += p->s.size;
		p = p->s.next;
	} while (p != mem_freep);
	return total;
}
unsigned mem_node_size(void *m)
{
	header *p;

	p = (header *) m;
	p -= 1;
	printf("Alloc Node size: %d\n", p->s.size);
	if (p == NULL)
		return 0;
	return p->s.size;
}
#define ALLOC_TIME 3
void mem_test(void)
{
	int block_size[] = {99, 201, 10, 400, 20, 2002};
	int n = sizeof(block_size) / sizeof(*block_size);
	void *p[n];
	int i;
    unsigned chain_pre_size, chain_size, node_size, j;
	static int init = 0;

	for (i = 0; i < n; ++i)
	{ 
		if (init == 0) 
		{
			init = 1;
			chain_pre_size = 0;
		}
		else
		{
			chain_pre_size = mem_chain_size();
		}
		printf("===>mem_alloc : %3d (%d byte)\n ", i, block_size[i]);
		p[i] = mem_alloc(block_size[i]);
		mem_chain_list();
		node_size = mem_node_size(p[i]);
		chain_size = mem_chain_size();
		printf("  Chain prev  : %3d\n", chain_pre_size); 
		printf("  request     : %3d\n", mem_size(block_size[i]));
		printf("  minimize    : %3d\n", NALLOC);
		printf("  Chain size  : %3d\n", chain_size);
		printf("  Node size   : %3d\n", node_size);
	}
	for (i = 0; i < n; ++i)
	{
		printf("==>free(p[%d])\n", i);
		chain_pre_size = mem_chain_size();
		node_size = mem_node_size(p[i]);
		mem_free(p[i]);
		mem_chain_list();
		chain_size = mem_chain_size();
		printf("  Free memory Chain pre: %5d\n", chain_pre_size);
		printf("  Free memory block    : %5d\n", node_size);
		printf("  Remain Free Memory   : %5d\n", chain_size);
		if (chain_size == (chain_pre_size + node_size))
				printf("  OK\n");
	}
}
int main()
{
	test_mem_size();
	printf("header size: %ld\n", sizeof(header));
	mem_test();
	return 0;
}
