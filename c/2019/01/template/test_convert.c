#include "head.h"

void test_convert(void) {
	char a[100] = "AbCdEfGhIjK012#^\0";
	char b[100] = "-1234567.00\0";
	char c[100] = " -908076.543a\0";
	int d = -12345678;
	char e[100];

	printf("---test convert----\n");
	printf("string a:%18s\n", a);
	printf("string b:%18s\n", b);
	printf("Atoi(b)	:%18d\n", Atoi(b));
	printf("Atof(b) :%18.2f\n", Atof(b));
	printf("string c:%18s\n", c);
	printf("Atof(c) :%18.2f\n", Atof(c));
	printf("number  :%18d\n", d);
	printf("Itoa()  :%18s\n", Itoa(d, e));
}

int main(int argc, char *argv[])
{
	test_convert();

	return 0;
}