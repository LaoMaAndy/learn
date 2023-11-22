#include <math.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	double f;
	f = 0.1234;
	f = sin(f);

	return 0;
}
/*
//
// Exercise 4-1:  Write the function strrindex(s, t), which return the position of the rightmost occurrence of t in s, or -1 if there is none.
//
int strrindex(char s[], char t[])
{
	//描述：
	//	从目标字符串接近结尾的地方向前追溯，逐个字符串比较，
	//	如果找到匹配字符，则返回当前位置
	//	如果无法找到，则返回-1
	//	在正向查找的基础上，重新定义开始位置、增量方式即可
	int i, j, k;
	
	for (i = 0; s[i] != '\0'; i++)
		;
	
	for ( ; i >= 0; i--)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}

void test_strrindex(void)
{
	char s[] = "thistttt coud sda ifewjk fdjsak; coudafdsa jkl; jfdsa";
	char t[] = "tt";
	int r;

	printf("source : %s\n", s);
	printf("target : %s\n", t);
	
	r = strrindex(s, t);

	printf("right inedx : %d\n",r);
}

//
// Exercise 4.2. Extend atof to handle scientific notation of the form
//	123.45e-6
// where a floating-point number may be followed by e or E and an optionally signed exponent.
double atofe(char s[])
{
	//描述：
	//	在atof基础上增加exponent的变量
	double val, power, exp_base, exp_val;
	int i, sign, exp;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E')
	 	i++;
	exp_base = (s[i] == '-') ? 0.1 : 10.0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (exp = 0; isdigit(s[i]); i++ )
		exp = 10 * exp + (s[i] - '0');
	for (i = 0, exp_val = 1.0; i < exp; i++)
		exp_val = exp_val * exp_base;
	//printf("exp : %d, exp_val : %f, exp_base: %f\n", exp, exp_val, exp_base);
	
	return sign * val / power * exp_val;
}

void test_atofe(void)
{
	char s[][20] = {"123.45e-", "123.45e-1", "123.45e-2", "123.45e1", "123.45e0"};
	int i, n = sizeof(s) / sizeof(s[0]);

	for (i = 0; i < n; i++)
	{
		printf("The string: %s\n", s[i]);
		printf("The double: %.8f\n", atofe(s[i]));
	}
}
double atof(char s[])
{
	double	val, power;
	int		i, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val / power;
}
void test_atof(void)
{
	char s[] = "-123.345";

	printf("String is %s\n", s);
	printf("Value  is %.8f\n", atof(s));
}
// Exercise 4-3. Given the basic framework, ti's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers.

// Exercise 4-4. Add commands to print the top element of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.

// Exercese 4-5. Add access to library functions like sine, exp, and pow. See <math.h> in Appendix B, Section4.

// Exercise 4-6. Add commands for handing variables. (It's easy to provide twenty-six variables with single-letter names.) Add a variable for the most recently printed value.

//  Exercise 4-7. Write a rountine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetch?

// Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.

// Exercise 4-9. Our getch and ungetch do not handle a pushend-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design.

// Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes getch and ungetch unnecessary. Revise the calculator to use this approach.
//

#define MAXOP 100
#define NUMBER '0'
#define SIN_COMMAND 's'
#define COS_COMMAND 'c'
#define EXP_COMMAND 'e'
#define POW_COMMAND 'p'


int getop(char []);
void push(double);
double pop(void);

void polish(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case SIN_COMMAND:
				push(sin(pop()));
				break;
			case COS_COMMAND:
				push(cos(pop()));
				break;
			case EXP_COMMAND:
				push(exp(pop()));
				break;
			case POW_COMMAND:
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else 
					printf("division error: zero divesor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);
				else 
					printf("modulus error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("operator error: unknown command %s\n", s);
				break;
		}
	}
}

#define STACK_MAX_SIZE 100
int stack_top = 0;
double stack_val[STACK_MAX_SIZE];

void push(double f)
{
	if (stack_top < STACK_MAX_SIZE)
		stack_val[stack_top++] = f;
	else
		printf("Stack error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (stack_top > 0)
		return stack_val[--stack_top];
	else
	{
		printf("Stack error: stack empty\n");
		return 0.0;
	}
}

double get_top(void)
{
	if (stack_top > 0)
		return stack_val[stack_top];
	else
	{
		printf("Stack error: stack empty\n");
		return 0.0;
	}
}
void copy_top(void)
{
	push(get_top());
}
void exchage_top(void)
{
	double op1, op2;

	op1 = pop();
	op2 = pop();
	push(op1);
	push(op2);
}
void clear_stack(void)
{
	stack_top = 0;
}

int my_getch(void);
void my_ungetch(int);

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = my_getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '-')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = my_getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = my_getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		my_ungetch(c);
	
	return NUMBER;
}

#undef BUF_SIZE
#define BUF_SIZE 100

char char_buf[BUF_SIZE];
int buf_count = 0;

int my_getch(void)
{
	return (buf_count > 0) ? char_buf[--buf_count] : getchar();
}

void my_ungetch(int c)
{
	if (buf_count >= BUF_SIZE)
		printf("ungetchar error: too many chars\n");
	else
		char_buf[buf_count++] = c;
}

#define TEST(func) printf("test function: "#func"\n");func()

int main(int argc, char *argv[])
{
	TEST(polish);
	//TEST(test_atof);
	//TEST(test_atofe);
	//TEST(test_strrindex);

	return 0;
}
*/
