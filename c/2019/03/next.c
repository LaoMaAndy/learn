/* next.c */
#include <stdio.h>		// printf()
#include <stdlib.h>		// malloc(), exit()
#include <string.h>		// strlen()

int Strindex(const char *dest, const char *sub)
{
	size_t i, j;
	size_t dest_len = strlen(dest);
	size_t sub_len = strlen(sub);

	while (i < dest_len && j < sub_len)
	{
		if (dest[i] == sub[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == sub_len)
		return i - j;
	else
		return -1;
}
int kmp(const char *dest, const char *sub)
{
	size_t i = 0, j = 0;
	size_t dest_len = strlen(dest);
	size_t sub_len = strlen(sub);
	int *next;
	void getNext(const char *, int *);

	next = (int *) malloc(sub_len * sizeof(int));
	if (next == NULL)
	{
		printf("malloc() return NULL\n");
		exit(1);
	}
	getNext(sub, next);
	while (i < dest_len && j < sub_len)
	{
		if (j == -1 || dest[i] == sub[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == sub_len)
		return i - j;
	else
		return -1;
}
void getNext(const char *p, int next[])
{
	int i = 0, j = -1;
	next[0] = -1;

	while (i < strlen(p))
	{
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
#define LEN(a) (sizeof(a) / sizeof(*a) - 1)
void test_getNext()
{
	char str[] = "abababca";
	int  next[LEN(str)];
	int i, n = LEN(str);

	printf("length: %d\n", n);
	printf("String: ");
	for (i = 0; i < n; ++i)
		printf("%2c ", str[i]);
	printf("\n");
	getNext(str, next);
	printf("next  : ");
	for (i = 0; i < n; ++i)
		printf("%2d ", next[i]);
	printf("\n");
}
int main()
{
	test_getNext();
	return 0;
}
