#include "kstring.hpp"
#include "0head.cpp"

stringx& stringx::copy(const char *src)
{
	size_t l = size(src);
	if(setmem(l) != false)
	{
		copy(base, src, l);
		len = l;
	}
	return *this;
}
inline char *stringx::copy(char *dest, const char *src)
{
	return strcpy(dest, src);
}
stringx& stringx::copy(const char *src, size_t n)
{
	if (setmem(n) != false)
		copy(base, src, n, n);
	len = n;
	return *this;
}
inline char *stringx::copy(char *dest, const char *src, size_t n)
{
	return (char*) memcpy(dest, src, n);
}
char *stringx::copy(char *dest, const char *src, size_t src_len, size_t n)
{
	size_t ss = src_len; 
	size_t ncopy, nspace;
	if (n > ss)
	{
		ncopy = ss;
		nspace = n - ss + 1;
	}
	else
	{
		ncopy = n;
		nspace = 0;
	}
	copy(dest, src, n);
	for (int i = 0; i < nspace; ++i)
		dest[n + i] = '\0';
	return dest;
}
inline stringx &stringx::copy(const stringx &src)
{
	return copy(src, src.size());
}
stringx &stringx::copy(const stringx &src, size_t n)
{
	if(setmem(n) != false)
	{
		copy(base, src.text(), src.size(), n);
		len = n;
		base[len] = 0;
	}
	return *this;
}

size_t stringx::index(const char *sub)
{
	const char *p = str(sub);
	if (p != NULL)
		return p - base;
	return -1;
}
const char *stringx::str(const char *dest, const char *sub)
{
	const char *s, *t;
	const char *top = base + len;

	for ( ; dest < top; ++dest)
		if (*dest == *sub)
		{
			t = dest + 1;
			s = sub + 1;
			for ( ;*t == *s && t < top; ++s, ++t)
				;
			if (*s == '\0')
				return dest;
		}
	return NULL;	
}
const char *stringx::str(const char *sub)
{
	return str((const char *)base, sub);
}
const char *stringx::chr(int c)
{
	const char *top = base + len;

	for (const char *p = base; p < top; ++p)
		if (*p == c)
			return p;
	return NULL;
}
const char *stringx::rchr(int c)
{
	for (const char *p = base + len - 1; p >= base; --p)
		if (*p == c)
			return p;
	return NULL;
}	
void stringx::reverse()
{
	char *p, *q;
	int temp;

	p = q = base;
	for(p += len - 1; p > q; --p, ++q)
	{
		temp = *p;
		*p = *q;
		*q = temp;
	}
}
void stringx::toup()
{
	for (size_t i = 0; i < len; ++i)
		base[i] = toupper(base[i]);
}
void stringx::tolow()
{
	for (size_t i = 0; i < len; ++i)
		base[i] = tolower(base[i]);
}
void stringx::showtext()
{
	int i;
	const char *p = base;

	printf("\t");
	for (i = 0; i < len; ++i)
	{
		printf("%2X", *p++);
		if (i % 16 == 15)
			printf("\n\t");
		else if (i % 8 == 7)
			printf(" - ");
		else
			printf(" ");
	}
}
int stringx::comp(const stringx &dest, size_t n)
{
	const char *s = base;
	const char *t = dest.text();
	size_t count = 0;
	size_t ls = len;
	size_t lt = dest.size();
	printf("[info-comp] ls: %ld, lt: %ld, n: %ld\n", ls, lt, n);
	for ( ; --n > 0 && count < ls && count < lt; ++count, ++s, ++t)
		if (*s != *t)
			break;
	printf("[info-comp] ls: %ld, lt: %ld, n: %ld\n", ls, lt, n);
	return *s - *t;
}
inline int stringx::comp(const stringx &dest)
{
	return comp(dest, dest.size() + len);
}
inline const char *stringx::text() const
{
	return (const char *) base;
}
inline char *stringx::cat(char *dest, const char *src)
{
	cat(dest, src, size(src));
}
inline char *stringx::cat(char *dest, const char *src, size_t n)
{
	return copy(dest + size(dest), src, n);
}
stringx &stringx::cat(const char *src)
{
	return cat(src, size(src));
}
stringx &stringx::cat(const char *src, size_t n)
{
	if(setmem(len + n) != false)
	{
		copy(base + len, src, n, n);
		len += n;
		base[len] = 0;
	}
	return *this;
}
inline stringx &stringx::cat(const stringx &src, size_t n)
{
	return cat(src.text(), n);
}
inline stringx &stringx::cat(const stringx &src)
{
	return cat(src, src.size());
}

stringx::~stringx()
{
	if (base != NULL)
		free(base);
}
void stringx::info(void)
{
	printf("[info-stringx] ");
	printf("\tlen: %ld, msize: %ld\n", len, msize);
	printf("\tbase address: %p\n", base);
	printf("\thead address: %p\n", this);
	printf("\ttext: %s\n", base);
	showtext();
	printf("\n");
}
stringx::stringx(const char *s)
{
	base = NULL;
	len = msize = 0;
	convert(s);
}
inline stringx &stringx::convert(const char *s)
{
	return copy(s);
}
inline size_t stringx::size() const
{
	return len;
}
inline size_t stringx::size()
{
	return len;
}
inline size_t stringx::size(const char *dest)
{
	return strlen(dest);
}
bool stringx::setmem(size_t n)
{
	if (n < msize)
		return true;
	char *p;
	size_t l = calc(n);
	if (base == NULL)
		p = (char *) malloc(l);
	else
		p = (char *) realloc(base, l);
	if (p == NULL)
		return false;
	base = p;
	msize = l;
	return true;
}
size_t stringx::calc(size_t n)
{
	return (n / KSTR_UNIT + 1) * KSTR_UNIT;
}
stringx::stringx()
{
	base = NULL;
	len = msize = 0;
}
void stringx::test_calc(void)
{
	for (int i = 0; i <= 256; ++i)
		printf("i: %3d, calc: %4ld\n", i, calc(i));
}
void test_info(void)
{
	stringx k;
	//k.test_calc();
	k.convert("This is a test");
	k.info();
	stringx k2("xx");
	k2.info();
	stringx k3("");
	k3.info();
	stringx k4("abcdefgh12345678ABCDEFGH!@#$%^&*");
	k4.info();
}
void test_copy(void)
{
	stringx k1("abcdefe");
	k1.info();
	stringx k2("321");
	k2.info();
	printf("---test copy----\n");
	k2.copy(k1);
	k2.info();
	printf("----test copy empyt---\n");
	stringx k3;
	k3.info();
	k2.copy(k3);
	k2.info();
	char s[] = "test the \\0 string.and there a \\0 in this string\0...";
	char t[] = "12345\0abcdef";
	printf("%s\n", s);
	printf("%s\n", t);
	stringx k4;
	k4.copy(t, 10);
	k4.info();
	stringx k5;
	k5.copy(s);
	k5.info();
}
void test_comp(void)
{
	stringx k1("a");
	stringx k2("b");

	k1.info();
	k2.info();
	printf("k1 comp k2 is: %d\n", k1.comp(k2, 0));
}
void test_toupper()
{
	printf("[info-test-toupper, tolower]\n");
	stringx k("This is a test");
	k.info();
	k.toup();
	k.info();
	k.tolow();
	k.info();
}
void test_reverse()
{
	printf("[info-test-converse]\n");
	stringx k("0123456789");
	k.info();
	k.reverse();
	k.info();
}
void test_str()
{
	stringx k1("1234567abcdef");
	k1.info();
	printf("[info-test-str]\n");
	printf("\t%s\n", k1.str("abc"));
	printf("index(abc): %ld\n", k1.index("abc"));
	printf("index(123): %ld\n", k1.index("123"));
}
void test_cat(void)
{
	printf("[info_test_cat]\n");
	stringx k1("123");
	stringx k2("abc");
	k1.cat(k2, 0);
	k1.info();
	k1.cat("const string");
	k1.info();
	char s[] = "!@!@";
	k1.cat(s);
	k1.info();
	char t[] = "12345\0abcde";
	k1.copy(t);
	k1.info();
	k1.cat(t, 10);
	k1.info();
}
int main(void)
{
	test_comp();
	test_info();
	test_toupper();
	test_reverse();
	test_str();
	test_copy();
	test_cat();
	test_string();

	return 0;
}

	

	
	
		
