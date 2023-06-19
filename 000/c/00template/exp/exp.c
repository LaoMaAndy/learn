#include "template/head.h"

#define MAXOP 100
#define NUMBER '0'

int Getop(char*);
void Push(double);
double Pop(void);
int getch(void);
void ungetch(int c);

void calc()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = Getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			Push(atof(s));
			break;
		case '+':
			Push(Pop() + Pop());
			break;
		case '*':
			Push(Pop() * Pop());
			break;
		case '-':
			op2 = Pop();
			Push(Pop() - op2);
			break;
		case '/':
			op2 = Pop();
			if (op2 != 0.0)
				Push(Pop() / op2);
			else
				printf("Error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", Pop());
			break;
		default:
			printf("error: unknow command %s\n", s);
			break;
		}
	}
}

#define MAXVAL 100
int sp = 0;
double  val[MAXVAL];
void Push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
double Pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}
int Getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!Isdigit(c) && c != '.')
		return c;
	i = 0;
	if(Isdigit(c))
	while (Isdigit(s[++i] = c = getch()))
		;
	if (c == '.')
		while (Isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
#define BUF_SIZE 100
int bufp = 0;
char buf[BUF_SIZE];
int getch(void)
{
	return (bufp == 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if (bufp >= BUF_SIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
int main()
{
	printf("Input reverse Polish express:\n");
	calc();
	return 0;
}