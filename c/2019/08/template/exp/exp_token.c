/* get a token from a string */
#include "template/head.h"

struct str_stream
{
	unsigned char *ptr;
	unsigned char *base;
};
typedef struct str_stream token;

int op_valid(const char *s);
int Token(char *buf, int bsize, token *s);
token *Intok(const char *s);
static int Get(token *t);
static int Cur(token *t);
static void Unget(token *t);

token *Intok(const char *s)
{
	token *t;

	t = (token *) malloc(sizeof(*t));
	if (t == NULL || (t->ptr = t->base = Strdup(s)) == NULL)
		return NULL;
	Strsqzs(t->ptr, "\t \n");
	return t;
}
static int Get(token *t)
{
	int c = *t->ptr;
	if (c == '\0')
		return EOF;
	++t->ptr;
	return c;
}
static void Unget(token *t)
{
	if (t->ptr > t->base)
		--t->ptr;
}
static int Cur(token *t)
{
	int c = *t->ptr;
	return (c == '\0') ? EOF : c;
}
/* 
	获取一个token， 其分类为:数字，单词，运算符，
	分别定义如下：
	数字：以数字开头，可以有小数点。
	单词：由字母开头，由字母、下划线、数字构成
	运算符：用op_valid()判断，尽可能取最长的运算符

	返回值：0为无法识别字符， 1为数字，2为运算符， 3为单词, EOF为结束, 
*/
int Token(char *buf, int size, token *t)
{
	int c;
	char *p = buf;
	
	c = Cur(t);
	if (c == EOF)
		return EOF;
	// printf("----------------\n");
	// printf("Begin :%s\n", t->ptr);
	if (Isdigit(c)) 				// number
	{
		for ( ; --size > 0 && Isdigit(c = Get(t)); ++buf)
			*buf = c;
		if (c != '.')
		{
			*buf = '\0';
			if (c != EOF)
				Unget(t);
			// printf("Remain:%s\n", t->ptr);
			return 1;
		}
		*buf++ = c;
		for ( ; --size > 0 && Isdigit(c = Get(t)); ++buf)
			*buf = c;
		*buf = '\0';
		if (c != EOF)
			Unget(t);
		// printf("Remain:%s\n", t->ptr);
		return 1;
	}
	else if (Isalpha(c) || c == '_')	// word
	{
		for ( ; --size > 0 && (Isalnum(c = Get(t)) || c == '_'); ++buf)
			*buf = c;
		*buf = '\0';
		if (c != EOF)
			Unget(t);
		// printf("Remain:%s\n", t->ptr);
		return 3;
	}
	else
	{
		*buf = Get(t);
		*(buf + 1) = '\0';
		// printf("--->Current op[1]: %s, Strlen(p): %ld\n", p, Strlen(p));
		if (!op_valid(buf))			// not a valid operator
		{
			*buf = '\0';
			return 0;
		}
		for (p = buf++; --size > 1 && (c = Get(t)) != EOF; ++buf)  // read next 
		{
			*buf = c;
			*(buf + 1) = '\0';
			// printf("--->Current op[2]: %s, Strlen(p): %ld\n", p, Strlen(p));
			if (!op_valid(p))
				break;
		}
		*buf = '\0';
		if (c != EOF)
			Unget(t);
		// printf("Remain:%s\n", t->ptr);
		return 2;	
	}
	*buf = '\0';
	return EOF;
}

void test_gettok()
{
	char tok[] = "123.0 + 234 * 432 / 123-- + 321";
	token *t;
	char buf[200];
	int size = sizeof(buf);
	int i, j = 0;

	t = Intok(tok);
	printf("%s\n", t->base);
	if (t == NULL)
	{
		printf("empty token\n");
		return ;
	}
	while((i = Token(buf, size, t)) != EOF)
	{
		printf("Rvalue: %d, %s\n", i, buf);
		if (j++ >= 20)
			break;
	}
}
int main_tiken()
{
	test_gettok();
	return 0;
}
