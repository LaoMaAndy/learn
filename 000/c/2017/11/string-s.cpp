#include "0head.cpp"
class cstring
{
friend int compare(const cstring &s, const cstring &t);
friend ostream &operator<< (ostream &os, const cstring &str);
public:
	typedef size_t size_type;
public:
	cstring();
	cstring(const char *s);
	cstring(const cstring &s);
	~cstring();
public:
	void test();
	size_type size();
	cstring &operator= (const cstring &rhs);
	cstring operator+ (const cstring &rhs);
private:
	size_type strsize;
	char *ptr;
};
cstring::cstring(){}
cstring::~cstring(){}


int main(void)
{
	cstring s;
	return 0;
}

