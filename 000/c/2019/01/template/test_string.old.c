/*
function: string
*/
#include "head.h"

void test_trim()
{
	char s[][30] = {
		"         ab", 
		"cd        ", 
		"   1  2  3  4   ", 
		"         ", 
		""} ;
	size_t k[sizeof(s) / sizeof(s[0])];
	int i, n;
	n = sizeof(s) / sizeof(s[0]);

	printf("=====Test Strtrim========\n");
	for (i = 0; i < n; ++i)
	{
		printf("String: %s\n", s[i]);
		k[i] = Strlen(Strtrim(s[i]));
		printf("Trim: %5ld :%s\n", k[i], s[i]);
	}
	if (k[0] == 2 && k[1] == 2 && k[2] == 10 && k[3] == 0 && k[4] == 0)
		printf("Strtrim OK\n");
	else
		printf("Strtrim Error\n");
}
void test_str(void)
{	
	char s[100] = "1234567";
	char t[100] = "abcdefg";
	char r[100] = "ABCDEFGHI"; 
	PRN_VAL(s, s);
	PRN_VAL(t, s);
	PRN_VAL(r, s);
	PRN_FUN(Strlen(s), lu);
	PRN_FUN(Strcpy(s, t), s);
	PRN_FUN(Strncpy(s, t, 3), s);
	PRN_FUN(Strcat(s, t), s);
	PRN_FUN(Strncat(s, r, 2), s);
	PRN_FUN(Strsqz(s, 'a'), s);

	char d[100] = "12abc1234567890abc1234abca";
	char e[100] = "abc";
	char *p = d;
	size_t l;
	PRN_STR(----------);
	PRN_VAL(d, s);
	PRN_VAL(e, s);
	PRN_FUN(l = Strlen(e), lu);
	PRN_FUN(Strindex(p, e), lu);
	PRN_FUN(p = Strstr(p, e), s);
	PRN_SEN(p += l);
	PRN_VAL(p, s);
	PRN_FUN(Strindex(p, e), lu);
	PRN_FUN(p = Strstr(p, e), s);
	PRN_SEN(p += l);
	PRN_VAL(p, s);
	PRN_FUN(Strindex(p, e), lu);
	PRN_FUN(p = Strstr(p, e), s);

	char f[100] = "   Abde    ";
	char g[100] = " "; 
	PRN_STR(--------);
	PRN_VAL(f, s);
	PRN_VAL(g, s);
	PRN_FUN(Strlen(f), lu);
	PRN_FUN(Strlen(Strtrim(f)), lu);
	PRN_VAL(f, s);
	PRN_FUN(Strlen(Strtrim(g)), lu);
	PRN_FUN(Strlen(""), lu);

	char h[100] = "1234567";
	PRN_STR(-------);
	PRN_VAL(h, s);
	PRN_FUN(Strrev(h), s);
	PRN_PRN("test micro PRN_PRN. variable h's value is :%s\n", h);

	char a[100] = "AbCdEfGhIjK012#^";
	PRN_STR(-----------);
	PRN_VAR(a, s);
	PRN_FUN(Strtoup(a), s);
	PRN_FUN(Strtolow(a), s);
	PRN_FUN(Strdup(a), s);

	char i[100] = "12340eabcdefg5678eabcdefghi123e re12";
	PRN_VAR(i, s);
	PRN_FUN(Strchr(i, 'e'), s);
	PRN_FUN(Strrchr(i, 'e'), s);
	char m[100] = "1234567890";
	char n[100] = "abcdefg";
	PRN_VAR(i, s);
	PRN_VAL(m, s);
	PRN_VAL(n, s);
	PRN_FUN(Strspn(i, m), lu);
	PRN_FUN(Strcspn(i, n), lu);
	printf("here is OK\n");
	PRN_FUN(Strpbrk(i, m), s);
	PRN_FUN(Strpbrk(i, n), s);

	char as[] = "1234567";
	char bs[] = "abcde";
	char cs[] = "1234567";
	PRN_VAL(as, s);
	PRN_VAL(bs, s);
	PRN_VAL(cs, s);
	PRN_FUN(Strspn(as, bs), lu);
	PRN_FUN(Strspn(as, cs), lu);
	PRN_FUN(Strcspn(as, bs), lu);
}

/*
 * Main fucntion
 */

int main(int argc, char *argv[])
{
	test_str();

	return 0;
}




