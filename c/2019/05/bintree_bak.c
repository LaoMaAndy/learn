#include "bintree.h"

struct tree
{
	int val, height, depth;
	int count;
	tree *left, *right;
};
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
		root->height = root->depth = 0;
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

	if (root == NULL)
		return NULL;
	r = root->val - val;
	if (r > 0)
		return tree_find(root->left, val);
	else if (r < 0)
		return tree_find(root->right, val);
	return root;
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
	else if (root->left == NULL)
		{
			temp = root;
			root = root->right;
			free(temp);
		}
	else if (root->right == NULL)
	{
		temp = root;
		root = root->left;
		free(temp);
	}
	else
	{ 
		if (root->left != NULL && root->right != NULL)
		{
			temp = tree_find_min(root->right);
			//printf("del find_min: %d\n", temp->val);
			root->val = temp->val;
			root->right = tree_del(root->right, root->val); 
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
int tree_count(tree *root)
{
	int left, right;
	if (root == NULL)
		return 0;
	left = tree_count(root->left);
	right = tree_count(root->right); 
	return left + right + 1;
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
		//prn_node(root);
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
		//prn_node(root);
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
	tree *p;
	while (root != NULL || !isempty())
		if (root != NULL)
		{
			push(root);
			push2(root);
			//prn_node(root);
			root = root->right;
		}
		else
		{
			root = pop();
			root = root->left;
		}
	while (!isempty2())
	{
		p = (tree *) pop2();
		foo(p);
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
		root->height = h;
		foo(root);
		//prn_node(root);
		return h;	
	}
	return -1;
}
void tree_depth_n(tree *root, int n)
{
	if (root != NULL)
	{
		root->depth = n;
		foo(root);
		//prn_node(root);
		tree_depth_n(root->left, n + 1);
		tree_depth_n(root->right, n + 1);
	}
}
void tree_depth(tree *root)
{
	tree_depth_n(root, 0);
}
void tree_level(tree *root)
{
	enque(root);
	while (!qempty())
	{
		root = deque();
		if (root == NULL)
			continue;
		foo(root);
		if (root->left !=  NULL)
			enque(root->left);
		if (root->right != NULL)
			enque(root->right);
	}
}