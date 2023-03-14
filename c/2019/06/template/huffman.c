/*
 * huffman tree algorithms
 */
#include "head.h"

htree *htree_freq(int freq[], int n, htree *h)
{
	int i, j, min_a, min_b;

	for (i = 0; i < n; ++i)
	{
		h[i].freq = freq[i];
		h[i].parent = h[i].left = h[i].right = -1;
	}
	for (i = n; i < 2 * n - 1; ++i)
	{
		for (j = 0; h[j].parent != -1; ++j)
			;
		min_a = j;
		for (++j; h[j].parent != -1; ++j)
			;
		if (h[j].freq < h[min_a].freq)
		{
			min_b = min_a;
			min_a = j;
		}
		else
			min_b = j;
		for (++j; j < i; ++j)
		{
			if (h[j].parent == -1)
			{
				if (h[j].freq < h[min_a].freq)
				{
					min_b = min_a;
					min_a = j;
				}
				else if (h[j].freq < h[min_b].freq)
					min_b = j;
			}
		}
		h[i].freq = h[min_a].freq + h[min_b].freq;
		h[i].left = min_a;
		h[i].right = min_b;
		h[i].parent = -1;
		h[min_a].parent = h[min_b].parent = i;
	}
	return h;
}
char **htree_table(htree *h, int n, char *tab[])
{
	char buf[n + 1], *bp;
	int i, nod, parent;

	for (i = 0; i < n; ++i)
	{
		for (nod = i, bp = buf; h[nod].parent != -1; nod = h[nod].parent, ++bp)
		{
			parent = h[nod].parent;
			*bp = (nod == h[parent].left) ? '0' : '1';
		}
		*bp = '\0';
		tab[i] = Strrev(Strdup(buf));
	}
	return tab;
}
htree *htree_rebuild(char *table[], int n, htree *h)
{
	int i, j, node, cur, len;

	for (i = 0; i < 2 * n - 1; ++i)
		h[i].freq = h[i].parent = h[i].left = h[i].right = -1;
	node = n;
	for (i = 0; i < n; ++i)
	{
		len = strlen(table[i]);
		cur = 2 * n - 2;
		for (j = 0; j < len - 1; ++j)
		{
			if (table[i][j] == '0')
			{
				if (h[cur].left == -1)
				{
					h[cur].left = node;
					h[node].parent = cur;
					++node;
				}
				cur = h[cur].left;
			}
			else if (table[i][j] == '1')
			{
				if (h[cur].right == -1)
				{
					h[cur].right = node;
					h[node].parent = cur;
					++node;
				}
				cur = h[cur].right;
			}
		}
		if (table[i][j] == '0')
			h[cur].left = i;
		else if (table[i][j] == '1')
			h[cur].right = i;
		h[i].parent = cur;
	}
	return h;
}
int htree_index(const char *str, char c)
{
	const char *p = str;

	for ( ; *str != '\0'; ++str)
		if (*str == c)
			return str - p;
	return -1;
}
char *htree_encode(char *table[], int n, const char *ch, const char *input, char *output)
{
	int i;
	char *p;

	for ( ; *input != '\0'; ++input)
	{
		i = htree_index(ch, *input);
		if (i != -1)
			for (p = table[i]; *p != '\0'; ++p)
				*output++ = *p;
	}
	*output = '\0';
	return output;
}
char *htree_decode(htree *h, int n, const char *ch, const char *input, char *output)
{
	int node, c, head;

	head = 2 * n - 2;
	for (node = head; *input != '\0'; ++input)
	{
		c = *input;
		if (c == '0')
			node = h[node].left;
		else if (c == '1')
			node = h[node].right;
		if (node < n)
		{
			*output++ = ch[node];
			node = head;
		}
	}
	*output = '\0';
	return output;
}