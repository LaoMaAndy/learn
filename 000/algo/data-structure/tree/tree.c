#include "../dsaa.h"

struct tree
{
	int val;
	int count;
	struct tree *left, *right;
	char path[2048];
};
typedef struct tree tree;

tree *Insert(tree *root, int val)
{
	int r;
	tree *leaf;

	if (root == NULL)
	{
		root = (tree *) malloc(sizeof(*root));
		if (root == NULL)
			return NULL;
		root->val = val;
		root->count = 1;
		root->left = root->right = NULL;
	}
	else
	{
		r = root->val - val;
		if (r > 0)
		{
			root->left = Insert(root->left, val);
		}
		else if (r < 0)
		{
			root->right = Insert(root->right, val);
		}
		else
		{
			++root->count;
		}
	}
	return root;
}
void Free(tree *root)
{
	if (root == NULL)
		return;
	Free(root->left);
	Free(root->right);
	free(root);
}
char path[2096];
void Prn(tree *root)
{
	if (root == NULL)
		return;
	Prn(root->left);
	printf("%3d\t", root->val);
	Prn(root->right);
} 
void Prn_rev(tree *root)
{
	if (root == NULL)
		return;
	Prn_rev(root->right);
	printf("%3d\t", root->val);
	Prn_rev(root->left);
}
void Prn_pre(tree *root)
{
	if (root == NULL)
		return;
	printf("%3d\t", root->val);
	Prn_pre(root->left);
	Prn_pre(root->right);
}
void Prn_post(tree *root)
{
	if (root == NULL)
		return;
	Prn_post(root->left);
	Prn_post(root->right);
	printf("%3d\t", root->val);
}

void Prn3(tree *root, char *path)
{
	if (root == NULL)
		return;
	Prn3(root->left, strcat(path, "LE "));
	printf("%3d, Path: %s\n", root->val, path);
	Prn3(root->right, strcat(path, "RI "));
}
void Prn2(tree *root)
{
	if (root == NULL)
		return;
	printf("%3d\n", root->val);
	printf("LE ");
	Prn2(root->left);
	printf("RI ");
	Prn2(root->right);
}
void test_insert()
{
	int v[] = {5, 9, 3, 7, 4, 1, 6, 2, 10, 8};
	int i;
	int n = sizeof(v) / sizeof(*v);
	tree *root = NULL;

	for (i = 0; i < n; ++i)
		root = Insert(root, v[i]);
	Prn(root);
	printf("\n");
	Prn_rev(root);
	printf("\n");
	Prn_pre(root);
	printf("\n");
	Prn_post(root);
	printf("\n");
	printf("--------\n");
	Prn2(root);
	printf("--------\n");
	//Prn3(root, path);
	
	Free(root);
}
int main()
{
	test_insert();
	return 0;
}