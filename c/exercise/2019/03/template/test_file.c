#include "head.h"

int Getchar(void);
int Getchar2(void);
char *Fgets(char *line, int n, FILE *fp);
char *Fgets2(char *line, int n, FILE *fp);
int Fputs(char *s, FILE *fp);
void Filecopy(FILE *in, FILE *out);
void Printf(char *fmt, ...);

/* use some function to test */
// #include <stdio.h>
// FILE *tmpfile(void);
// char *tmpname(char *s);  // L_tmpnam  , is the minimum size;
// char *mkstemp();
// int remove(const char *filename);
// rename(const char *old, const char *new);
// FILE *freopen(const char * restrict filename, const char * restrict mode, FILE * restrict stream);
// int system(const4 char *command);
void Filecat(int argc, char *argv[])
{
	FILE *fp;
	char *prog = argv[0];

	if (argc == 1)
		Filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				fprintf(stderr, "%s: Can't open %s\n", prog, *argv);
				return ;
			}
			else
			{
				Filecopy(fp, stdout);
				fclose(fp);
			}
	if (ferror(stdout))
		fprintf(stderr, "%s: error writing stdout\n", prog);
	return ;
}
void test_printf()
{
	Printf("===Testing Printf()\n");
	Printf("\tPrintf(int   ): %d\n", 12345);
	Printf("\tPrintf(doubel): %f\n", 6789.01);
	Printf("\tPrintf(char *): %s\n", "abcdefg");
}
void test_fputs(FILE *fp)
{
	char s1[] = "This is a test file\n";
	char s2[] = "1234567890\n";
	char s3[] = "abcdefghijklmn...\n";

	printf("=======  test Fputs(), write some text into file\n");
	fseek(fp, 0, SEEK_SET);
	Fputs(s1, fp);
	Fputs(s2, fp);
	Fputs(s3, fp);
}
void test_fgets(FILE *fp)
{
	char buf[1024];

	printf("=======  Test Fgets(), read from file: \n");
	fseek(fp, 0, SEEK_SET);
	while (Fgets(buf, sizeof(buf), fp) != NULL)
		Fputs(buf, stdout);
}
void test_fgets2(FILE *fp)
{
	char buf[1024];

	printf("=======  Test Fgets2(), just the same as above: \n");
	fseek(fp, 0, SEEK_SET);
	while (Fgets(buf, sizeof(buf), fp) != NULL)
		Fputs(buf, stdout);
}
void test_filecopy(FILE *in, FILE *out)
{
	char buf[1024];

	fseek(in, 0, SEEK_SET);
	fseek(out, 0, SEEK_SET);
	printf("=======  Test filecopy(). after filecopy:\n");

	Filecopy(in, out);
	fseek(out, 0, SEEK_SET);
	while (Fgets(buf, sizeof(buf), out) != NULL)
		Fputs(buf, stdout);
}
void test_getchar()
{
	int c;

	printf("=======  Test Getchar(), ");
	printf("Please input some text\n");

	while ((c = Getchar()) != EOF)
		putchar(c);
	printf("\n");
}
void test_file(const char *command)
{
	char f1[] = "tttt_XXXXXX";
	char f2[] = "tttt_XXXXXX";
	char cmd[4096];
	FILE *file1, *file2;

	if (mkstemp(f1) == -1 || mkstemp(f2) == -1)
	{
		printf("tmpnam() return NULL\n");
		return;
	}
	file1 = fopen(f1, "r+");
	file2 = fopen(f2, "r+");
	if (file1 == NULL)
	{
		printf("Can not open temp_file 1\n");
		return;
	}
	if (file2 == NULL)
	{
		printf("Can not open temp_file 2\n");
		fclose(file1);
		return;
	}
	test_printf();
	test_fputs(file1);
	test_fgets(file1);
	test_fgets2(file1);
	test_filecopy(file1, file2);

	test_getchar();

	fclose(file1);
	fclose(file2);
	remove(f1);
	remove(f2);
	printf("Remove all file, Test OK\n");
}
int main(int argc, char *argv[])
{

	system("rm tttt_*");
	test_file(argv[0]);

	return 0;
}