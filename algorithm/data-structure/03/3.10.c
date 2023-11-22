/* exercise 3.9.c */
#include "../list/list.h"

void josephus(int n, int m)
{
	list *s;
	elem_ptr *e;
	int i, *ip, count;
	node *p;

	ip = (int *) malloc(n * sizeof(int));
	if (ip == NULL)
		Exit("malloc() return NULL");
	for (i = 0; i < n; ++i)
		ip[i] = i + 1;
	e = MakeElems(ip, ip, n);
	s = MakeList(e, n);
	// PrnList(s);

	i = 0;
	count = 0;
	printf("n = %3d, m = %3d\n", n, m);
	for (p = First(s); Next(Next(Head(s))) !=Head(s);  )
	{
		if (i == m)
		{
			PrnNode(p, ++count);
			p = DelCurNode(s, p);
			i = 0;
		}
		else 
		{
			p = Next(p);
			if (p == Head(s))
				p = Next(p);
			++i;
		}
	}
	printf("Winner: \n");
	PrnNode(First(s), 0);
	free(ip);
}
int main()
{
	josephus(10000, 10000);
	return 0;
}