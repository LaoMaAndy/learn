/* kmp search */
#include "template/head.h"

void getlps(const char *s, int *lps);
int kmp_search(const char *dest, const char *sub)
{
	int d, s;
	int dest_len = Strlen(dest);
	int sub_len = Strlen(sub);
	int *lps;

	lps = (int *) malloc(sub_len * sizeof(int));
	if (lps == NULL)
		return -1;
	getlps(sub, lps);
	for (d = s = 0; d < dest_len && s < sub_len; )
	{
		if (dest[d] == sub[s])
		{
			++d;
			++s;
		}
		else if (s != 0)
			s = lps[s - 1];
		else
			++d;
	}
	free(lps);
	if (s == sub_len)
		return d - s;
	return -1;
}
void getlps(const char *s, int *lps)
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
			j = lps[j - 1];
		else
		{
			lps[i] = 0;
			++i;
		}
	}
}