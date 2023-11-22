#include <stdio.h>
#include <string.h>

size_t len;
char cstr[] = "char string";
signed char scstr[] = "signed char string";
unsigned char ucstr[] = "unsgiend char string";

int main(void)
{
	len = strlen(cstr);
	len = strlen(scstr);
	len = strlen(ucstr);

	return 0;
}
