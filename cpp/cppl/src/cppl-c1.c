/*
 ============================================================================
 Name        : cppl-c1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void word_per_line(void)
{
	int c, state ;

	state = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state == 1)
			{
				putchar('\n');
				state = 0;
			}
		}
		else
		{
			putchar(c);
			state = 1;
		}
	}
}

int main(void) {
	word_per_line();
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
