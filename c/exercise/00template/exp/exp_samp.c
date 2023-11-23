/* simple infix to postfix */
#include "template/head.h"

#define STACK_SIZE 256
int stack[STACK_SIZE];
int count = 0;

static void Push(int c)
{
	if (count < STACK_SIZE)
		stack[count++] = c;
	else
		printf("push() error: overflow\n");
}
static int Pop()
{
	if (count > 0)
		return stack[--count];
	else
		printf("pop() error: empty\n");
	return 0;
}
static int Isempty()
{
	return (count == 0) ? 1 : 0;
}
static int Top()
{
	return stack[count - 1];
}
void test_stack()
{
	int v[] = {1, 2, 3, 4, 5, 7, 8};
	int n = sizeof(v) / sizeof(*v);
	int i;

	for (i = 0; i < n; ++i)
	{
		Push(i);
		printf("push(%3d). Top(): %3d, Count: %3d\n", i, Top(), count);
	}
	while (!Isempty())
	{
		printf("Pop(): %3d\n", Pop());
	}
}
char *infix(char *s)
{
	char *p = (char *) malloc(strlen(s) + 1);
	char c, tmp;
	int i, j;

	if (p == NULL)
	{
		printf("malloc() return NULL\n");
		return NULL;
	}
	for (i = 0, j = 0; (c = s[i]) != '\0'; ++i)
	{
		if (isalnum(c))
		{
			p[j++] = c;
			continue;
		}
		switch(c)
		{
		case '+':
		case '-':
			while (!Isempty() && Top() != '(')
				p[j++] = Pop();
			Push(c);
			break;
		case '*':
		case '/':
			while (!Isempty() && (tmp = Top()) != '(' && tmp != '-' && tmp != '+')
				p[j++] = Pop();
			Push(c);
			break;
		case '(':
			Push('(');
			break;
		case ')':
			while (!Isempty() && (tmp = Top()) != '(')
				p[j++] = Pop();
			if (Top() == '(')
				Pop();
			break;
		}
	}
	while (!Isempty())
		p[j++] = Pop();
	p[j] = '\0';
	strcpy(s, p);
	free(p);
	return s;
}
void test_infix()
{
	char s[] = "a+b*c+(d*e+f)*g";
	char t[] = "a-b-c";
	char r[] = "(a*(b+c)-d)*e+f";

	printf("%s\n", s);
	infix(s);
	printf("%s\n", s);

	printf("%s\n", t);
	infix(t);
	printf("%s\n", t);

	printf("%s\n", r);
	infix(r);
	printf("%s\n", r);
}
int main()
{
	test_stack();
	test_infix();
	return 0;
}
