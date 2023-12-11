#include <stdio.h>

char array_1[] = "first";
char array_2[] = "Second";
char array_3[] = "Third";
char *ptr_a[] = {array_1, array_2, array_3};
char **ptr_b = ptr_a;

char *ptr_c[] = {"abdefghi","1234567","ABCDEFG","!@#$%"};

void test_ptr_array(char *ptr[])
{
	/*
	char *ptr[] = {"abdefghi","1234567","ABCDEFG","!@#$%"};
	*/
	printf("1st string %s\n",ptr[0]);
	printf("2nd string %s\n", *++ptr);
	printf("3rd string %s\n", (++ptr)[0]);
	printf("3rd string 1st char: %c\n", *ptr[0]);
	printf("3rd string 2nd char: %c\n", *++ptr[0]);
	printf("3rd string 3rd char: %c\n", *++(*ptr));
	
}

int main(int argc, char *argv[])
{
	test_ptr_array(ptr_b);
	test_ptr_array(ptr_c);

	return 0;
}
