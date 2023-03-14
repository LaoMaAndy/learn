/* 
 * tree. count word
 */
#include "000string.c"

struct tnode 
{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *talloc(void)
{
	return (struct tnode *) malloc (sizeof(struct tnode));
}

char *strdup(char *s)
{
	char *p;

	p = (char *) malloc(Strlen(s) + 1);
	if (p != NULL)
		Strcpy(p, s);
	return p;
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL)
	{
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} 
	else if ((cond = Strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL)
	{
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}


#define MAXWORD 100
int main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	if (argc == 1)
	{
		printf("usage: command + argument.\n");
		return 0;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Can't open file: %s\n", argv[1]);
		return 0;
	}
	while (Getword(fp, word, MAXWORD) != EOF)
		if (Isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}


