/* binary tree */
#include "template/head.h"

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
///////
struct tree
{
	int val, height, depth;
	int count;
	tree *left, *right;
};
//#define foo(p) do{if(p != NULL) printf("%s:%3d", __func__, (p)->val); static int i = 0; printf("%c", ((i++ % 4 == 3) ? '\n' : '\t'));}while(0);
#define NVAL 16
int t_value[NVAL];
int t_height[NVAL];
int t_depth[NVAL];
int t_cur = 0;
void foo(tree *p)
{
	if (p == NULL)
		return;
	if (t_cur >= NVAL)
		return;
	t_value[t_cur] = p->val;
	t_height[t_cur] = p->height;
	t_depth[t_cur] = p->depth;
	++t_cur;
}
void fooreset()
{
	t_cur = 0;
}
tree *tree_ins(tree *root, int val)
{
	int r;

	if (root == NULL)
	{
		root = (tree *) malloc(sizeof(*root));
		if (root == NULL)
			return NULL;
		root->val = val;
		root->count = 1;
		root->left = root->right = NULL;
		foo(root);
	}
	else
	{
		r = root->val - val;
		if (r > 0)
			root->left = tree_ins(root->left, val);
		else if (r < 0)
			root->right = tree_ins(root->right, val);
		else
			++root->count;
	}
	return root;
}
tree *tree_find(tree *root, int val)
{
	int r;

	if (root != NULL)
	{
		r = root->val - val;
		if (r < 0)
			tree_find(root->left, val);
		else if (r > 0)
			tree_find(root->right, val);
		else
			return root;
	}
	return NULL;
}
tree *tree_free(tree *root)
{
	if (root != NULL)
	{
		tree_free(root->left);
		tree_free(root->right);
		free(root);
	}
	return NULL;
}
tree *tree_find_min(tree *root)
{
	if (root != NULL)
		while (root->left != NULL)
			root = root->left;
	return root;
}
tree *tree_find_max(tree *root)
{
	if (root != NULL)
		while (root->right != NULL)
			root = root->right;
	return root;
}
void tree_inorder(tree *root)
{
	if (root != NULL)
	{
		tree_inorder(root->left);
		foo(root);
		tree_inorder(root->right);
	}
}
void tree_inorder_nr(tree *root)
{
	while (root != NULL || !isempty())
		if (root != NULL)
		{
			push(root);
			root = root->left;
		}
		else
		{
			root = (tree *) pop();
			foo(root);
			root = root->right;
		}
}
void tree_pre(tree *root)
{
	if (root != NULL)
	{
		foo(root);
		tree_pre(root->left);
		tree_pre(root->right);
	}
}
void tree_pre_nr(tree *root)
{
	while (root != NULL || !isempty())
		if (root != NULL)
		{
			foo(root);
			push(root);
			root = root->left;
		}
		else
		{
			root = pop();
			root = root->right;
		}
}
void tree_post(tree *root)
{
	if (root != NULL)
	{
		tree_post(root->left);
		tree_post(root->right);
		foo(root);
	}
}
void tree_post_nr(tree *root)
{
	while (root != NULL || isempty())
	{
		if (root != NULL)
		{
			push2(root);
			push(root);
			root = root->left;
		}
		else
		{
			root = pop();
			root = root->right;
		}
	}
	while (isempty2())
		foo((tree *)pop2());
}
void prn_node(tree *root)
{
	static int i = 0;
	if (root == NULL)
		return;
	printf("(%3d, ", root->val);
	if (root->left != NULL)
		printf("%3d, ", root->left->val);
	else
		printf("Nil, ");
	if (root->right != NULL)
		printf("%3d", root->right->val);
	else
		printf("Nil");
	printf(")");
	printf("%c", ((i++ % 5 == 4) ? '\n' : '\t'));
}
void tree_level(tree *root)
{
	void *p = (void *) -1;

	enque(root);
	while (!qempty())
	{
		root = deque();
		if (root == NULL)
			continue;
		//foo(root);
		if (root->left !=  NULL)
			enque(root->left);
		if (root->right != NULL)
			enque(root->right);
	}
}
int tree_height(tree *root)
{
	int left, right, h;

	if (root != NULL)
	{
		left = tree_height(root->left);
		right = tree_height(root->right);
		h = (left > right) ? (left + 1) : (right + 1); 
		printf("height: %2d, val: %3d", h, root->val);
		prn_line(3);
		return h;	
	}
	return -1;
}
void tree_depth_n(tree *root, int n)
{
	if (root != NULL)
	{
		printf("Depth: %1d, val: %2d", n, root->val);
		prn_line(3);
		tree_depth_n(root->left, n + 1);
		tree_depth_n(root->right, n + 1);
	}
}
void tree_depth(tree *root)
{
	tree_depth_n(root, 0);
}
int tree_count(tree *root)
{
	int left, right;
	if (root == NULL)
		return 0;
	left = tree_count(root->left);
	right = tree_count(root->right); 
	return left + right + 1;
}
tree *tree_del(tree *root, int val)
{
	tree *temp;
	int r;

	if (root == NULL)
		return NULL;
	r = root->val - val;
	if (r > 0)
		root->left = tree_del(root->left, val);
	else if (r < 0)
		root->right = tree_del(root->right, val);
	else
	{
		if (root->left != NULL && root->right != NULL)
		{
			temp = tree_find_min(root->right);
			root->val = temp->val;
			root->right = tree_del(root->right, val); 
		}
		else
		{
			temp = root;
			if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;
			free(temp);
		}
	}
	return root;
}
void test_bin()
{
	int i, j, depth, height;
	tree *root = NULL;
	int nvalue = 13;
	int value[nvalue];

	//init_order(value, nvalue);
	init_rand(value, nvalue);
	printf("Tree insert:\n");
	for (i = 0; i < nvalue; ++i)
		root = tree_ins(root, value[i]);

	i = tree_find_max(root)->val;
	printf("Tree find max: %d\n", i);
	j = tree_find_min(root)->val;
	printf("Tree find min: %d\n", j);

	root = tree_ins(root, value[nvalue / 2]);
	printf("Tree inorder: \n");
	tree_inorder(root);
	printf("Tree height...\n");
	height = tree_height(root);
	printf("Tree height: %d\n", height);
	printf("Tree depth: \n");
	tree_depth(root);

	printf("tree count - del - count\n");
	i = tree_count(root);
	printf("tree count: %d\n", i);
	tree_del(root, 15);
	i = tree_count(root);
	printf("After tree-del: %d\n", i);

	printf("tree_inorder:\n");
	tree_inorder(root);
	printf("\ntree_inorder_nr\n");
	tree_inorder_nr(root);
	printf("\ntree_pre_order:\n");
	tree_pre(root);
	printf("\ntree_pre_order_nr:\n");
	tree_pre_nr(root);
	printf("\ntree_post_order:\n");
	tree_post(root);

	printf("\nTest level: \n");
	tree_level(root);

	tree_free(root);
}
int main()
{
	//test_stack();
	//test_que();
	test_bin();

	printf("\n");
	return 0;
}