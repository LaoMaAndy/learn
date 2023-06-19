#include "kstring.hpp"
#include "cstdio"
#define CONSTRUCT

bool memory::memset(size_t l)
{
	void *p;
	if (l < memsize)
		return true;
	if (base == NULL)
		p = malloc(l);
	else
		p = realloc(base, l);
	if (p == NULL)
		return false;
	base = p;
	memsize = l;
	return true;
}
memory::memory()
{
	base = NULL;
	memsize = 0L;
#ifdef CONSTRUCT
	printf("construct memory\n");
#endif
}
memory::~memory()
{
	if (base != NULL)
		free(base);
#ifdef CONSTRUCT
	printf("~dis-construct memory\n");
#endif
	return;
}
inline size_t memory::size(void)
{
	return memsize;
}

kstr::kstr()
{
	len = 0;
#ifdef CONSTRUCT
	printf("construct kstr\n");
#endif
}
kstr::~kstr()
{
#ifdef CONSTRUCT
	printf("~dis-construct kstr\n");
#endif
}
size_t kstr::calc(size_t n)
{
	return (n / KSTR_UNIT + 1) * KSTR_UNIT;
}
int main(void)
{
	kstr k;
	return 0;
}
