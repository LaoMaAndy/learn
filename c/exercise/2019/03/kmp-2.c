/* kmp.c */
#include <stdio.h>		// printf()
#include <stdlib.h>		// malloc(), exit()
#include <string.h>		// strlen(), strncmp()

/* 	kme_search()：
	使用kmp算法，搜索字符串txt中，模板串pat第一次出现的位置。 
	如果找到，则返回其位置；如果未找到，则返回-1
	按照C语言惯例，字符串起始处位置为0
	函数中，使用size_t描述字符串长度则更为严谨
	使用gcc 7.3.0编译通过
*/
void getNext(const char *, int *); /* 声明getNext() 函数 */
int kmp_search(const char *txt, const char *pat)
{
	/* strlen() 这样的函数不能写入循环体内，否则会导致O(n^2)的时间度 */
	int txt_len = strlen(txt);	
	int pat_len = strlen(pat);
	int t, p;
	int *next;

	/* 为next[]数组分配存储空间。
	在c99中，可以使用动态数组，从而省略这一步。*/
	next = (int *) malloc(pat_len * sizeof(int));
	if (next == NULL)
	{
		printf("malloc() return NULL\n");
		exit(1);
	}
	getNext(pat, next);
	t = p = 0;
	while (t < txt_len && p < pat_len)
	{
		if (txt[t] == pat[p]) /* 如果当前字符相同，则比较下一个字符 */
		{
			++p;
			++t;
		}
		/* 	出现”失配“时，若此时是pat的首字符，则转入txt串的下一个位置，
			否则使用next[]数组确定下一次比较的pat位置 */
		else if (p == 0)
			++t;
		else 
			p = next[p]; 
	}
	free(next);
	/* 如果已经比较到pat串尾，表示完成匹配，返回其位置 */
	if (p == pat_len)
		return t - p;
	return -1;
}
/* 计算模板字符串的next() 数组 */
void getNext(const char *pat, int *next)
{
	int pat_len = strlen(pat);
	int i, j;

	if (pat_len == 1) /* 长度为1的字串，可直接返回 */
	{
		next[0] = 0;
		return ;
	}
	i = 1;
	j = next[0] = next[1] = 0;
	while (i < pat_len - 1) /* 此处必需 -1 否则发成溢出 */
	{
		if (pat[i] == pat[j])
		{
			++j;
			next[i + 1] = j;
			++i;
		}
		else if (j == 0)
		{
			next[i + 1] = 0;
			++i;
		}
		else
			j = next[j];
	}
}
/* 测试函数。*/
/* 输出函数。输出字符串 或 next[]数组、或从0开始的一串数字 */
void Prntxt(const char *title, const char *str, const int *next, int n)
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
	else if (next != NULL)
		for (i = 0; i < n; ++i)
			printf("%3d", next[i]);
	else /* 输出一组从0开始到n的数字 */
		for (i = 0; i < n; ++i)
			printf("%3d", i);
	printf("\n");
}
/* 定义一个宏，计算字符串数组的长度。在c99中，可使用动态数组*/
#define LEN(a) ((int)(sizeof(a) / sizeof(*a) - 1))
void test_getNext()
{
	char pat[] = "abababca"; /*测试不同的字串，只修改此处即可*/
	int  next[LEN(pat)];
	int  i, n = strlen(pat);

	getNext(pat, next);
	printf("****** Test getNext(). LEN(pat): %d\n", LEN(pat));
	Prntxt("Index", NULL, NULL, n);
	Prntxt("String", pat, NULL, 0);
	Prntxt("next[]", NULL, next, n);
	
}
void test_kmp_search()
{
	/*测试不同的字串，只修改txt[]和pat[]即可*/
	char txt[] = "ABABDABACDABABCABAB"; 
	char pat[] = "ABABCABAB";
	int  next[LEN(pat)];
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int r; 
	
	getNext(pat, next);
	printf("****** Test kmp_search(). \n");
	Prntxt("Index", NULL, NULL, txt_len);
	Prntxt("Txt String", txt, NULL, 0);
	Prntxt("Pat String", pat, NULL, 0);
	Prntxt("next[]", NULL, next, pat_len);

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
	test_getNext();
	test_kmp_search();
	return 0;
}