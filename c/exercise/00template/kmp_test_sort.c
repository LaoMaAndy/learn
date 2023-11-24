/* test_base_sort.c */
#include "head.h"
#define REGU_TEST_TIME 200

void swap(int v[], int i, int j);
void hpsort(int v[], int n);
void rdsort(int v[], int n);
void mgsort(int v[], int n);
void qksort(int v[], int n);
void shsort(int v[], int n);
void insort(int v[], int n);
void bbsort(int v[], int n);

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void test_sort_result(int v[], int n)
{
	int i;

	printf(" Result");
	for (i = 0; i < n - 1; ++i)
		if (v[i] > v[i + 1])
		{
			printf("..Error.");
			return;
		}
	printf("..OK.");
}
void regu_sort(int n, void (*sort)(int [], int))
{
	int v[n];
	int i;

	for (i = 0; i < n; ++i)
		v[i] = rand() % 100;
	printf("\tTotal:%4d", n);
	sort(v, n);
	test_sort_result(v, n);
	printf("\n");
}
#define TEST_REGU_SORT(n, fun)  		do{printf(""#fun"(). ");regu_sort(n, fun);}while(0)
void test_regu()
{
	int n = REGU_TEST_TIME;

	TEST_REGU_SORT(n, mgsort);
	TEST_REGU_SORT(n, qksort);
	TEST_REGU_SORT(n, shsort);
	TEST_REGU_SORT(n, insort);
	TEST_REGU_SORT(n, bbsort);
	TEST_REGU_SORT(n, rdsort);
	TEST_REGU_SORT(n, hpsort);
}
int kmp_search(const char *txt, const char *pat);
void getlps(const char *, int *); /* 声明getlps() 函数 */
void Prntxt(const char *title, const char *str, const int *lps, int n);
/* 测试函数。*/
/* 输出函数。输出字符串 或 lps[]数组、或从0开始的一串数字 */
void Prntxt(const char *title, const char *str, const int *lps, int n)
{
	int i;
	int len;

	printf("%-12s:", title);
	/* str不为空则输出字符串，以下类似 */
	if (str != NULL)
	{
		len = strlen(str);
		for (i = 0; i < len; ++i)
			printf("%3c", str[i]);
	}
	else if (lps != NULL)
		for (i = 0; i < n; ++i)
			printf("%3d", lps[i]);
	else /* 输出一组从0开始到n的数字 */
	{
		for (i = 0; i < n; ++i)
			printf("%3d", i);
	}
	printf("\n");
}
/* 定义一个宏，计算字符串数组的长度。在c99中，可使用动态数组*/
#define LEN(a) ((int)(sizeof(a) / sizeof(*a) - 1))
void test_lps()
{
	int n = 5;
	int len[] = {4, 5, 11, 10, 7};
	char *pat[] = {"AAAA", "ABCDE", "AABAACAABAA", "AAACAAAAAC", "AAABAAA"};
	int result[5][20] = {{0, 1, 2, 3}, {0, 0, 0, 0, 0}, {0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5}, 
					{0, 1, 2, 0, 1, 2, 3, 3, 3, 4}, {0, 1, 2, 0, 1, 2, 3}};
	int lps[30];
	int i, j;

	for (i = 0; i < n; ++i)
	{
		getlps(pat[i], lps);
		for (j = 0; j < len[i]; ++j)
			if (lps[j] != result[i][j])
				printf("lps compute Error\n");
	}
	printf("lps compute OK\n");
}
void test_getlps()
{
	char pat[] = "abababca"; /*测试不同的字串，只修改此处即可*/
	int  lps[LEN(pat)];
	int  i, n = strlen(pat);

	getlps(pat, lps);
	printf("****** Test getlps(). LEN(pat): %d\n", LEN(pat));
	Prntxt("Index", NULL, NULL, n);
	Prntxt("String", pat, NULL, 0);
	Prntxt("lps[]", NULL, lps, n);
	
}
void test_kmp_search()
{
	/*测试不同的字串，只修改txt[]和pat[]即可*/
	char txt[] = "ABABCABAB"; 
	char pat[] = "ABABCABAB";
	int  lps[LEN(pat)];
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int i, r; 
	
	getlps(pat, lps);
	printf("****** Test kmp_search(). \n");
	Prntxt("Index", NULL, NULL, txt_len);
	Prntxt("Txt String", txt, NULL, 0);
	Prntxt("Pat String", pat, NULL, 0);
	Prntxt("lps[]", NULL, lps, pat_len);

	r = kmp_search(txt, pat);
	if (r == -1)
		printf("Don\'t match. \n");
	else
	{
		printf("kme_search() return: %3d\n", r);
		if (strncmp(&txt[r], pat, pat_len) == 0)
			printf("Search result OK\n");
		else
			printf("Search result Error\n");
	}
}
void test_kmp_search2()
{
	/*测试不同的字串，只修改txt[]和pat[]即可*/
	char txt[] = "ABABDABACDABABCABAB"; 
	char pat[] = "ABABCABAB";
	int  lps[LEN(pat)];
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int i, r; 
	
	getlps(pat, lps);
	printf("****** Test kmp_search(). \n");
	Prntxt("Index", NULL, NULL, txt_len);
	Prntxt("Txt String", txt, NULL, 0);
	Prntxt("Pat String", pat, NULL, 0);
	Prntxt("lps[]", NULL, lps, pat_len);

	r = kmp_search(txt, pat);
	if (r == -1)
		printf("Don\'t match. \n");
	else
	{
		printf("kme_search() return: %3d\n", r);
		if (strncmp(&txt[r], pat, pat_len) == 0)
			printf("Search result OK\n");
		else
			printf("Search result Error\n");
	}
}
int main()
{
	test_regu();
	test_lps();
	test_getlps();
	test_kmp_search();
	test_kmp_search2();
	return 0;
}
