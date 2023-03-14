#include <stdio.h>
//
// Chapter 3: Exercise
// 
// Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside the loop and measure the difference in run-time.
//

int my_binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x != v[mid])
			x < v[mid] ? (high = mid - 1) : (low = mid + 1);
		else
			return mid;
	}	
	return -1;
}

void test_my_binsearch(void)
{
	int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	printf("search 1 is %d\n", my_binsearch(1, v, 14));
	printf("search 6 is %d\n", my_binsearch(6, v, 14));
	printf("search 10 is %d\n", my_binsearch(10, v, 14));
	printf("search 14 is %d\n", my_binsearch(14, v, 14));
	printf("search 20 is %d\n", my_binsearch(20, v, 14));
}
//
// Exercise 3-2. Write a function escape(s, t) that converts characters like newline and tab into visible excape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
//
char *escape(char *s, char *t)
{
	char *p = t;

	while (*s != '\0')
	{
		switch (*s)
		{
			case '\t':
				*t++ = '\\';
				*t = 't';
				break;
			case '\n':
				*t++ = '\\';
				*t = 'n';
				break;
			default:
				*t = *s;
				break;
		}
		++t;
		++s;
	}
	*t = '\0';
	return p;
}

char *de_escape(char *s, char *t)
{
	char *p = t;
	while (*s != '\0')
	{
		switch (*s)
		{
			case '\\':
				switch (*(s + 1))
				{
					case 't':
						*t = '\t';
						++s;
						break;
					case 'n':
						*t = '\n';
						++s;
						break;
					default:
						*t = '\\';
						break;
				}
				break;
			default :
				*t = *s;
		}
		++t;
		++s;
	}
	return p;
}

#define BUF_SIZE 1024

void test_escape(void)
{
	char buf[BUF_SIZE + 1], buf2[BUF_SIZE + 1];
	int i, c;

	for (i = 0; i < BUF_SIZE && ((c = getchar()) != EOF); ++i)
		buf[i] = c;
	buf[i] = '\0';

	printf("escape: \n%s\n", escape(buf, buf2));
	printf("de_escape: \n%s\n", de_escape(buf2, buf));
}
//
// Exercise 3-3. Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is is taken literally.
//
#include <ctype.h>
void expand(char s[], char t[])
{
	//描述：
	//	判断源字符是否为 '-'
	//	查看左字符，右字符，是否同属于a~z, A~Z, 0~9
	//	如果是，则，展开这些字符，将a~z转化为a...z，
	//	写入目标数组
	//	调整源数组
	//	判断源数组是否为结尾字符

	int i = 1, j = 1, step;
	char c;
	
	if ((t[0] = s[0]) == '\0')
		return;
	
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			if ((islower(s[i - 1]) && islower(s[i + 1]))  ||
		 		(isupper(s[i - 1]) && isupper(s[i + 1]))  ||
				(isdigit(s[i - 1]) && isdigit(s[i + 1])))
			{
				step = (s[i - 1] < s[i + 1]) ? 1 : -1;
				for (c = s[i - 1] + step; c != s[i + 1]; c += step)
				{
					t[j] = c;
					j++;
				}
				i++;
			}
		}
		t[j++] = s[i++];
	}
	t[j] = '\0';
}

#undef BUFFER_SIZE
#define BUFFER_SIZE 1024
void test_expand(void)
{
	char s[] = "2-7,A-a,3-b,a-z0-9,-a-z,a-b-c,-w";
	char t[BUFFER_SIZE];
	
	expand(s, t);
	printf("Before expand: %s\n", s);
	printf("After  expand: %s\n", t);
}
//
// Exercise 3-4. In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2^wordsize-1). Explain why not. Modify it to pring that value correctly, regardless of the machine on which it runs.
//
int my_strlen(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}

void test_my_strlen(void)
{
	char s[] = "a";
	printf("String: %s, length is: %d \n", s, my_strlen(s));
}

void my_reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = my_strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void my_itoa(int n, char s[])
{
	//描述
	//	首先判断是否为负数
	//	如果为负数，则需要处理最大负数的情况
	//	补码：减一求反。负1：全F，负最大：1全零 
	//	负数转正数：求反加1。
	//	如果为正数，则利用除10取余数的方法计算
	//	办法：将负数转化为绝对值相等的正数，再处理
	unsigned abs;
	int i = 0, neg = 0;
	
	if (n < 0)
	{
		neg = 1;
		abs = ~(unsigned)n + 1;
	}
	else 
		abs = (unsigned)n;
	
	do
	{
		s[i++] = abs % 10 + '0';
	} while ((abs /= 10) > 0);
	
	if (neg)
		s[i++] = '-';
	s[i] = '\0';

	my_reverse(s);
}

void my_itoa_v2(int n, char s[])
{
	//描述
	//	将所有的数字作为负数处理
	//	首先将正数转化为负数
	//	判断余数的正负，然后对商进行调整
	//	通常负数的余数为负，商则必定为负
	int i, r, sig;
	
	if (n >= 0)
	{
		sig = 1;
		n = -n;
	}
	else 
		sig = 0;

	i = 0;
	do 
	{
		r = n % 10;
		n = n / 10;
		if (r > 0)
		{
			r -= 10;
			n += 1;
		}
		s[i++] = "0123456789"[-r];
	}while (n < 0);

	if (!sig)
		s[i++] = '-';
	s[i] = '\0';

	my_reverse(s);
}

void test_my_itoa(void)
{
	char s[100];
	int n0 = 0;
	int n = ~(~(unsigned)0 >> 1);
	int n1 = ~(unsigned)0 >> 1;
	
	my_itoa_v2(n0, s);
	printf("number1 : %d\n", n0);
	printf("string1 : %s\n", s);

	my_itoa_v2(n, s);
	printf("number1 : %d\n", n);
	printf("string1 : %s\n", s);

	my_itoa_v2(n1, s);
	printf("number2 : %d\n", n1);
	printf("string2 : %s\n", s);
}

//
// Exercise 3-5. Write the function itob(n, s, b) that converts the integer n into a base b character representation in the string s. In particular, itob(n, s, 16) formats n as a hexadecimal integer in s.
//
void itob(int n, char s[], int b)
{
	int i = 0, r, sig;

	if (b < 2 || b > 16)
		return ;

	if (n >= 0)
	{
		sig = 1;
		n = -n;
	}
	else
		sig = 0;
	
	do 
	{
		r = n % b;
		n /= b;
		if (r > 0)
		{
			r += b;
			n -= 1;
		}
		s[i++] = "0123456789ABCDEF"[-r];
	} while (n < 0);
	
	if (!sig)
		s[i++] = '-';
	s[i] = '\0';

	my_reverse(s);
}

void test_itob(void)
{
	char s[100];
	int n[] = {0, ~(~(unsigned)0 >> 1), 12345678, ~(unsigned)0 >> 1};
	int b, j;
	
	for (b = 4; b < 17; b += 4)
	{
		printf("Base : %d\n", b);
		for (j = 0; j < 4; j++)
		{

			itob(n[j], s, b);
			printf("number1 : %d\n", n[j]);
			printf("string1 : %s\n", s);
		}
	}
}
//
// Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.
//
void itoa_pad(int n, char s[], int p)
{
	int i, r, sig;

	if (n >= 0)
	{
		sig = 1;
		n = -n;
	}
	else
		sig = 0;
		
	i = 0;
	do 
	{
		r = n % 10;
		n /= 10;
		if (r > 0)
		{
			r -= 10;
			n += 1;
		}
		s[i++] = "0123456789"[-r];
	}while (n < 0);
	
	if (!sig)
		s[i++] = '-';
		
	for ( ; i < p; i++)
		s[i] = ' ';

	s[i] = '\0';

	my_reverse(s);
}

void test_itoa_pad(void)
{
	char s[100];
	int n[] = {0, ~(~(unsigned)0 >> 1), 12345678, ~(unsigned)0 >> 1};
	int p, j;
	
	for (p = 10; p < 17; p += 2)
	{
		printf("Pad width : %d\n", p);
		for (j = 0; j < 4; j++)
		{
			itoa_pad(n[j], s, p);
			printf("number1 : %d\n", n[j]);
			printf("string1 : %s\n", s);
		}
	}
}

#define TEST(func) printf("Testing function "#func":\n");func()
int main(void)
{
	TEST(test_itoa_pad);
	//TEST(test_itob);
	//TEST(test_my_itoa);
	//TEST(test_my_strlen);
	//TEST(test_expand);
	//TEST(test_escape);
	//TEST(test_my_binsearch);
	return 0;
}







