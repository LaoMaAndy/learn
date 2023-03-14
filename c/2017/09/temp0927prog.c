/*
 * command line arguments
 */
#include <stdio.h>
#define LINE_BUF_SIZE 0x200
char Line_buf[LINE_BUF_SIZE];

void wordcount(void)
{
	int c, nl, nw, nc, state;

	state = nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' '|| c == '\n' || c == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			++nw;
		}
	}
	printf("char: %d, word: %d, line: %d\n", nc, nw, nl);
}

int Getline(char *s, int lim)
{
	int c, i;

	if (lim <= 1)
		return 0;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return i;
}

void printd(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

void putarg(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");
	printf("\n");
}

void putarg_a(int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
	printf("\n");
}

void putarg_b(int argc, char *argv[])
{
	int c;

	printf("argument switch:\n");

	while (--argc > 0)
		if ((*++argv)[0] == '-')
		{
			putchar(*++argv[0]);
			putchar(' ');
		}
	printf("\n");
}

/*
 * test these functions 
 */

void test(void)
{
	int i = 87654321;
	printf("input some word. ctrl-d to exit.\n");
	wordcount();
	printf("Output d: %d\n", i);
	printd(i);
	printf("\n");
}


/* 
 * Main function
 */

int main(int argc, char *argv[])
{
	int i;

	printf("argc: %d\n", argc);
	if (argc == 1)
		printf("Echo command-line arguments. Please add some arguments.\n");
	putarg(argc, argv);
	putarg_a(argc, argv);
	putarg_b(argc, argv);
	//test();

	return 0;
}




