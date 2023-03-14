#ifndef KSTRING_HPP
#define KSTRING_HPP
#include <stdlib.h>

class memory
{
public:
	bool memset(size_t n);
	size_t size(void);
	memory();
	~memory();
private:
	void *base;
	size_t memsize;
};

class kstr : public memory
{
//friend kstr &copy(kstr &dest, const kstr &src);
public:
	kstr();
	~kstr();
	//kstr &copy(kstr &src);
private:
	const size_t KSTR_UNIT = 64;
	size_t calc(size_t n);
	size_t len;
};

#endif
