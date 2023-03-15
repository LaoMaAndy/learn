#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define NEED_STRING
#include "0head.c"
#include "lib-str.c"

#define IN_LOOP (12345678L)
#define TIME_LOOP (1L)
#define STR_A "abcdefghijklmnopqrst"
#define STR_B "12345678901234567890"
#define TEST(func, times) printf("[function] "#func"\n");time_def(func, times) 

void time_def(void(*fun)(void), int t)
{
	time_t before, after;
	double elap;

	before = clock();
	for (long i = t * TIME_LOOP; i != 0; i--)
		fun();
	after = clock();
	elap = (after - before) / (CLOCKS_PER_SEC / 10);
	printf("Time: %4.1f\n", elap);
}

char cs1[2 * (sizeof(STR_A) + sizeof(STR_B))] = STR_A;
char cs2[2 * (sizeof(STR_A) + sizeof(STR_B))] = STR_B;
char cs3[2 * (sizeof(STR_A) + sizeof(STR_B))] = "";
void str_mine(void)
{
	for (long i = 0; i < IN_LOOP; i++)
	{
		int n = Strlen(cs1);
		char *p = Strchr(cs1, 't');
		Strcpy(cs2, cs1);
		Strcat(cs2, cs1);
		int c = Strcmp(cs1, cs2);
	}
}
void str_c(void)
{
	for (long i = 0; i < IN_LOOP; i++)
	{
		int n = strlen(cs1);
		char *p = strchr(cs1, 't');
		strcpy(cs2, cs1);
		strcat(cs2, cs1);
		int c = strcmp(cs1, cs2);
	}
}

void str_clib(void)
{
	for (long i = 0; i < IN_LOOP; i++)
	{
		int n = STRlen(cs1);
		char *p = STRchr(cs1, 't');
		STRcpy(cs2, cs1);
		STRcat(cs2, cs1);
		int c = STRcmp(cs1, cs2);
	}
}

string ps1(STR_A);
string ps2(STR_B);
string ps3("");
void str_cpp()
{
	for (long i = 0; i < IN_LOOP; i++)
	{
		int n = ps1.size(); 	
		ps1.find('t');
		ps1 = ps2;
		ps1 + ps2;
		int c = (ps1 == ps2);
	}
}


int main(void)
{
	TEST(str_c, 10);
	TEST(str_clib, 10);
	TEST(str_cpp, 10);
	TEST(str_mine, 10);
	return 0;
}

