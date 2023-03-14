/* hanoi.c */
#include "../dsaa.h"

void move(int n, char *src, char *dest)
{
	static int step = 1;
	printf("Step:%5d. Move #%2d from: %5s to: %5s\n", step, n, src, dest);
	++step;
}
void hanoi(int n, char *src, char *mid, char *dest)
{
	if(n == 1)
		move(1, src, dest);
	else
	{
		hanoi(n - 1, src, dest, mid);
		move(n, src, dest);
		hanoi(n - 1, mid, src, dest);
	}
}
void test_hanoi()
{
	int n = 10;
	char src[] = "A";
	char mid[] = "B";
	char dest[] = "C";

	printf("Move %d, from %s, by %s, to %s\n", n, src, mid, dest);
	hanoi(n, src, mid, dest);
}
int main()
{
	test_hanoi();
	return 0;
}
