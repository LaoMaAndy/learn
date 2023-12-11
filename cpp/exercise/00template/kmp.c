/* kmp.c */
#include <stdio.h>		// printf()
#include <stdlib.h>		// malloc(), exit()
#include <string.h>		// strlen(), strncmp()

void getlps(const char *s, int *lps)
{
	int len = strlen(s);
	int i, j;

	lps[0] = 0;
	for (i = 1, j = 0; i < len; )
	{
		if (s[i] == s[j])
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
int kmp_search(const char *dest, const char *sub)
{
	int dest_len = strlen(dest);	
	int sub_len = strlen(sub);
	int i, j;
	int *lps;

	lps = (int *) malloc(sub_len * sizeof(int));
	if (lps == NULL)
	{
		printf("malloc() return NULL\n");
		exit(1);
	}
	getlps(sub, lps);
	i = j = 0;
	for (i = j = 0; i < dest_len && j < sub_len;  )
	{
		if (sub[j] == dest[i])
		{ 
			++j;
			++i;
		}
		else if (j != 0) 
			j = lps[j - 1]; 
		else 
			++i;
	}
	free(lps);
	if (j == sub_len)
		return i - j;
	return -1;
}

