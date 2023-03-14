//test if - else statement
#include <stdio.h>

int ifelse(void)
{
	static int i = 3;

	if (i == 3)
	{
		printf("i :%d\n", i);
		i = 2;
	}
	else if (i == 2)
	{
		printf("i :%d\n", i);
		i = 1;
	}
	else if (i == 1)
	{
		printf("i :%d\n", i);
	}
	return 0;
}

int main(int argc, char *argv[])
{
	ifelse();
	ifelse();
	ifelse();
	
	return 0;
}

