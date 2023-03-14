#include "template/head.h"

size_t Strlen2(const char *s)
{
	const char *p = s;
	while (*p++ != '\0')
		;
	return p - s;
}

void test_strlen2(void)
{
	char s[20] = "\0";
	char t[20] = " \0";
	printf("Empty string size: %ld\n", Strlen2(s));
	printf("One Space string : %ld\n", Strlen2(t));

}
int main()
{
	test_strlen2();
	return 0;
}


