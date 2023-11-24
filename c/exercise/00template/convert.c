/* convert.c */
#include "head.h"

/* 
几个类型转换的算法：
	Atoi() 字符串转换为整数
	Atof() 字符串转换为浮点数
	Itoa() 整数转换为字符串
	fact() 求阶乘的递归算法
	prnstr() 打印字符串的递归算法
	prnint() 打印整数的递归算法
*/
int Atoi(const char *s)
{
	int sign, val;

	while (Isspace(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		++s;
	for (val = 0; Isdigit(*s); ++s)
		val = 10 * val + (*s - '0');
	return sign * val;
}

double Atof(const char *s)
{
	double val, sign , power;

	while (Isspace(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		++s;
	for (val = 0.0; Isdigit(*s); ++s)
		val = 10.0 * val + (*s - '0');
	if (*s == '.')
		++s;
	for (power = 1.0; Isdigit(*s); ++s)
	{
		val = 10.0 * val + (*s - '0');
		power *= 10.0;
	}
	return sign * val / power;
}
char *Itoa(int n, char *s)
{
	int sign;
	char *p = s;

	if ((sign = n) < 0)
		n = -n;
	do
		*s++ = n % 10 + '0';
	while ((n /= 10) > 0);
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	return Strrev(p);
}
int fact(int n)
{
	if (n <= 1)
		return 1;
	return n * fact(n - 1);
}
void prnstr(const char *s)
{
	if (*s == '\0')
		return ;
	printf("%c", *s);
	prnstr(s + 1);
}
void prnint(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n > 10)
		prnint(n / 10)
	putchar(n % 10 + '0');
}