/* test bintree.c */
#include "bintree.h"

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void init_order(int v[], int n)
{
	int i;

	for (i = 0; i < n; ++i)
		v[i] = i;
}
void init_rand(int v[], int n)
{
	int i;

	init_order(v, n);
	for (i = 0; i < n; ++i)
		swap(v, i, rand() % n);
}
void prn_line(int n)
{
	static int i = 0;

	if (i % n == (n - 1))
		printf("\n");
	else 
		printf("\t");
	++i;
}
void prn_node(tree *root)
{
	static int i = 0;
	if (root == NULL)
		return;
	printf("(%2d, ", root->val);
	if (root->left != NULL)
		printf("%2d, ", root->left->val);
	else
		printf("nl, ");
	if (root->right != NULL)
		printf("%2d", root->right->val);
	else
		printf("nl");
	printf("h%d,", root->height);
	printf("d%d", root->depth);
	printf(")");
	printf("%c", ((i++ % 4 == 3) ? '\n' : '\t'));
}
//#define MAX_STACK (sizeof(value) / sizeof(*value))
#define MAX_STACK 1000
void *stack[MAX_STACK];
int stack_size = sizeof(stack) / sizeof(*stack);
void **stack_ptr = stack;
void push(void *p)
{
	if (stack_ptr - stack >= stack_size)
		printf("Stack overflow\n");
	else
		*stack_ptr++ = p;
}
int isempty()
{
	return (stack_ptr <= stack) ? 1 : 0;
}
void *pop()
{
	if (stack_ptr <= stack)
	{
		printf("stack empty\n");
		return NULL;
	}
	return *--stack_ptr;
}
void *top()
{
	return *(stack_ptr - 1);
}
// second stack
void *stack2[MAX_STACK];
int stack_size2 = sizeof(stack2) / sizeof(*stack2);
void **stack_ptr2 = stack2;
void push2(void *p)
{
	if (stack_ptr2 - stack2 >= stack_size2)
		printf("Stack2 overflow\n");
	else
		*stack_ptr2++ = p;
}
int isempty2()
{
	return (stack_ptr2 <= stack2) ? 1 : 0;
}
void *pop2()
{
	if (stack_ptr2 <= stack2)
	{
		printf("stack empty\n");
		return NULL;
	}
	return *--stack_ptr2;
}
/////////////
void test_stack()
{
	int nvalue = 20;
	int i, n;
	int value[nvalue];
	int *p;

	init_rand(value, nvalue);
	for (i = 0; i < nvalue; ++i)
	{
		push(&value[i]);
		n = *(int *)top();
		printf("%3d: %d\n", i, n);
	}
	push(NULL);
	for (i = 0; i < nvalue; ++i)
	{
		p = (int *) pop();
		if (p != NULL)
			n = *p;
		printf("%3d: %d\t", i, n);
	}
	pop();
	printf("\n");
}
// queue
void *queue[MAX_STACK];
//void *queue[20];

int que_size = sizeof(queue) / sizeof(*queue);
void **qfront = queue;
void **qrear = queue;
void enque(void *p)
{
	void **next = qrear;

	++next;
	if (next - queue >= que_size)
		next = queue;
	if (next == qfront)
		printf("queue full\n");
	else
	{
		*qrear = p;
		//printf("enque: %d\n", (*(int*)(*qrear)));
		qrear = next;
	}
}
void *deque()
{
	void *v = NULL;

	if (qfront == qrear)
		printf("queue empty\n");
	else
	{
		v = *qfront++;
		if (qfront - queue >= que_size)
			qfront = queue;
	} 
	return v;
}
int qempty()
{
	return (qfront == qrear) ? 1 : 0;
}
void test_que()
{
	int i, n = que_size;
	int val[que_size];
	int *p;

	for (i = 0; i < n; ++i)
		val[i] = i;
	printf("qempty(): %d\n", qempty());
	for (i = 0; i < n; ++i)
		enque(&val[i]);
	printf("qempty(): %d\n", qempty());
	for (i = 0; i < n; ++i)
	{
		p = (int *) deque();
		if (p != NULL)
			printf("deque: %d\n", *p);
	}
	printf("qempty(): %d\n", qempty());
}
//#define foo(p) do{if(p != NULL) printf("%s:%3d", __func__, (p)->val); static int i = 0; printf("%c", ((i++ % 4 == 3) ? '\n' : '\t'));}while(0);
#define NVAL 16
int t_value[NVAL + 1];
int t_n = 0;
int t_cur = 0;
void foo(tree *p)
{
	if (p == NULL || t_cur >= NVAL + 1)
		return;
	//printf("foo: cur: %3d, val: %3d\n", t_cur, p->val);
	t_value[t_cur] = p->val;
	++t_cur;
	t_n = t_cur;
}
void fooreset()
{
	t_cur = 0;
}
void fooshow()
{
	int i;

	for (i = 0; i < t_n; ++i)
		printf("%2d, ", t_value[i]);
	fooreset();
}
void foocomp(int result[], int n)
{
	int i;

	for (i = 0; i < n; ++i)
		if (t_value[i] != result[i])
		{
			printf("...error. \n");
			return;
		}
	printf("...OK.\n");
	fooreset();
}
void prn_height(tree *root)
{
	if (root != NULL)
	{
		printf("%2d,", root->height);
		prn_height(root->left);
		prn_height(root->right);
	}
}
void prn_depth(tree *root)
{
	if (root != NULL)
	{
		printf("%2d,", root->depth);
		prn_depth(root->left);
		prn_depth(root->right);
	}
}
void prn_val(tree *root)
{
	if (root != NULL)
	{
		prn_val(root->left);
		printf("value: %3d, height: %3d, depth: %3d\n", root->val, root->height, root->depth);
		prn_val(root->right);
	}
}
void test_height()
{
	int i, j, k, ok;
	tree *root = NULL, *p;
	int value[]      = {8,  4,  2,  1,  0,  3,  6,  5,  7, 12, 10,  9, 11, 13, 14, 15};
	int val_height[] = {4,  3,  2,  1,  0,  0,  1,  0,  0,  3,  1,  0,  0,  2,  1,  0};
	int val_depth[]  = {0,  1,  2,  3,  4,  3,  2,  3,  3,  1,  2,  3,  3,  2,  3,  4};
	int n = sizeof(value) / sizeof(*value);

	for (i = 0; i < n; ++i)
		root = tree_ins(root, value[i]);
	prn_val(root);
	printf("\n");
	tree_height(root);
	prn_val(root);
	//prn_height(root);
}
void test_bin()
{
	int i, j, k, ok;
	tree *root = NULL, *p;
	int value[]      = {8,  4,  2,  1,  0,  3,  6,  5,  7, 12, 10,  9, 11, 13, 14, 15};
	int val_insort[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15};
	int val_del_4[]  = {8,  5,  2,  1,  0,  3,  6,  7, 12, 10,  9, 11, 13, 14, 15    };
	int val_del_8[]  = {9,  5,  2,  1,  0,  3,  6,  7, 12, 10, 11, 13, 14, 15        };
	int val_del_0[]  = {9,  5,  2,  1,  3,  6,  7, 12, 10, 11, 13, 14, 15            };
	int val_post[] 	 = {0,  1,  3,  2,  5,  7,  6,  4,  9, 11, 10, 15, 14, 13, 12,  8};
	int val_level[]  = {8,  4, 12,  2,  6, 10, 13,  1,  3,  5,  7,  9, 11, 14,  0, 15};
	int val_height[] = {4,  3,  2,  1,  0,  0,  1,  0,  0,  3,  1,  0,  0,  2,  1,  0};
	int val_depth[]  = {0,  1,  2,  3,  4,  3,  2,  3,  3,  1,  2,  3,  3,  2,  3,  4};

	//init_order(value, NVAL);
	//init_rand(value, NVAL);
	printf("Tree insert:");
	for (i = 0; i < NVAL; ++i)
	{
		//printf("insert: %d\n", value[i]);
		root = tree_ins(root, value[i]);
	}
	tree_pre(root);
	fooshow();
	foocomp(value, NVAL);
	i = tree_find_max(root)->val;
	printf("Tree find max: %d", i);
	if (i == 15)
		printf("  OK\n");
	else
		printf("  Error");
	j = tree_find_min(root)->val;
	printf("Tree find min: %d", j);
	if (j == 0)
		printf("   OK\n");
	else
		printf("   error\n");
	printf("Tree inorder :");
	tree_inorder(root);
	fooshow();
	foocomp(val_insort, NVAL);
	printf("Tree preorder:");
	tree_pre(root);
	fooshow();
	foocomp(value, NVAL);
	printf("tree find");
	ok = 1;
	for (i = 0; i < NVAL; ++i)
	{
		p = tree_find(root, value[i]);
		if (p == NULL)
			printf("find %d return NULL\n", value[i]);
		else if (value[i] != tree_find(root, value[i])->val)
		{
			ok = 0;
			printf("...error\n");
		}
	}
	if (ok != 0)
		printf("...ok\n");
	i = tree_count(root);
	if (i == 16)
		printf("tree_count OK\n");
	else
		printf("tree_count Error\n");
	printf("delete 4 : ");
	root = tree_del(root, 4);
	j = tree_count(root);
	tree_pre(root);
	fooshow();
	foocomp(val_del_4, NVAL - 1);
	printf("delete 8 : ");
	root = tree_del(root, 8);
	k = tree_count(root);
	tree_pre(root);
	fooshow();
	foocomp(val_del_8, NVAL - 2);
	printf("delete 0 : ");
	root = tree_del(root, 0);
	tree_pre(root);
	fooshow();
	foocomp(val_del_0, NVAL - 3);
	if (j == 15 && k == 14)
		printf("tree_del() OK\n");
	else
		printf("tree_del() Error\n");
	root = tree_free(root);
	if (root != NULL)
	{
		printf("tree_free() error\n");
		return;
	}
	else 
		printf("tree_free() ok\n");
	for (i = 0; i < NVAL; ++i)
	{
		//printf("insert: %d\n", value[i]);
		root = tree_ins(root, value[i]);
	}
	fooreset();
	printf("tree_inorder 	   :");
	tree_inorder(root);
	fooshow();
	foocomp(val_insort, NVAL);
	printf("tree_inorder_nr	   :");
	tree_inorder_nr(root);
	fooshow();
	foocomp(val_insort, NVAL);
	printf("tree_pre_order 	   :");
	tree_pre(root);
	fooshow();
	foocomp(value, NVAL);
	printf("tree_pre_order_nr  :");
	tree_pre_nr(root);
	fooshow();
	foocomp(value, NVAL);
	printf("tree_post_order    :");
	tree_post(root);
	fooshow();
	foocomp(val_post, NVAL);
	printf("tree_post_order_nr :");
	tree_post_nr(root);
	//return;
	fooshow();
	foocomp(val_post, NVAL);
	printf("Test level         :");
	tree_level(root);
	fooshow();
	foocomp(val_level, NVAL);
	printf("Tree height: ");
	tree_height(root);
	prn_height(root);
	printf("\n");
	printf("should be  : ");
	for (i = 0; i < sizeof(val_height) / sizeof(*val_height); ++i)
		printf("%2d,", val_height[i]);
	printf("\n");
	printf("Tree depth : ");
	tree_depth(root);
	prn_depth(root);
	printf("\n");
	printf("should be  : ");
	for (i = 0; i < sizeof(val_depth) / sizeof(*val_depth); ++i)
		printf("%2d,", val_depth[i]);
	printf("\n");
//
	printf("-------\n");
	//test_height();
	tree_free(root);
}
int main()
{
	//test_stack();
	//test_que();
	test_bin();
	//test_height();

	return 0;
}