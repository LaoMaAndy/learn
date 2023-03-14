/* time2.c */
#include <stdio.h>
void time2()
{
	int v, c;
	do
	{
		printf("input a number: ");
		scanf("%d", &v);
		printf("%d x 2 = %d\n", v, v * 2);
		printf("continue (n = no) ?");
		c = getchar();
		c = getchar();
	} while (c != EOF && c != 'n' && c != 'N');	
}
void prn_star()
{
	int i, j, n = 10;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j <= i; ++j)
			printf("%2d", j);
		printf("\n");
	}
}
int main()
{
	prn_star();
	return 0;
}