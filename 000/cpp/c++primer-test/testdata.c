/*
 output some inter to a test file
 */
#include <stdio.h>
#include <stdlib.h> //rand()
#include <ctype.h>  //isdigit()

int main(int argc, char *argv[])
{
	int i, count, val;
	FILE *fp;

	if (argc <= 3)
	{
		printf("Usage: count range filename.\n");
		return 1;
	}
	if (argc >= 4)
	{
		fp = fopen(argv[3], "w");
		if (fp == NULL)
		{
			printf("Can not open file: %s\n", argv[1]);
			return 2;
		}
	}
	else
		fp = stdout;
	count = atoi(argv[1]);
	val = atoi(argv[2]);
	for (i = 0; i < count; i++)
		fprintf(fp, "%5d%c ", rand() % (val + 1), (i % 10 == 9) ? '\n' : '\t');
	fclose(fp);
	printf("Out put 0~%3d count: %3d OK.\n", val, count);
	return 0;
}
