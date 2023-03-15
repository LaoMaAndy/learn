/* declear */
#include "template/head.h"

#define BUF_SIZE 100
int bufp = 0;
char buf[BUF_SIZE];
static int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
static void ungetch(int c)
{
	if (bufp >= BUF_SIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

#define STACK_SIZE 256
int stack_top = 0;
int stack[STACK_SIZE];

static void Push(int c)
{
	if (stack_top < STACK_SIZE)
		stack[stack_top++] = c;
	else
		printf("push() error: overflow\n");
}
static int Pop()
{
	if (stack_top > 0)
		return stack[--stack_top];
	printf("pop() error: empty\n");
	return 0;
}
static int Isempty()
{
	return (stack_top == 0) ? 1 : 0;
}
static int Top()
{
	return stack[stack_top - 1];
}


#define MAXTOKEN 100
enum {NAME, PARENS, BRACKETS};
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[100];
int gettoken(void);
void dirdcl(void);

void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; )
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " Pointer to");
}
void dirdcl(void)
{
	int type;
	if (tokentype == '(')
	{
		dcl();
		if (tokentype != ')')
			printf("error: missing ) \n");
	}
	else if (tokentype == NAME)
	{
		strcpy(name, token);
	}
	else
		printf("error: expected name or (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS)
	{
		if (type == PARENS)
			strcat(out, " function returning");
		else
		{
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}
int gettoken(void)
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(')
	{
		if ((c = getch()) == ')')
		{
			strcpy(token, "()");
			return tokentype = PARENS;
		}
		else
		{
			ungetch(c);
			return tokentype = '(';
		}
	}
	else if (c == '[')
	{
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	}
	else if (isalpha(c))
	{
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	}
	else
		return tokentype = c;
}

int main()
{
	while (gettoken() != EOF)
	{
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}2