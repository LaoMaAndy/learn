/*
temp0818.c	: 
temp0818-2.c	:	
temp0818-3.c	:三种排序算法，比较完整的构架
temp08260-2.c	:四个str函数

*/

/* sort */
void quicksort(int v[], int left, int right);
void qksort(int v[], int n);
void shsort(int v[], int n);
void bbsort(int v[], int n);
void swap(int v[], int i, int j);
int Binsearch(int x, int v[], int n);

/* String 11 */
int Strlen(const char *s);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, int n); 
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, int n); 
char *Squeeze(char *dest, int chr);
int Strcmp(const char *s1, const char *s2);
char *Strstr(const char *dest, const char *sub);
int Strindex(const char *dest, const char *sub);
char *Trim(char *s);
char *Reverse(char *s);


// Data transform
int Upper(int c);
int Lower(int c);
int Atoi(const char *s);
double Atof(const char *s);
char *Itoa(int n, char *s);

//bit operate:ws:w
unsigned Getbits(unsigned x, int p, int n);

//shell command
void Wordcount(void);

//IO function
int Getline(char *s, int lim);

//Buffer I/O
int Getch(void);
void Ungetch(int c);
int Getint(int *pn);
// Command-line arguments

// C language
int Gettoken(void);

//important:
//stack 
#include <stdlib.h>
#define STKD int
typedef struct stk_info
{
	STKD *top, *base;
	int size;
} stk;
stk *stkinit(int n);
int stkresize(stk *s, int n);
int stkpush(stk *s, STKD d);
int stkpop(stk *s, STKD *dp);
int stkgetop(stk *s, STKD *dp);
int stkgetn(stk *s, STKD *dp, int n);
void stkfree(stk *s);
void stkreset(stk *s);
void stkreset(stk *s);
int stkcount(stk *s);
int stkmax(stk *s);

// tree

// table

#include <stdio.h>
/* define PRN_... 6 */
#define PRN_VAL(val, type) 	printf("(variable) "#val":\t%"#type"\n", val)
#define PRN_FUN(fun, type) 	printf("(function) "#fun":\t%"#type"\n", fun)
#define PRN_CAL(fun)		printf("(function) "#fun"\n");fun
#define PRN_SEN(sen)		printf("(sentence) "#sen";\n");sen
#define PRN_STR(str)		printf(#str"\n")
#define PRN_PRN			printf


