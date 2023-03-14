/*
 * String functions: 11
 */

 int Strlen(const char *s)
 {
	const char *p = s;
	
	while (*p != '\0')
		p++;
	return p - s;
 }
 
 char *Strcpy(char *dest, const char *src)
 {
	char *d = dest;
	 
	while ((*d++ = *src++) != '\0')
		 ;
	return dest;
 }
 
 char *Strncpy(char *dest, const char *src, int n)
 {
	 char *d = dest;
	 
	 for ( ; n > 0; n--)
		if ((*d++ = *src++) == '\0')
			return dest;
	*d = '\0';
	return dest;
 }
 
 char *Strcat(char *dest, const char *src)
 {
	 char *d = dest;
	 
	 while (*d != '\0')
		 d++;
	 if ((*d++ = *src++) != '\0')
		 ;
	 return dest;
 }
 
 char *Strncat(char *dest, const char *src, int n)
 {
	 char *d = dest;
	 
	 while (*d != '\0')
		 d++;
	 for ( ; n > 0; n--)
		 if ((*d++ = *src++) == '\0')
			 return dest;
	 *d = '\0';
	 return dest;
 }
 
 char *Squeeze(char *dest, int chr)
 {
	 char *p = dest;
	 char *q = dest;
	 int c;
	 
	 while ((c = *p++) != '\0')
		 if (c != chr)
			 *q++ = c;
	 *q = '\0';
	 return dest;
 }
 
 char *Strstr(const char *dest, const char *sub)
 {
	 const char *d = dest;
	 int i;
	 
	 for ( ; *d != '\0'; d++)
		 if (*d == *sub)
		 {
			 for (i = 1; d[i] == sub[i] && d[i] != 0; i++)
				 ;
			 if (sub[i] == '\0')
				 return (char *) d;
		 }
	 return (char *) 0;
 }
 
 int Strindex(const char *dest, const char *sub)
 {
	 const char *p;
	 
	 p = Strstr(dest, sub);
	 if (p != (const char *) 0)
		 return p - dest;
	 else
		 return -1;
 }
 
 int Strcmp(const char *s, const char *t)
 {
	 for ( ; *s == *t; s++, t++)
		 if (*s == '\0')
			 return 0;
	 return *s - *t;
 }
 
 char *Trim(char *dest)
 {
	 char *d = dest;
	 int c;
	 
	 while (*d != '\0')
		 d++;
	while (--d >= dest)
		 if ((c = *d) != ' ' && c != '\t' && c != '\n')
			 break;
	 if (d == dest)
		*d = '\0';
	 else
		 *++d = '\0';
	 return dest;
 }
 
 char *Reverse(char *dest)
 {
	 char *p = dest, *q = dest;
	 int c;
	 
	 while (*p != '\0')
		 p++;
	 for (--p; p > q; p--, q++)
	 {
		 c = *p;
		 *p = *q;
		 *q = c;
	 }
	 return dest;
 }
 

/*
 * test these function
 */
#include <stdio.h>

void test_str(void)
{	
	char s[100] = "12345";
	char t[100] = "abcdefg";
	char r[100] = "ABCDEFGHI";

	printf("String s: %s\n", s);
	printf("%d\n", Strlen(s));
	printf("Strcpy:  %s\n", Strcpy(s, t));
	printf("Strncpy: %s\n", Strncpy(s, t, 100));
	printf("Strcat:  %s\n", Strcat(s, r));
	printf("Strncat: %s\n", Strncat(s, r, 2));
	printf("Squeeze: %s\n", Squeeze(s, 'a'));

	char d[100] = "12abc1234567890abc1234abca";
	char e[100] = "abc";
	char *p;
	int n;
	int l;
	l = Strlen(e);
	p = d;
	printf("dest string: %s\n", p);
	printf("sub string : %s\n", e);
	printf("Strindex: %d\n", Strindex(p, e));
	printf("Strstr: %s\n", p = Strstr(p, e));
	p += l;
	printf("String p: %s\n", p);
	printf("Strindex: %d\n", Strindex(p, e));
	printf("Strstr: %s\n", p = Strstr(p, e));
	p += l;
	printf("String p: %s\n", p);
	printf("Strindex: %d\n", Strindex(p, e));
	printf("Strstr: %s\n", p = Strstr(p, e));

	char f[100] = "Abde    ";
	char g[100] = " ";
	printf("sizeof f is      : %d\n", Strlen(f));
	printf("Sizeof Trim(f) is: %d\n", Strlen(Trim(f)));
	printf("string f is %s\n", f);
	printf("Trim of zero-size string size is: %d\n", Strlen(Trim(g)));
	printf("Sizeof zero-size string is: %d\n", Strlen(""));

	char h[100] = "1234567";
	printf("string h is: %s\n", h);
	printf("Revers h is: %s\n", Reverse(h));
}

/*
 * Main fucntion
 */

int main(int argc, char *argv[])
{
	test_str();

	return 0;
}

 
 
