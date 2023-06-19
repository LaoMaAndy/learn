#include "0prn.h"
#include "kstring.h"

void test_0(void)
{
	char s[] = "1234567890abcdefg\0'";

	Strinfo(s, 18);
}
void test_1(void)
{
	char s[] = "1234";
	char c[] = "1234";
	char t[200] = "\0aaaaaaaa\0aaaaaaa";
	//Strcpy(t, s);
	//Strncpy(t, c, 6);
	//Strxcpy(t, c, 10);
	//strcat(t, c);
	//Strncat(t, c, 5);
	//Strxcat(t, 0, c, 4);
	//Strinfo(t, 32);
	char cmp[][20] = {"t", "", "this", "thisabcde", "that", "thit", "thi", "thija", "this", "", "u", "t"};
	int i;
	for (i = 0; i < sizeof(cmp) / sizeof(*cmp); ++i)
		printf("Strxcmp. %4d: %s -- %s\n", Strxcmp(cmp[0], 4, cmp[i], 5), cmp[0], cmp[i]);
	printf("test Strstr...\n");
	char strstr[] = "goo hello google, tell me about my day goog";
	char sub[] = "goo";
	char *str_p = strstr;
	printf("\tThe dest string: %s\n", strstr);
	printf("\tSearch string: %s\n", sub);
	printf("\t\t strindex: %ld\n", Strindex(str_p, sub));
	printf("\t\t 1: %s\n", str_p = Strstr(str_p, sub));
	str_p += Strlen(sub);
	printf("\t\t strindex: %ld\n", Strindex(str_p, sub));
	printf("\t\t 2: %s\n", str_p = Strstr(str_p, sub));
	str_p += Strlen(sub);
	printf("\t\t strindex: %ld\n", Strindex(str_p, sub));
	printf("\t\t 3: %s\n", str_p = Strstr(str_p, sub));
	str_p += Strlen(sub);
	printf("\t\t strindex: %ld\n", Strindex(str_p, sub));
	printf("\t\t 4: %s\n", str_p = Strstr(str_p, sub));
	size_t ds = Strlen(strstr);
	size_t ss = Strlen(sub);
	str_p = strstr;
	printf("\tThe dest string: %s\n", strstr);
	printf("\tSearch string: %s\n", sub);
	printf("\t\t Strxindex: %ld\n", Strxindex(str_p, ds, sub, ss));
	printf("\t\t 1: %s\n", str_p = Strxstr(str_p, ds, sub, ss));
	str_p += Strlen(sub);
	ds -= Strlen(sub);
	printf("\t\t Strxindex: %ld\n", Strxindex(str_p, ds, sub, ss));
	printf("\t\t 2: %s\n", str_p = Strxstr(str_p, ds, sub, ss));
	str_p += Strlen(sub);
	ds -= Strlen(sub);
	printf("\t\t Strxindex: %ld\n", Strxindex(str_p, ds, sub, ss));
	printf("\t\t 3: %s\n", str_p = Strxstr(str_p, ds, sub, ss));
	str_p += Strlen(sub);
	ds -= Strlen(sub);
	printf("\t\t Strxindex: %ld\n", Strxindex(str_p, ds, sub, ss));
	printf("\t\t 4: %s\n", str_p = Strxstr(str_p, ds, sub, ss));
}

void test_2(void)
{
	char s[] = "0123456789";
	int i;

	for (i = 0; i < 10; ++i)
		printf("%s\n", Strchr(s, i + '0'));	
	for (i = 9; i >= 0; --i)
		printf("%s\n", Strrchr(s, i + '0'));	
	printf("Search 0: %s\n", Strchr(s, '0'));
	for (i = 0; i < 10; ++i)
		printf("%s\n", Strxchr(s, 10, i + '0'));
	for (i = 9; i >= 0; --i)
		printf("%s\n", Strxrchr(s, 10, i + '0'));	
}
void test_str(void)
{	
	char s[100] = "12345";
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

	char f[100] = "Abde    ";
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
	PRN_STR(---- My strpbrk-----);
	PRN_FUN(Strpbrk(i, m), s);
	PRN_STR(-----C Lib strpbrk-------);
	PRN_FUN(strpbrk(i, m), s);
	PRN_STR(---- My strpbrk-----);
	PRN_FUN(Strpbrk(i, n), s);
	PRN_STR(-----C Lib strpbrk-------);
	PRN_FUN(strpbrk(i, n), s);

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

void test_strtolow(void)
{
	char i[] = "THI FJKSLD:J";
	printf("%s\n", Strtolow(i));
}
int main(void)
{
	test_0();
	test_1();
	test_2();
	test_str();
	test_strtolow();

	return 0;
}
