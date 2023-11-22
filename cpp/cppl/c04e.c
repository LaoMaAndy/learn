#include <math.h>
#include <stdio.h>
#include <ctype.h>

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

#define MAXOP 		100
#define NUMBER		1
#define SET_VAR		2
#define GET_VAR		3
#define FUNC_CALL	4
#define LINE_FINISH	5

#define SIN_FUNC	'S'
#define COS_FUNC	'C'
#define EXP_FUNC	'E'
#define POW_FUNC	'P'

double var_value['z' - 'a'];

int getop(char []);
double push(double);
double pop(void);
double get_top(void);
void copy_top(void);
void exchage_top(void);
void clear_stack(void);

void polish(void)
{
	int type;
	double op1, op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case FUNC_CALL:
				//printf("here is a function call , s[0]: %c\n", s[0]);
				switch (s[0])
				{
					case SIN_FUNC:
						push(sin((op1 = pop())));
						printf("op1 is %.3f\n", op1);
						break;
					case COS_FUNC:
						push(cos((op1 = pop())));
						printf("op1 is %.3f\n", op1);
						break;
					case EXP_FUNC:
						push(exp((op1 = pop())));
						printf("op1 is %.3f\n", op1);
						break;
					case POW_FUNC:
						op2 = pop();
						push(pow((op1 = pop()), op2));
						printf("op1: %.3f, op2: %.3f\n", op1, op2);
						break;
					default:
						printf("Function error, unknown function : %c\n", s[0]);
						break;
				}
				break;
			case SET_VAR:
				if (s[0] >= 'a' && s[0] <= 'z')
				{
					var_value[s[0] - 'a'] = pop();
					printf("Valiable %c set value: %.3f\n", s[0], var_value[s[0] - 'a']);
				}
				else 
					printf("Variable error: Invalid var name: %c\n", s[0]);
				break;
			case GET_VAR:
				if (s[0] >= 'a' && s[0] <= 'z')
				{
					push(var_value[s[0] - 'a']);
					printf("Variable %c is : %.3f\n", s[0], var_value[s[0] - 'a']);
				}
				else
					printf("Variable error: Invalid var name: %c\n", s[0]);
				break;
			case NUMBER:
				op1 = push(atof(s));
				printf("Number: %.3f\n", op1);
				break;
			case '+':
				push((op1 = pop()) + (op2 = pop()));
				printf("op1: %.3f, op2: %.3f\n", op1, op2);
				break;
			case '*':
				push((op1 = pop()) * (op2 = pop()));
				printf("op1: %.3f, op2: %.3f\n", op1, op2);
				break;
			case '-':
				op2 = pop();
				push((op1 = pop()) - op2);
				printf("op1: %.3f, op2: %.3f\n", op1, op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
				{
					push((op1 = pop()) / op2);
					printf("op1: %.3f, op2: %.3f\n", op1, op2);
				}
				else 
					printf("division error: zero divesor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
				{
					op1 = pop();
					push((int)op1 % (int)op2);
					printf("op1: %d, op2: %d\n", (int)op1, (int)op2);
				}
				else 
					printf("modulus error: zero divisor\n");
				break;
			case '\n':
				printf("\t\t = %.8g\n", get_top());
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

double push(double f)
{
	if (stack_top < STACK_MAX_SIZE)
		return (stack_val[stack_top++] = f);
	else
	{
		printf("Stack error: stack full, can't push %g\n", f);
		return 0.0;
	}
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
		return stack_val[stack_top - 1];
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

int 	my_getch(void);
void 	my_ungetch(int);
int 	my_getch_v2(void);
void 	my_ungetch_v2(int c);
int 	my_getch_v3(void);
void 	my_ungetch_v3(int c);

#define GETCH()			my_getch_v3()
#define UNGETCH(c)		my_ungetch_v3(c)

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = GETCH()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '-' && c != '=')
	{
		if (islower(c))
			return GET_VAR;
		else if (isupper(c))
			return FUNC_CALL;
		else
			return c;
	}
	i = 0;
	if (c == '=')
	{
		while (isspace(s[0] = c = GETCH()))
			;
		if(isalpha(s[0] = c))
			return SET_VAR;
		else
			UNGETCH(c);
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = GETCH()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = GETCH()))
			;
	s[i] = '\0';
	if (c != EOF)
		UNGETCH(c);
	
	return NUMBER;
}

#undef  BUF_SIZE
#define BUF_SIZE 100

char char_buf[BUF_SIZE];
int buf_count = 0;
int EOF_flag = 0;

int my_getch(void)
{
	int c;

	if (EOF_flag)
		return EOF;
	else
	{
		c = (buf_count > 0) ? char_buf[--buf_count] : getchar();
		if (c == EOF)
			EOF_flag = 1;
	}
	
	return c;
}

void my_ungetch(int c)
{
	if (buf_count >= BUF_SIZE)
		printf("ungetchar error: too many chars\n");
	else
	{
		char_buf[buf_count] = c;
		if (c == EOF)
			EOF_flag = 1;
		else
			++buf_count;
	}
}

void my_ungets(char s[])
{
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
		;
	for (	; i >=0; --i)
		my_ungetch(s[i]);
}

void test_ungets(void)
{
	int c;
	my_ungets("This is a test 1234567890abcdefg");
	while ((c = my_getch()) != EOF)
		putchar(c);
}

int unget_char;
int unget_char_flag;

int my_getch_v2(void)
{
		if (unget_char_flag)
		{
			unget_char_flag = 0;
			return unget_char;
		}
		else
			return getchar();
}

void my_ungetch_v2(int c)
{
	unget_char_flag = 1;
	unget_char = c;
}

#undef LINE_BUF_SIZE 
#define LINE_BUF_SIZE 1024
char line_buf[LINE_BUF_SIZE + 1];
int  cur_char;

int get_line(void)
{
	int i, c;

	for (i = 0; i < LINE_BUF_SIZE && (c = getchar()) != EOF && c != '\n'; i++)
		line_buf[i] = c;
	if (c == '\n')
		line_buf[i++] = '\n';
	line_buf[i] = '\0';
	cur_char = 0;

	return i;
}
void test_get_line(void)
{
	int i;
	
	i = get_line();
	printf("%s\t%d\n", line_buf, i);
}

int my_getch_v3(void)
{
	if (line_buf[cur_char] == '\0')
	{
		if (get_line() == 0)
			return EOF;
		else
			return (line_buf[cur_char++]);
	}
	else
		return (line_buf[cur_char++]);
}

void my_ungetch_v3(int c)
{
	cur_char = (cur_char > 0) ? cur_char - 1 : 0;	
}
//
// Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.
//
// Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.
//
void itoa_re(int v)
{
	//描述
	//	先写出一个最基本的转换，即对最基本单元的转换
	//	如何从整体中提取最基本的转换单元
	//	用递归调用的方式进行描述
	//	返回条件
	//	递归调用可以替代一次循环结构

	putchar(v % 10 + '0');
	if (v < 10) 
		return ;
//	itoa_re(v / 10);
}
void test_itoa(void)
{
	int i = 12345678;
	itoa_re(i);
}

// Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the string s in place.
void reverse_re(char s[], int left, int right)
{
	// I have no idea about this program.	
}

// Exercise 4-14. Define a macro swap(t, x, y) that interchanges two arguments of type t.(Block structure will help.)

#define SWAP(t, x, y) 		do{				\
							t temp;			\
							temp = x;		\
							x = y;			\
							y = temp;		\
							}while(0)

void test_swap(void)
{
	int x = 23;
	int y = 67;
	
	printf("x is: %d, y is: %d\n", x, y);
	SWAP(int, x, y);
	printf("After swap,\nx is: %d, y is: %d \n", x, y);
}

#define TEST(func) printf("test function: "#func"\n");func()

int main(int argc, char *argv[])
{
	TEST(test_swap);
	//TEST(test_itoa);
	//TEST(test_get_line);
	//TEST(test_ungets);
	//TEST(polish);
	//TEST(test_atof);
	//TEST(test_atofe);
	//TEST(test_strrindex);

	return 0;
}

