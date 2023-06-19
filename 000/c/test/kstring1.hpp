#ifndef KSTRING_HPP
#define KSTRING_HPP
#include <iostream>
#include "kstring.h"

class stringx
{
public:
	stringx(void);
	stringx(const char *s);
	~stringx();
public:
	size_t size() const;
	size_t size();
	size_t size(const char *p);
	const char *text() const;
	stringx &copy(const stringx &src);
	stringx &copy(const stringx &src, size_t n);
	stringx &copy(const char *src);
	stringx &copy(const char *src, size_t n);
	char *copy(char *dest, const char *src);
	char *copy(char *dest, const char *src, size_t n);
	char *copy(char *dest, const char *src, size_t src_len, size_t n);
	stringx &cat(const stringx &src);
	stringx &cat(const stringx &src, size_t n);
	stringx &cat(const char *src);
	stringx &cat(const char *src, size_t n);
	char *cat(char *dest, const char *src);
	char *cat(char *dest, const char *src, size_t n);
	int comp(const stringx &s);
	int comp(const stringx &s, size_t n);
	const char *chr(int c);
	const char *rchr(int c);
	const char *str(const char *sub);
	const char *str(const char *dest, const char *sub);
	size_t index(const char *sub);
	size_t spn(const char *dest, const char *pre);
	void reverse();
	void toup();
	void tolow();
	stringx &convert(const char *s);
	void info(void);
	void showtext();
	//strstr, strindex, chr, rchr, spn, cspn, pbrk, squeeze, trim, reverse, 
	//dup, toup, tolow, squs
	//subs, devision, 
public:
	void test_calc();
private:
	const size_t KSTR_UNIT = 64;
	size_t len, msize;
	char *base;
private:
	size_t calc(size_t n);
	bool setmem(size_t n);
};


#endif
