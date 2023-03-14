/* mem.h */
#include <stdio.h>
union header_union
{
	struct
	{
		union header_union *next;
		unsigned size;
	} s;
	long never_use;
};
typedef union header_union header;

header mem_base;
header *mem_freep;
#define NALLOC 10

static header *mem_more(unsigned nu);
char *sbrk(int n);
