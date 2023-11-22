#include "head.h"

void test_convert(void) {
	char a[100] = "AbCdEfGhIjK012#^\0";
	char b[100] = "-1234567.9876\0";
	char c[100] = " -908076.543a\0";
	int d = -12345678;
	char e[100];

	printf("---test convert----\n");
	printf("string a:%18s\n", a);
	printf("string b:%18s\n", b);
	int b1 = Atoi(b);
	printf("Atoi(b)	:%18d\n", b1);
	double b2 = Atof(b);
	printf("Atof(b) :%18.4f\n", b2);
	if (b1 == (int) b2)
		printf("--Atoi(), Atof()---OK--\n");
	else
		printf("--Atoi(), Atof()---Err--\n");
	printf("string c:%18s\n", c);
	printf("Atof(c) :%18.2f\n", Atof(c));
	printf("number  :%18d\n", d);
	printf("Itoa()  :%18s\n", Itoa(d, e));
	if (Atoi(Itoa(d, e)) == d)
		printf("---Itoa()---OK---\n");
	else
		printf("---Itoa()---Err---\n");
}
int fact(int n);
void test_fact()
{
	int i = 5;
	printf("---test fact:---\n");
	printf("fact(%2d) = %3d\n", i, fact(i));
}
void prnstr(const char *s);
void test_prnstr()
{
	char s[100] = "a  b  c123\n\0";
	printf("---test prn_str:---\n");
	printf("%s", s);
	prnstr(s);
}
void prnint(int n);
void test_prnint()
{
	printf("Test prnint(): \n-987654321\n");
	fflush(stdout);
	prnint(-987654321);
	printf("\n");
}
int main(int argc, char *argv[])
{
	test_convert();
	test_fact();
	test_prnstr();
	test_prnint();

	return 0;
}
