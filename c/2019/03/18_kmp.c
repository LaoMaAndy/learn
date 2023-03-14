/* kmp.c */
#include "template/head.h"

void getlps(const char *pat, int *lps)
{
	int i, j;
	int pat_len = strlen(pat);

	lps[0] = 0;
	for (i = 1, j = 0; i < pat_len; )
	{
		if (pat[i] == pat[j])
		{
			++j;
			lps[i] = j;
			++i;
		}
		else if (j != 0)
			j = lps[j - 1];
		else
		{
			lps[i] = 0;
			++i;
		}
	}
}
int kmp_search(const char *txt, const char *pat)
{
	int t, p;
	int t_size, p_size;
	int *lps;

	p_size = strlen(pat);
	t_size = strlen(txt);
	lps = (int *) malloc(p_size * sizeof(int));
	if (lps == NULL)
	{
		printf("malloc() return NULL\n");
		return -1;
	}
	getlps(pat, lps);
	for (t = p = 0; t < t_size && p < p_size;  )
	{
		if (txt[t] == pat[p])
		{
			++t;
			++p;
		}
		else if (p != 0)
			p = lps[p - 1];
		else
			++t;
	}
	free(lps);
	if (p == p_size)
		return t - p;
	return -1;
}
