#include "head.h"

void print_nstr(const char *s, size_t n)
{
	for ( ; n != 0; --n)
	{
		if (*s == '\0')
			printf("\\0");
		else
			printf("%c", *s);
		++s;
	}
}
void print_str(const char *s)
{
	size_t i;
	char c;

	for (i = 0; (c = s[i]) != '\0'; ++i)
		if (Isspace(c))
			printf(".");
		else
			printf("%c", c);
	printf("\\0");
}
void print_str_l(const char *s, size_t n)
{
	size_t i;

	for (i = 0; i < n && s[i] != '\0'; ++i)
			printf("%c", s[i]);
	for ( ; i < n; ++i)
		printf(" ");
}
void test_len()
{
	
	char s[][30] = {
		"123456789\0zzzzzzzz", 
		" a\0zzzzzzzz", 
		"a \0zzzzzzzz", 
		"  \0zzzzzzzz",
		"\0zzzzzzzz"
		} ;
	size_t k[sizeof(s) / sizeof(s[0])];
	int i, n;
	n = sizeof(s) / sizeof(s[0]);

	printf("=====Test Strlen()========\n");
	for (i = 0; i < n; ++i)
	{
		k[i] = Strlen(s[i]);
		printf("Strlen: %3ld, String:", k[i]);
		print_str(s[i]);
		printf("\n");
	}
	if (k[0] == 9 && k[1] == 2 && k[2] == 2 && k[3] == 2 && k[4] == 0)
		printf("Strlen() OK\n");
	else
		printf("Strlen() Error\n");
}

void test_cpy()
{
	char s[][30] = {
		"abcde\0zzzzzzzz", 
		"abcdf\0zzzzzzzz", 
		"a\0zzzzzzzz", 
		"abcde \0zzzzzzzz",
		"  \0zzzzzzzz",
		"ba\0zzzzzzzz",
		"\0zzzzzzzz"
		} ;
	char d[sizeof(s) / sizeof(s[0])][30];
	int i, n, ok = 1;
	n = sizeof(s) / sizeof(s[0]);

	printf("=====Test Strcpy()========\n");
	for (i = 0; i < n; ++i)
	{
		Strcpy(d[i], s[i]);
		printf("String[%d]:", i);
		print_str(d[i]);
		printf("\n");
	}
	for (i = 0; i < n; ++i)
	{
		n = Strcmp(d[i], s[i]);
		if (n != 0)
			ok = 0;
	}
	if (!ok)
			printf(ERR_STR);
	else
		printf(OK_STR);
}
void test_ncpy()
{
	char t[100] = "abcdefghijklmnopqrstuvwxyz\0zzzzzzzz";
	char s[100] = "12345\0zzzzzzzz";

	printf("=====Test Strncpy()========\n");
	printf("string:%s\n", s);
	print_nstr(s, 7);
	printf("\n");
	printf("strncpy(t, s, 3):");
	Strncpy(t, s, 3);
	print_nstr(t, 30);
	printf("\n");
	printf("strncpy(t, s, 5):");
	Strncpy(t, s, 5);
	print_nstr(t, 30);
	printf("\n");
	printf("strncpy(t, s, 6):");
	Strncpy(t, s, 6);
	print_nstr(t, 30);
	printf("\n");
	printf("strncpy(t, s, 8):");
	Strncpy(t, s, 8);
	print_nstr(t, 30);
	printf("\n");
}
void test_cat()
{
	char a[20] = "12 3 4 5\0zzzzzzzz";
	char b[20] = "ab c d e\0zzzzzzzz";
	
	printf("=====Test Strcat()========\n");
	printf("a: %s\n", a);
	printf("b: %s\n", b);
	Strcat(a, b);
	printf("Strcat(a, b):");
	print_str(a);
	printf("\n");
}
void test_ncat()
{
	char s[][30] = {
		"12345\0zzzzzz", 
		"abcdf\0ffffff", 
		"a\0zzzzzz", 
		"abcde \0zzzzzz",
		"  \0zzzzz",
		"ba\0zzzzzz",
		"\0zzzzz"
		} ;
	size_t d[sizeof(s) / sizeof(s[0])];
	size_t s_len, j;
	int i, n, ok = 1;
	n = sizeof(s) / sizeof(s[0]);

	printf("=====Test Strncat()========\n");
	for (i = 0; i < n; ++i)
	{
		d[i] = Strlen(s[i]);
		printf("Strlen=%2ld:", d[i]);
		print_str(s[i]);
		printf("\n");
	}
	s_len = Strlen(s[0]);
	for (i = 1; i < n; ++i)
	{
		printf("Strncat(%2ld,%2ld,%2d):", Strlen(s[i]), Strlen(s[0]), 3 + i);
		print_str_l(s[i], 8);
		printf(" + ");
		print_str_l(s[0], 5);
		printf(" ==> ");
		Strncat(s[i], s[0], 3 + i);
		print_str_l(s[i], 13);
		printf(" (Strlen:%2ld)\n", Strlen(s[i]));
	}
	for (i = 1; i < n; ++i)
	{
		(3 + i) > s_len ? (j = s_len) : (j = 3 + i);
		if (d[i] + j != Strlen(s[i]))
			ok = 0;
	}
	if (!ok)
			printf(ERR_STR);
	else
		printf(OK_STR);

}
void test_cmp()
{
	char s[][30] = {
		"abcde\0zzzzzzzz", 
		"abcdf\0zzzzzzzz", 
		"a\0zzzzzzzz", 
		"abcde \0zzzzzzzz",
		"  \0zzzzzzzz",
		"ba\0zzzzzzzz",
		"\0zzzzzzzz"
		} ;
	int k[sizeof(s) / sizeof(s[0])];
	int r[sizeof(s) / sizeof(s[0])] = {0, -1, 98, -32, 65, -1, 97};
	int i, n;
	n = sizeof(s) / sizeof(s[0]);

	printf("=====Test Strcmp()========\n");
	for (i = 0; i < n; ++i)
	{
		k[i] = Strcmp(s[0], s[i]);
		printf("Strcmp(s, t): %3d, s:%s, t:", k[i], s[0]);
		print_str(s[i]);
		printf("\n");
	}
	for (i = 0; i < n; ++i)
		if (k[i] != r[i])
		{
			printf(ERR_STR);
			return;
		}
	printf(OK_STR);
}
void test_ncmp()
{
	char s[][30] = {
		"abcde\0zzzzzzzz", 
		"abcdf\0zzzzzzzz", 
		"a\0zzzzzzzz", 
		"abcde \0zzzzzzzz",
		"  \0zzzzzzzz",
		"ba\0zzzzzzzz",
		"\0zzzzzzzz"
		} ;
	int k[4][sizeof(s) / sizeof(s[0])];
	int r[4][sizeof(s) / sizeof(s[0])] ={
		{0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 65, -1, 97},
		{0, 0, 98, 0, 65, -1, 97},
		{0, 0, 98, 0, 65, -1, 97}
		};
	int i, n, j;
	n = sizeof(s) / sizeof(s[0]);

	printf("=====Test Strncmp()========\n");
	for (j = 0; j < 4; ++j)
	for (i = 0; i < n; ++i)
	{
		k[j][i] = Strncmp(s[0], s[i], (size_t) j);
		printf("Strncmp(s, t, %d): %3d, s:%s, t:", j, k[j][i], s[0]);
		print_str(s[i]);
		printf("\n");
	}
	for (j = 0; j < 4; ++j)
		for (i = 0; i < n; ++i)
			if (k[j][i] != r[j][i])
			{
				printf(ERR_STR);
				return;
			}
	printf(OK_STR);	
}
void test_str()
{
	char d[100] = "12abc1234567890abc1234abca\0zzzzzzzz";
	char e[100] = "abc\0zzzzzzzz";
	size_t e_len = Strlen(e);
	char *p = d;
	int ok = 1;
	int i;
	
	printf("=====Test Strstr()========\n");
	printf("dest:%s\nsub:%s\n", d, e);
	for (i = 0; i < 3; ++i)
	{
		p = Strstr(p, e);
		printf("%3d: Strstr(p, e):%s\n", i, p);
		if (Strncmp(p, e, e_len) != 0)
		   ok = 0;
		p += e_len;
	}
	if (ok == 0)
		printf(ERR_STR);
	else
		printf(OK_STR);
}
void test_index()
{
	char d[100] = "12abc1234567890abc1234abca\0zzzabczzzzz";
	char e[100] = "abc\0zzzabczzzzz";
	size_t e_len = Strlen(e);
	char *p = d;
	int ok = 1;
	int i;
	
	printf("=====Test Strindex()========\n");
	printf("dest:%s\nsub:%s\n", d, e);
	for (i = 0; i < 3; ++i)
	{
		p += Strindex(p, e);
		printf("%3d: Strindex(p, e):%s\n", i, p);
		if (Strncmp(p, e, e_len) != 0)
		   ok = 0;
		p += e_len;
	}
	if (ok == 0)
		printf(ERR_STR);
	else
		printf(OK_STR);
}
void test_chr()
{
	char d[100] = "1234567890abc1234abca\0zzzabczzzzz";
	char c[16] = "0987654321abcdef";
	char *p;
	int n = sizeof(c) / sizeof(c[0]);
	int i, r, ok = 1;

	printf("=====Test Strchr()========\n");
	p = Strchr(c, 'g');
	if (p == NULL)
		printf("p = NULL\n");
	printf("string: %s\n", d);
	for (i = 0; i < n; ++i)
	{
		p = Strchr(d, c[i]);
		if (p != NULL)
		{
			printf("c: %c, pos: %ld\n", c[i], p - d);
			if (*p != c[i])
				ok = 0;
		}
		else
		{
			printf("c: %c, pos: NULL\n", c[i]);
		}
	}
	p = Strchr(d, '$');
	if (p != NULL)
		ok = 0;
	if (ok == 0)
		printf(ERR_STR);
	else
		printf(OK_STR);
}
void test_rchr()
{
	char d[100] = "1234567890abc1234abca\0zzzabczzzzz";
	char c[10] = "0987654321";
	char *p;
	int n = sizeof(c) / sizeof(c[0]);
	int i, r, ok = 1;

	printf("=====Test Strrchr()========\n");
	
	printf("string: %s\n", d);
	for (i = 0; i < n; ++i)
	{
		p = Strrchr(d, c[i]);
		printf("c: %c, pos: %ld\n", c[i], p - d);
		if (*p != c[i])
			ok = 0;
	}
		if (ok == 0)
		printf(ERR_STR);
	else
		printf(OK_STR);
}
void test_spn2()
{
	char a[100] = "abc12";
	char b[20] = "12345678\n";
	size_t i;

	i = Strspn(a, b);
	printf("Test Strspn: %ld\n", i);
}
void test_spn()
{
	char d[100] = "1234567890abc1234abca\0zzzabczzzzz";
	char c[30] = "0987654321\0zzzzz";
	char *p;
	int n = Strlen(c);
	int i, ok = 1;
	size_t r;

	printf("=====Test Strspn()========\n");
	printf("string: %s\n", d);
	printf("Span:  ");
	for (i = 0; i < n + 3; ++i)
	{
		r = Strspn(d + i, c);
		printf("%4ld", r);
	}
	printf("\n");
}
void test_cspn()
{
	char d[100] = "1234567890abc1234abca\0zzzabczzzzz";
	char c[30] = "abcdefghij\0zzz";
	char *p;
	int n = Strlen(c);
	int i, ok = 1;
	size_t r;

	printf("=====Test Strcspn()========\n");
	printf("string: %s\n", d);
	printf("Cspan: ");
	for (i = 0; i < n + 3; ++i)
	{
		r = Strcspn(d + i, c);
		printf("%4ld", r);
	}
	printf("\n");
}
void test_pbrk()
{
	char c[100] = "z1aa2bbb3cccc4ddddd5eeeeee6ffffffff7ggggggggg8";
	char d[30] = "1234567890\0zzz";
	char *p = c;
	int i;

	printf("=====Test Strpbrk()========\n");
	printf("string: %s\n", c);
	printf("Find: ");
	for (i = 0; i < 8; ++i)
	{
		p = Strpbrk(p, d);
		printf("%3c", *p);
		++p;
	}
	printf("\n");
}
void test_rev()
{
	char c[100] = "1 2 3 4 5 6 7 8 9 0\0zzzzzz";
	int i;

	printf("=====Test Strrev()========\n");
	printf("string : %s\n", c);
	Strrev(c);
	printf("Reverse: %s\n", c);
}

void test_trim()
{
	char s[][50] = {
		"  \t\na b c d e  \0zzzzzzzz", 
		"   abcdf\0zzzzzzzz", 
		"a      \0zzzzzzzz", 
		"  abcde \0zzzzzzzz",
		"  \0zzzzzzzz",
		"ba\0zzzzzzzz",
		"\0zzzzzzzz"
		} ;
	char d[sizeof(s) / sizeof(s[0])][30];
	int i, n, ok = 1;
	n = sizeof(s) / sizeof(s[0]);

	printf("=====Test Strtrim()========\n");
	for (i = 0; i < n; ++i)
	{
		printf("String:");
		print_str(s[i]);
		printf("\n");
		printf("Trim  :");
		Strtrim(s[i]);
		print_str(s[i]);
		printf("\n");
		if (Isspace(s[i][0]) || Isspace(s[i][Strlen(s[i]) - 1]))
			ok = 0;
	}
	if (!ok)
			printf(ERR_STR);
	else
		printf(OK_STR);
}
void test_sqz()
{
	char c[100] = "g111g2gg22333ggg444g555g666g\0zzzz";
	printf("=====Test Strsqz()========\n");
	printf("String:%s\n", c);
	Strsqz(c, 'g');
	printf("Strsqz:%s\n", c);
}
void test_sqzs()
{
	char c[100] = "g111g2gg22333ggg444g555g666g\0zzzz";
	char d[20] = "1234567890\0zzz";
	printf("=====Test Strsqzs()========\n");
	printf("String:%s\n", c);
	Strsqzs(c, d);
	printf("Strsqz:%s\n", c);
}
void test_dup()
{
	char c[100] = "abcdefghijklmnopqrstuvwxyz\0zzzzz";
	char *d;

	d = Strdup(c);
	printf("=====Test Strdup()========\n");
	printf("Src :%s\n", c);
	printf("Dest:%s\n", d);
}

void test_to()
{
	char c[100] = "abcdefghijklmnopqrstuvwxyz\0zzzzz";

	printf("=====Test Strto()========\n");
	printf("String :%s\n", c);
	Strtoup(c);
	printf("Toupper:%s\n", c);
	Strtolow(c);
	printf("Tolower:%s\n", c);
}
int main()
{
	test_len();
	test_cpy();
	test_ncpy();
	test_cat();
	test_ncat();
	test_cmp();
	test_ncmp();
	test_str();
	test_index();
	test_chr();
	test_rchr();
	test_spn();
	test_cspn();
	test_pbrk();
	test_rev();
	test_trim();
	test_sqz();
	test_sqzs();
	test_dup();
	test_to();

	return 0;
}
