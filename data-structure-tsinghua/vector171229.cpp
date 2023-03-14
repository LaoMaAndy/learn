/*
   Vector
*/
#include "0head.h"

class Vector
{
	private:
		typedef int dtype;
		dtype *base;
		dtype *cur;
		size_t n;
	public:
		int init(size_t);
		inline dtype get(void);
		void free(void);
		inline size_t size();
};
int Vector::init(size_t i)
{
	base = (dtype *) malloc(i);
	if (base == NULL)
		return 0;
	n = i;
	cur = base;
	return i;
}
size_t Vector::size()
{
	return n;
}
Vector::dtype Vector::get(void)
{
	return *cur;
}
