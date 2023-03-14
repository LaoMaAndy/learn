/* kmp search */
#include "template/head.h"

void getlps(const char *s, int lps[])
{
	int i, j;
	int len = Strlen(s);

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
		{
			j = lps[j - 1];
		}
		else
		{
			lps[i] = 0;
			++i;
		}
	}
}
int kmp_search(const char *dest, const char *sub)
{
	int sub_len = Strlen(sub);
	int dest_len = Strlen(dest);
	int i, j;
	int *lps;

	lps = (int *) malloc(sub_len * sizeof(int));
	if (lps == NULL)
		return -1;
	getlps(sub, lps);
	for (i = j = 0; i < dest_len && j < sub_len;  )
	{
		if (dest[i] == sub[j])
		{
			++i;
			++j;
		}
		else if (j != 0)
		{
			j = lps[j - 1];
		}
		else
		{
			++i;
		}
	}
	if (j == sub_len)
		return i - j;
	return -1;
}