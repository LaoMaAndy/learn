/*
 * String.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: lixudong
 */
//String 类，实现类似string的功能
//可以在练习程序中，用来替代库函数中的string类
#include "0head.cpp"
class String
{
friend ostream &operator<<(ostream &os, const String &str);
friend int Stringcmp(const String &s, const String &t);
public:
	typedef size_t size_type;
public:
	String();
	String(const char *s);
	~String();
public:
	size_type size(return strsize);
	void test(void);
private:
	size_type strsize, memsize;
	char *ptr;
	static const size_type init_size = 32;
	static const size_type increase_rate = 2;
	static const size_type size_factor = 8;
private:
	char *init(size_type n);
	bool resize(size_type n);
	void error(int n, const char *s);
	size_type refactor(size_type n);
};
String::String()
{
	init(init_size);
	strsize = 0;
}
String::String(const char *s)
{
	size_type len = strlen(s);
	strcpy(init(refactor(len)), s);
	strsize = len;
}
String::~String()
{
	if (ptr != nullptr)
		free(ptr);
}
char *String::init(size_type n)
{
	ptr = (char *) malloc(n);
	if (ptr != nullptr)
	{
		memsize = n;
		return ptr;
	}
	error(1, "Can't init mem.");
	return ptr;
}
bool String::resize(size_type n)
{
	char *p = (char *) realloc(ptr, n);
	if (p != nullptr)
	{
		if (n < strsize + 1)
		{
			p[n - 1] = '\0';
			strsize = n - 1;
		}
		memsize = n;
		ptr = p;
		return true;
	}
	error(2, "Can't resize mem");
	return false;
}
void String::error(int n, const char *s)
{
	printf("string error. %3d: %s\n", n, s);
	exit(1);
}
ostream &operator<<(ostream &os, const String &str)
{
	return cout << str.ptr;
}
String::size_type String::refactor(size_type n)
{
	return (n < init_size) ? init_size : (n / size_factor + 1) * size_factor;
}
void String::test(void)
{
	for (int i = 0; i < 50; i++)
		printf("refactor. %3d - %3ld\n", i, refactor(i));
}
int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		String s("test string");
		cout << s << endl;
	}
	String t("47832907&*$#");
	t.test();
	return 0;
}
	
	


	
