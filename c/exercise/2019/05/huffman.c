/* huffman.c */
#include "template/head.h"

htree *htree_freq(int freq[], int n, htree *p)
{
	int i, j, min_a, min_b;

	for (i = 0; i < n; ++i)
	{
		p[i].freq = freq[i];
		p[i].parent = p[i].left = p[i].right = -1;
	}
	printf("init ok\n");
	for (i = n; i < 2 * n - 1; ++i)
	{
		for (j = 0; p[j].parent != -1; ++j)
			;
		min_a = j;
		for (++j; p[j].parent != -1; ++j)
			;
		if (p[j].freq < p[min_a].freq)
		{
			min_b = min_a;
			min_a = j;
		}
		else
			min_b = j;
		//printf("[%d] min_a: %3d, min_b: %3d\n", j, min_a, min_b);
		for (++j; j < i; ++j)
		{
			if (p[j].parent == -1)
			{
				if (p[j].freq < p[min_a].freq)
				{
					min_b = min_a;
					min_a = j;
				}
				else if (p[j].freq < p[min_b].freq)
					min_b = j;
			}
		}
		printf("min_a: %3d, min_b: %3d\n", min_a, min_b);
		p[i].freq = p[min_a].freq + p[min_b].freq;
		p[i].left = min_a;
		p[i].right = min_b;
		p[i].parent = -1;
		p[min_a].parent = p[min_b].parent = i;
	}
	return p;
}
char **htree_table(htree *h, int n, char *table[])
{
	int i, j, p, k;
	char buf[n + 1];

	for (i = 0; i < n; ++i)
	{
		for (j = i, k = 0; h[j].parent != -1; j = h[j].parent, ++k)
		{
			p = h[j].parent;
			//printf("j: %d, p[j].parent: %d, p[j].")
			buf[k] = (j == h[p].left) ? '0' : '1';
		}
		buf[k] = '\0';
		table[i] = Strrev(Strdup(buf));
		//printf("--%s\n", table[i]);
	}
	return table;
}
htree *htree_rebuild(char *table[], int n, htree *h)
{
	int i, j, empty, cur, len;

	for (i = 0; i < 2 * n - 1; ++i)
		h[i].freq = h[i].parent = h[i].left = h[i].right = -1;
	empty = n;
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
					h[cur].left = empty;
					h[empty].parent = cur;
					++empty;
				}
				cur = h[cur].left;
			}
			else if (table[i][j] == '1')
			{
				if (h[cur].right == -1)
				{
					h[cur].right = empty;
					h[empty].parent = cur;
					++empty;
				}
				cur = h[cur].right;
			}
		}
		if (table[i][j] == '0')
			h[cur].left = i;
		else 
			h[cur].right = i;
		h[i].parent = cur;
	}
	return h;
}
int htree_index(const char *s, char c)
{
	char *p;

	return ((p = strchr(s, c)) == NULL) ? -1 : (p - s);
}
char *htree_encode(char *table[], int n, const char *ch, const char *text, char *output)
{
	int i;

	for ( ; *text != '\0'; ++text)
		if ((i = htree_index(ch, *text)) != -1)
			strcat(output, table[i]);
	return output;
}
char *htree_decode(htree *h, int n, const char *ch, const char *input, char *output)
{
	int i, c;

	for (i = 2 * n - 2; *input != '\0'; ++input)
	{
		c = *input;
		if (c == '0')
			i = h[i].left;
		else if (c == '1')
			i = h[i].right;
		else 
			break;
		if (i < n)
		{
			*output++ = ch[i];
			i = 2 * n - 2;
		}
	}
	*output = '\0';
	return output;
}
