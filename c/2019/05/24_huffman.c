/*
 * huffman code 
 */
#include "template/head.h"

htree *htree_freq(int freq[], int n, htree *h)
{
	int i, j, min_est, min_er;

	for (i = 0; i < n; ++i)
	{
		h[i].freq = freq[i];
		h[i].left = h[i].right = h[i].parent = -1;
	}
	for (i = n; i < 2 * n - 1; ++i)
	{
		for (j = 0; h[j].parent != -1; ++j)
			;
		min_est = j;
		for (++j; h[j].parent != -1; ++j)
			;
		min_er = j;
		if (h[j].freq < h[min_est].freq)
		{
			min_er = min_est;
			min_est = j;
		}
		for (++j; j < n; ++j)
		{
			if (h[j].patent == -1)
			{
				if (h[j].freq < h[min_est].freq)
				{
					min_er = min_est;
					min_est = j;
				}
				else if (h[j].freq < h[min_er].freq)
					min_er = j;
			}
		}
		h[i].freq = h[min_est].freq + h[min_er].freq;
		h[i].left = min_est;
		h[i].right = min_er;
		h[i].parent = -1;
		h[min_est].parent = h[min_er].parent = i;
	}
	return h;
}
char **htree_table(htree *h, int n, char *tab[])
{
	char buf[n + 1], *ptr;
	int i, nod, parent;

	for (i = 0; i < n; ++i)
	{
		for (nod = i, ptr = buf; h[nod])
	}
}