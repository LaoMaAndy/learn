#include "head.h"
size_t Strlen(const char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}
char *Strcpy(char *dest, const char *src)
{
	char *p = dest;

	while ((*dest++ = *src++) != '\0')
		;
	return p;
}
char *Strdup(const char *s)
{
	char *p;

	p = (char *) malloc(Strlen(s) + 1);
	return (p == NULL) ? p : Strcpy(p, s);
}
char *Strrev(char *s)
{
	char *p, *r, c;

	p = r = s;
	s += Strlen(s);
	for (--s; s > p; --s, ++p)
	{
		c = *s;
		*s = *p;
		*p = c;
	}
	return r;
}
htree *htree_freq(int freq[], int n, htree *p);
char **htree_table(htree *h, int n, char *table[]);
htree *htree_rebuild(char *table[], int n, htree *h);
int htree_index(const char *s, char c);
char *htree_encode(char *table[], int n, const char *ch, const char *text, char *output);
char *htree_decode(htree *h, int n, const char *ch, const char *input, char *output);

void test_huff_tree(void)
{
	int freq[] = {1, 1, 3, 4, 2, 5};
	int n = sizeof(freq) / sizeof(*freq);
	int i;
	char *ch = "abcdef";
	htree tree[2 * n - 1], tree2[2 * n - 1];
	char *table[n], *table2[n];
	char *text = "aabbccddeeffedcba";
	char *encode = "1010101010111011000001011001001111100010010111010";
	char output[300];

	htree_freq(freq, n,  tree);
	for (i = 0; i < 2 * n - 1; ++i)
		printf("[%2d] freq: %2d, parent: %2d, left: %2d, right: %2d\n", i,  tree[i].freq,  tree[i].parent,  tree[i].left,  tree[i].right);
	htree_table( tree, n, table);
	for (i = 0; i < n; ++i)
		printf("[%2d] %5s\n",i, table[i]);
	htree_rebuild(table, n, tree2);
	for (i = 0; i < 2 * n - 1; ++i)
		printf("[%2d] freq: %2d, parent: %2d, left: %2d, right: %2d\n", i, tree2[i].freq, tree2[i].parent, tree2[i].left, tree2[i].right);
	htree_table(tree2, n, table2);
	for (i = 0; i < n; ++i)
		printf("[%2d] %5s\n",i, table2[i]);
	for (i = 0; i < strlen(ch); ++i)
		printf("%d: %c, %c\n", i, ch[i], ch[htree_index(ch, ch[i])]);
	htree_encode(table, n, ch, text, output);
	printf("text  : %s\n", text);
	printf("decode: %s\n", output);
	if (strcmp(output, encode) == 0)
		printf("encode() OK\n");
	else
		printf("encode() Error\n");
	htree_decode(tree, n, ch, encode, output);
	printf("encode: %s\n", output);
	if (strcmp(output, text) == 0)
		printf("decode() OK\n");
	else
		printf("decode() Error\n");
}

int main()
{
	test_huff_tree();
	return 0;
}