/* test_tree.c */
#include "head.h"
#include "keyword.h"

void file_tree(FILE *fp);
void file_table(FILE *fp);

void test_tree(FILE *fp)
{
	printf("---- test tree ----\n");
	file_tree(fp);
}
void test_table(FILE *fp)
{
	printf("---- test table ----\n");
	file_table(fp);
}
int main(int argc, char *argv[])
{
	FILE *fp;
	char *fname = "template/test.txt";
	int n = sizeof(key_word) / sizeof(*key_word);

	if (argc == 1)
		fp = fopen(fname, "r");
	else
		fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Can not open file: %s\n", (argc == 1) ? fname : argv[1]);
		return 1;
	}
	fseek(fp, 0, SEEK_SET);
	test_tree(fp);
	fseek(fp, 0, SEEK_SET);
	test_table(fp);
	fclose(fp);	

	return 0;
}
