// Echo2 prints its command-line arguments.
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i;
	char s[200] = "";

	for (i = 1; i < argc; ++i)
	{
		strcat(s, argv[i]);
		strcat(s, " ");
	}
	printf("%s\n", s);
	return 0;
}

