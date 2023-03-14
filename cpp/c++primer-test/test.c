#include <stdio.h>
#include <ctype.h>
#include <stddef.h>

void array(void)
{
	int ia[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int ib[4] = {15, 16, 17, 18};
	int (*p)[4];
	int *q;
	int *s;

	//*ia = &ib;
	p = ia;
	q = ia[0];
	s = (int *)ia;
	for (int i = 0; i < 4; i++)
		printf("%d\t", ia[0][i]);
	for (int i = 0; i < 12; i++)
		printf("%d\t", *s++);
	printf("\nia: %p, ia[0]: %p, &ia[0][0]: %p\n", ia, ia[0], &ia[0][0]);
}
int Strncmp(char *s, char *t, int n)
{
	for ( ; --n > 0; s++, t++)
		if (*s != *t)
			break;
	return *s - *t;
}

int num(int n)
{
	return n;
}

void test(int n)
{
	int i[n];
	int m[num(3)];
	int a;

	for (a = 0; a < n; a++)
		i[n] = a;
	for (a = 0; a < num(3); a++)
		i[a] = a;
}

int main(void)
{
	array();
	test(3);
	printf("size of size_t: %ld\n", sizeof(size_t));
	printf("size of ptrdiff_t: %ld\n", sizeof(ptrdiff_t));
	size_t st = 0;
	st -= 1;
	if (st > 0)
		printf("size_t is unsigned.\n");
	else
		printf("size_t is signed.\n");
	ptrdiff_t pt = 0;
	pt -= 1;
	if (pt > 0)
		printf("ptrdiff_t is unsigned.\n");
	else
		printf("ptrdiff_t is signed.\n");

	return 0;
}

