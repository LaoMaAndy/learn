/*
   class of kstr
*/

#ifndef KSTR_HPP
#define KSTR_HPP

#include <iostream>
#include <cstdio>
#include <cstring>

class kstr
{
	friend std::ostream& operator<<(std::ostream&, const kstr&);
	public:
		typedef char ktype;
		typedef size_t ksize;
		kstr() = default;
		kstr(const char *);
	private:
		ktype *base = nullptr;
		ksize len = (ksize) 0;
};


#endif
