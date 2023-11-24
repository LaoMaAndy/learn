/*
function: bit operate
位操作函数：
	bit_set() 设置: 设置第p位 至 p - n + 1位
	bit_clr() 清除
	bit_chk() 检测
	bit_get() 返回状态
	bit_prn() 打印

以下函数若修改为 模版函数(C++)，则有一定实用性
可存储，在需要时查阅
*/

#include <stdio.h>

unsigned bit_set(unsigned v, int p, int n)
{
	return v | (~(~0u << n) << (p - n + 1));
}
unsigned bit_clr(unsigned v, int p, int n)
{
	return v & ~(~(~0u << n) << (p - n + 1));
}
int bit_chk(unsigned v, int n)
{
	return (v & ~(1u << n)) == 0 ? 0 : 1;
}
unsigned bit_get(unsigned v, int p, int n)
{
	return (v >> (p + 1 - n)) & ~(~0u << n);
}
void bit_prn(unsigned v)
{
	unsigned m = ~(~0U >> 1);
	for (int n = 0; n < sizeof(v) * 8; ++n, m >>= 1)
	{
		printf("%c", (v & m) == 0 ? '0' : '1');
		printf("%s", (n % 8 == 7 ) ? "   " : " ");
	}
	printf("\n");
}

