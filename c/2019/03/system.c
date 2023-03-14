/* system() */
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char s[2048];
	printf("Input a command: \n");
	fgets(s, sizeof(s), stdin);
	system((const char *) s);
	return 0;
}
