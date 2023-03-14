/* 
 * bin tree
 */
#include "template/bintree.h"

tree *tree_ins(tree *root, int val)
{
	if (root == NULL)
	{
		root = (tree *) malloc(sizeof(*root));
		if (root == NULL)
			return NULL;
		root->val = val;
		root->count = 1;
		root->depth = root->height = 0;
		root->left = root->right = NULL;
	}
}