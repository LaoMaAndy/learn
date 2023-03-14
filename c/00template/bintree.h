#include "head.h"
#ifndef BINTREE_H
#define BINTREE_H
////// binary tree /////////
/// bintree.h
// stack
void push(void *p);
void *pop();
int isempty();
void push2(void *p);
void *pop2();
int isempty2();
// queue
void enque(void *p);
void *deque();
int qempty();

typedef struct tree tree;
struct tree
{
	int val, count, depth, height;
	tree *left, *right;
};
void foo(tree *p);
void prn_line(int n);
void prn_node(tree *root);

// bintree
tree *tree_ins(tree *root, int val);
tree *tree_find(tree *root, int val);
tree *tree_del(tree *root, int val);
tree *tree_free(tree *root);
tree *tree_find_min(tree *root);
tree *tree_find_max(tree *root);
void tree_inorder(tree *root);
void tree_inorder_nr(tree *root);
void tree_pre(tree *root);
void tree_pre_nr(tree *root);
void tree_post(tree *root);
void tree_post_nr(tree *root);
void tree_level(tree *root);
int tree_height(tree *root);
int tree_count(tree *root);
void tree_depth(tree *root);
void tree_depth_n(tree *root, int n);
#endif