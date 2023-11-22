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

//important:
//stack 
void Push(double f);
double Pop(void);

//Buffer I/O
int Getch(void);
void Ungetch(int c);
int Getint(int *pn);
void Printd(int n);
// Command-line arguments

// C language
int Gettoken(void);

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


