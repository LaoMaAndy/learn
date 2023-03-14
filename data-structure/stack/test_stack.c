/* test_stack.c */
#include "stack.h"

void test_stack()
{
	int v[] = {13, 12, 11, 10, 9, 8, 7, 6, 5};
	int n = sizeof(v) / sizeof(*v);
	stack *s;
	int i, temp;

	s = NewStack();
	for (i = 0; i < n; ++i)
	{
		Push(s, v[i]);
		printf("Push: %d\n", v[i]);
	}
	printf("Elem Count: %3d, Stack cap: %3d\n", StackSize(s), StackCap(s));
	for (i = 0; i < n; ++i)
	{
		temp = Pop(s);
		printf("Pop: %d\n", temp);
	}
	printf("IsEmpty: %s\n", (IsEmpty(s) ? "Yes" : "No"));
}

int main()
{
	test_stack();
	return 0;
}