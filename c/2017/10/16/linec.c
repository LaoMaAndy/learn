#define NEED_FILE
#include "0head.c"
struct wc
{
	int nc, nw, nl;
};

struct wc wordcount(FILE *fp)
{
	int c, state;
	struct wc w;

	w.nc = w.nw = w.nl = state =  0;
	while ((c = fgetc(fp)) != EOF)
	{
		++w.nc;
		if (c == '\n')
			++w.nl;
		if (Isspace(c))
			state = 0;
		else if (state == 0)
		{
			++w.nw;
			state = 1;
		}
	}
	return w;
}

int linecount(FILE *fp)
{
	char buf[1024];
	int bsize = sizeof(buf) / sizeof(*buf);
	int count = 0;

	while (Getline(fp, buf, bsize))
		if (Strlen(Trim(buf)) > 0)
			++count;
	return count;
}

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("usage linecount  file1, file2...\n");
		return 1;
	}
	int total = 0;
	struct wc wt = {0, 0, 0};
	for (int i = 1; i < argc; ++i)
	{
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL)
		{
			printf("Can not open file: %s\n", argv[i]);
			return 2;
		}
		struct wc w = wordcount(fp);
		wt.nc += w.nc;
		wt.nw += w.nw;
		wt.nl += w.nl;
		fseek(fp, 0, SEEK_SET);
		int line = linecount(fp);
		total += line;
		//printf("ns-line: %5d (char:%5d, word: %4d, line: %4d) - %s\n", line, w.nc, w.nw, w.nl,argv[i]);
		printf("%5d - %s\n", line, argv[i]);
		fclose(fp);
	}
	//printf("total: %6d (char:%6d, word: %6d, line: %5d)\n", total, wt.nc, wt.nw, wt.nl);
	printf("total: %d \n", total);
	return 0;
}
