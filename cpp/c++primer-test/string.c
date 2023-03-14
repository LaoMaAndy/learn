#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define NEED_STRING
#include "0head.c"
#define TEST(a, b) printf("[function] "#a"\n");time_def(a,b)

void time_def(void(*fun)(void), int t)
{
	time_t before, after;
	double elap;

	before = clock();
	for (long i = t * 10000; t != 0; t--)
		fun();
	after = clock();
	elap = (after - before) / CLOCKS_PER_SEC;
	printf("Time: %3.3f\n", elap);
}


void str_clib(void)
{
	char s1[200] = "abcdefghijklmnopqrst";
	char s2[200] = "12345678901234567890";

	for (long i = 0; i < 12345678; i++)
	{
		strlen(s1);
		strchr(s1, 't');
		strcpy(s2, s1);
		strcmp(s1, s2);
		strcat(s2, s1);
	}
}

void str_mine(void)
{
	char s1[200] = "abcdefghijklmnopqrst";
	char s2[200] = "12345678901234567890";

	for (long i = 0; i < 12345678; i++)
	{
		Strlen(s1);
		Strchr(s1, 't');
		Strcpy(s2, s1);
		Strcmp(s1, s2);
		Strcat(s2, s1);
	}
}

int main(void)
{
	TEST(str_clib, 12);
	TEST(str_mine, 12);

	return 0;
}

