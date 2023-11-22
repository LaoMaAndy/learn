#include "head.h"
#include "keyword.h"

void test_getline(FILE *fp)
{
	char buf[200];
	size_t n = sizeof(buf) / sizeof(*buf);

	printf("===Test Getline()===\n");
	while (Getline(fp, buf, n) != 0)
		printf("%s", buf);
}

void test_getword(FILE *fp)
{
	char buf[200];
	size_t n = sizeof(buf) / sizeof(*buf);

	printf("===test Getword()===\n");
	while (Getword(fp, buf, n) != EOF)
		if (Isalpha(buf[0]))
			printf("%s\t\t", buf);
	printf("\n");
}

void test_strsearch(void)
{
	char *s[] = 
	{
		"a",
		"bbbbbb",
		"ccccccc",
		"dddd",
		"eee",
		"fff",
		"gg",
		"hh"
	};
	int n = sizeof(s) / sizeof(s[0]);
	int i, ok = 1;
	int d;

	printf("===test Strsearch()===\n");
	printf("String: \n");
	for (i = 0; i < n; i++)
		printf("%2d: %s\n", i, s[i]);
	d = Strsearch("", s, n);
	printf("Search \"\"  : %3d %s\n", d, ((d == -1) ? "OK" : "Err"));
	d = Strsearch("  ", s, n);
	printf("Search \"  \": %3d %s\n", d,((d == -1) ? "OK" : "Err"));
	d = Strsearch("a ", s, n);
	printf("Search \"a \": %3d %s\n", d, ((d == -1) ? "OK" : "Err"));
	for (i = 0; i < n; ++i)
		if (Strcmp(s[i], s[Strsearch(s[i], s, n)]) !=0 )
			ok = 0;
	if (ok == 1)
		printf(OK_STR);
	else
		printf(ERR_STR);
}

void Wordcount(FILE *fp);
void test_wordcount(FILE *fp)
{
	printf("----Test Wordcount() ----\n");
	Wordcount(fp);
}

void file_key(FILE *fp, char *key[], int nkey);
void test_filekey(FILE *fp, char *keyword[], int n)
{
	printf("---- Test file_key() ----\n");
	file_key(fp, keyword, n);
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
	test_getline(fp);
	fseek(fp, 0, SEEK_SET);
	test_getword(fp);
	fseek(fp, 0, SEEK_SET);
	test_wordcount(fp);
	test_strsearch();
	fseek(fp, 0, SEEK_SET);
	test_filekey(fp, key_word, n);

	printf("\nUsage: command + filename\n");
	fclose(fp);
	return 0;
}
