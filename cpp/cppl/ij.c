#include <stdio.h>

int main(void)
{
	int c;
	int i, j ;
	char buffer[256];

	i = j = 0;

	while ((c = getchar()) != EOF)
	{
		buffer[i++] = c;
		while (j < i)
			putchar (buffer[j++]);
		if (c == '\n')
			i = j = 0;
	}
	return 0;
}

