// hw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"

int main(int argc, char* argv[])
{
	long int i;
	printf("Hello World!\n");
	printf("中文输入是否可以\n");
	getch();

	for(i=0; i<=100000; i++)putch('K');

	printf("\nLoops is over,press any key to exit\n");
	getch();
	return 0;
}

