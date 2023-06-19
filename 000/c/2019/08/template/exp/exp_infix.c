/* Infix express */
#include "template/head.h"

struct oper
{
	char *op;
	int level;
	int nary;
	int dire;
};
typedef struct oper oper;
oper op_basic[] = {
	{"(",	50,		0, 0},
	{")", 	-50,	0, 1},
	{"+",	5,		2, 1},
	{"-",	5,		2, 1},
	{"*",	4,		2, 1},
	{"/",	4,		2, 1},
	{"%",	4,		2, 1},
	{"++",	2,		1, 1},
	{"--",	2,		1, 1},
};
int op_basic_num = sizeof(op_basic) / sizeof(*op_basic);
#define OP_ERROR -100

int op_index(const char *s)
{
	int i;

	for (i = 0; i < op_basic_num; ++i)
		if (strcmp(s, op_basic[i].op) == 0)
			return i;
	return -1;
}
int op_valid(const char *s)
{
	return (op_index(s) == -1) ? 0 : 1;
}
int op_comp(int op1, int op2)
{
	//printf("level 1: %3d, level2 : %3d\n", op_basic[op2].level, op_basic[op1].level);
	return op_basic[op2].level - op_basic[op1].level;
}
int op_nary(int op)
{
	return op_basic[op].nary;
}
const char *op_name(int i)
{
	return op_basic[i].op;
}
void test_op()
{
	char *op[] = {"+", "-", "*", "/"};
	int n = sizeof(op) / sizeof(*op);
	int i, j;
	int op1, op2;

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; j++)
		{
			op1 = op_index(op[i]);
			op2 = op_index(op[j]);
			printf("op1:%3s, op1.id: %2d, op2:%3s, op2.id: %2d comp: %3d\n", op[i], op1, op[j], op2, op_comp(op1, op2));
		}
}
struct node
{
	int type;
	int op;
	double val;
};
typedef struct node node;
node mk_opd(double v)
{
	node n;

	n.type = 1;
	n.val = v;
	return n;
}
node mk_opt(int op)
{
	node n;

	n.type = 2;
	n.op = op;
	return n;
}
/* stack */
#define STACK_SIZE 256
node stack[STACK_SIZE];
int count = 0;

static void Push(node c)
{
	if (count < STACK_SIZE)
		stack[count++] = c;
	else
		printf("push() error: overflow\n");
}
static node Pop()
{
	if (count > 0)
		return stack[--count];
	printf("pop() error: empty\n");
	return (node) {EOF, 0, 0};
}
static int Isempty()
{
	return (count == 0) ? 1 : 0;
}
static node Top()
{
	return stack[count - 1];
}
/* convert a string to a express */
struct str_stream
{
	unsigned char *ptr;
	unsigned char *base;
};
typedef struct str_stream token;
token *Intok(const char *s);
int Token(char *buf, int bsize, token *s);

node *Express(node *p, int n, const char *s)
{
	char buf[200];
	int size = sizeof(buf);
	int i, r;
	double val;
	token *t;

	t = Intok(s);
	while (--n > 0 && (r = Token(buf, size, t)) != EOF)
	{
		//printf("Return val: %2d, Buf: %s\n", r, buf);
		if (r == 1)
		{
			*p++ = mk_opd(atof(buf));
		}
		else if (r == 2)
		{
			//if (op_valid(buf))
				*p++ = mk_opt(op_index(buf));
		}
	}
	*p = (node) {EOF, 0, 0.0};
	return p;
}

node *postfix(node *s)
{
	node tmp, *p = s;
	int i, j;

	for (i = 0, j = 0; s[i].type != EOF; ++i)
	{
		if (s[i].type == 1)
		{
			s[j++] = s[i];
			continue;
		}
		if (s[i].type == 2)
		{
			switch (s[i].op)		
			{
			case 0:			// (
				Push(s[i]);
				continue;
			case 1:			// )
				while (!Isempty() && (tmp = Top()).op != 0)
					s[j++] = Pop();
				if (Top().op == 0)
					Pop();
				break;
			default :
				while (!Isempty() && op_comp(Top().op, s[i].op) >= 0)
					s[j++] = Pop();
				Push(s[i]);
				break;
			}
		}
	}
	while (!Isempty())
		p[j++] = Pop();
	p[j] = (node) {EOF, 0, 0.0};
	return s;
}
void test_express()
{
	char s[] = "11 + 2 * 3 + (4 * 5 + 6) * 7";
	node exp[300];
	int size = sizeof(exp) / sizeof(*exp);
	int i;
	
	Express(exp, size, s);
	printf("string : %s\n", s);
	printf("express: \n");
	for (i = 0; exp[i].type != EOF; ++i)
	{
		if (exp[i].type == 1)
			printf("%5.2f ", exp[i].val);
		if (exp[i].type == 2)
			printf("%s ", op_name(exp[i].op));
	}
	postfix(exp);
	printf("\n----- postfix()\n");
	for (i = 0; exp[i].type != EOF; ++i)
	{
		if (exp[i].type == 1)
			printf("%5.2f ", exp[i].val);
		if (exp[i].type == 2)
			printf("%s ", op_name(exp[i].op));
	}
	printf("\n");
}
void test_gettok();
int main()
{
	//test_gettok();
	// test_op();
	test_express();
	return 0;
}