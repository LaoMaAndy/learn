/* tree.c */
#include "template/head.h"

struct tree 
{
	char *word;
	int count;
	struct tree *left, *right;
};
struct tree *tree_upd(struct tree *root, const char *word)
{
	int r;

	if (root == NULL)
	{
		root = (struct tree *) malloc(sizeof(*root));
		if (root == NULL || (root->word = Strdup(word)) == NULL)
			return NULL;
		root->count = 1;
		root->left = root->right = NULL;
	}
	else
	{
		r = Strcmp(root->word, word);
		if (r > 0)
			root->left = tree_upd(root->left, word);
		else if (r < 0)
			root->right = tree_upd(root->right, word);
		else
			++root->count;
	}
	return root;
}
void tree_prn(struct tree *root)
{
	if (root == NULL)
		return;
	tree_prn(root->left);
	printf("Count: %3d, Word: %s\n", root->count, root->word);
	tree_prn(root->right);
}	
void file_tree(FILE *fp)
{
	char buf[300];
	int bsize = sizeof(buf) / sizeof(*buf);
	struct tree *root = NULL;

	while (Getword(fp, buf, bsize) != EOF)
		if (Isalpha(*buf))
			root = tree_upd(root, buf);
	tree_prn(root);
}
/* table */
struct table 
{
	char *word, *def;
	int count;
	struct table *next;
};
unsigned Hash(const char *word, int size)
{
	unsigned val;

	for (val = 0; *word != '\0'; ++word)
		val = val * 31 + *word;
	return val % size;
}
struct table *tab_seek(struct table *list[], int nlist, const char *word)
{
	unsigned h = Hash(word, nlist);
	struct table *p;

	for (p = list[h]; p != NULL; p = p->next)
		if (Strcmp(p->word, word) == 0)
			return p;
	return NULL;
}
struct table *tab_upd(struct table *list[], int nlist, const char *word, const char *def)
{
	unsigned h;
	struct table *p;

	p = tab_seek(list, nlist, word);
	if (p == NULL)
	{
		p = (struct table *) malloc(sizeof(*p));
		if (p == NULL || (p->word = Strdup(word)) == NULL)
			return NULL;
		h = Hash(word, nlist);
		p->next = list[h];
		list[h] = p;
		p->count = 1;
	}
	else
	{
		++p->count;
		free(p->def);
	}
	if ((p->def = Strdup(def)) == NULL)
		return NULL;
	return p;
}
void tab_prn(struct table *list[], int nlist)
{
	int i, j;
	struct table *p;

	for (i = 0; i < nlist; ++i)
		for (p = list[i], j = 1; p != NULL; p = p->next, ++j)
			printf("Pos:%3d-%1d, Count: %3d, Word: %30s, Define: %s\n", i, j, p->count, p->word, p->def);
}
void file_table(FILE *fp)
{
	char buf[300];
	int bsize = sizeof(buf) / sizeof(*buf);
	struct table *list[199];
	int nlist = sizeof(list) / sizeof(*list);
	int i;

	for (i = 0; i < nlist; ++i)
		list[i] = NULL;
	while (Getword(fp, buf, bsize) != EOF)
		if (Isalpha(*buf))
			tab_upd(list, nlist, buf, "99112--");
	tab_prn(list, nlist);
}
