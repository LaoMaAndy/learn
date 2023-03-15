#include <stdio.h>
#include <stdlib.h>

#define NEED_FILE
#define NEED_CONVERT
#include "0head.c"

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void randary(int v[], int n)
{
	int i;
	
	for (i = 0; i < n; i++)
		v[i] = i + 1;
	for (i = 0; i < n; i++)
		swap(v, i, rand() % n);
}

char *randstr(int len)
{
	char s[len + 1];
	int i;
	
	for (i = 0; i < len; i++)
		s[i] = rand() % 26 + 'a';
	s[i] = '\0';
	return Strdup(s);
}
	
int main(int argc, char *argv[])
{
	int *v, i, n;
	char *s;
	FILE *fp;

	n = 0;
	printf("argc = %d\n", argc);
	if (argc == 2)
		n = Atoi(argv[1]);
	if (n == 0)
		n = 10;
	printf("n = %d\n", n);
	v = (int *) malloc(n * sizeof(*v));
	if (v == NULL)
		exit(1);
	randary(v, n);
	for (i = 0; i < n; i++)
		printf("%3d%c", v[i], i % 10 == 9 ? '\n' : '\t');
	printf("\n");
	/*
	fp = fopen("0test.c", "w");
	if (fp == NULL)
	{
		printf("can not open file \n");
		exit(0);
	}
	for (i = 0; i < 1000; i++)
	{
		s = randstr(1 + rand() % 5);
		fprintf(fp, "%s\n", s);
	}
	fclose(fp);
	*/
	return 0;
}

