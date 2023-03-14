/* 3.10-2 */
#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int n;
	struct node *next, *prev;
};
typedef struct node node;

node *init(int n)
{
	int i;
	node *p, *start, *prev;

	prev = start = p = (node *) malloc(n * sizeof(node));
	if (p == NULL)
	{
		printf("malloc() return NULL\n");
		return NULL;
	}
	for (i = 0; i < n; ++i)
	{
		p->n = i + 1;
		p->next = p + 1;
		p->prev = prev;
		prev = p;
		++p;
	}
	(--p)->next = start;
	start->prev = p;
	return start;
}
node *del(node *p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	return p->next;
}
node *insert(node *pos, int i)
{
	node *new_node = (node *) malloc(sizeof(node));
	if (new_node == NULL)
	{
		printf("malloc() return NULL\n");
		exit(1);
	}
	new_node->n = i;
	new_node->next = pos->next;
	new_node->prev = pos;
	pos->next = new_node;
	new_node->next->prev = new_node;
	return new_node;
}
void prn(node *p, int n)
{
	int i;

	for (i = 0; i < n; ++i)
	{
		printf("No: %3d, Next: %p, Addr: %p, Prev: %p\n", p->n, p->next, p, p->prev);
		++p;
	}
}
void josephus(int n, int m)
{
	int i, count, total, time;
	node *p, *fp;

	fp = p = init(n);
	//prn(init(n), n);

	i = 0;
	count = 1;
	total = n;
	time = m;
	while (1)
	{
		if (i == time)
		{
			printf("[%6d], No: %6d, Next: %p, Addr: %p, Prev: %p\n",count, p->n, p->next, p, p->prev);
			p = del(p);
			if (p->next == p)
			{
				printf("Winner:\n");
				printf("[%6d], No: %6d, Next: %p, Addr: %p, Prev: %p\n",count + 1, p->n, p->next, p, p->prev);
				break;
			}
			i = 0;
			++count;
			--total;
			time = m % total;
		}
		else
		{
			p = p->next;
			++i;
		}
	}
	free(fp);
}

void josephus2(int n, int m)
{
	int i, count;
	node *p, *fp;

	fp = p = init(n);
	//prn(init(n), n);

	count = 1;
	i = 0;
	while (1)
	{
		if (i == m)
		{
			printf("[%6d], No: %6d, Next: %p, Addr: %p, Prev: %p\n",count, p->n, p->next, p, p->prev);
			p = del(p);
			if (p->next == p)
			{
				printf("Winner:\n");
				printf("[%6d], No: %6d, Next: %p, Addr: %p, Prev: %p\n",count + 1, p->n, p->next, p, p->prev);
				break;
			}
			i = 0;
			++count;
		}
		else
		{
			p = p->next;
			++i;
		}
	}
	free(fp);
}

int main()
{
	// josephus2(100000, 100000);
	printf("------------\n");
	//josephus(10, 199);
	josephus(100000, 100000);
	return 0;
}