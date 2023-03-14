/* bintree.c */
#include "bintree.h"

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
		root->depth = root->depth = 0;
		root->left = root->right = NULL;
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
		return root;
	r = root->val - val;
	if (r > 0)
		root = tree_find(root->left, val);
	else if (r < 0)
		root = tree_find(root->right, val);
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
		temp = tree_find_min(root->right);
		root->val = temp->val;
		root->right = tree_del(root->right, temp->val);
	}
	return root;
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
int tree_count(tree *root)
{
	int left, right;

	if (root == NULL)
		return 0;
	left = tree_count(root->left);
	right = tree_count(root->right);
	return (left + right + 1);
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
	{
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
	{
		if (root != NULL)
		{
			foo(root);
			push(root);
			root = root->left;
		}
		else
		{
			root = (tree *) pop();
			root = root->right;
		}
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
	while (root != NULL || !isempty())
	{
		if (root != NULL)
		{
			push(root);
			push2(root);
			root = root->right;
		}
		else
		{
			root = (tree *) pop();
			root = root->left;
		}
	}
	while (!isempty2())
		foo((tree *) pop2());
}
void tree_level(tree *root)
{
	if (root == NULL)
		return;
	enque(root);
	while (!qempty())
	{
		root = (tree *) deque();
		if (root != NULL)
		{
			foo(root);
			enque(root->left);
			enque(root->right);
		}
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
		return h;
	}
	return -1;
}
void tree_depth_n(tree *root, int n)
{
	if (root != NULL)
	{
		root->depth = n;
		tree_depth_n(root->left, n + 1);
		tree_depth_n(root->right, n + 1);
	}
}
void tree_depth(tree *root)
{
	tree_depth_n(root, 0);
}

