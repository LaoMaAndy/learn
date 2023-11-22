/*
 array of list
 */
#define NEED_TYPE
#include "0head.c"

int Getlist(FILE *fp, char ***lp)
{
	/* get the file size */
	long int fsize;
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	if (fsize == 0L)
		return 0;

	long int nc = fsize + 1L;
	long int nw = sizeof(int) * fsize / 2 + 1L;
	char *buf = (char *) malloc(nc);
	if (buf == NULL)
		return 0;
	int *next = (int *) malloc(nw);
	if (next == NULL)
	{
		free(buf);
		return 0;
	}
	
	fseek(fp, 0, SEEK_SET);
	char *bp = buf;
	int *np = next; 
	int wl = 0;
	int state = 0;
	int c;
	do
	{
		c = fgetc(fp);
		if (Isalnum(c))
		{
			state = 1;
			*bp++ = c;
			wl++;
		}
		else if (!Isalnum(c) && state == 1)
		{
			state = 0;
			*bp++ = '\0';
			*np++ = wl + 1;
			wl = 0;
		}
	} while (c != EOF);
	nw = np - next;
	char **list = (char **) malloc(nw * sizeof(*list));
	if (list == NULL)
	{
		free(buf);
		free(next);
		return 0;
	}
	nc = bp - buf;
	bp = realloc(buf, nc);
	if (bp != NULL)
		buf = bp;
	bp = buf;
	for (int i = 0; i < nw; i++)
	{
		list[i] = bp;
		bp += next[i];
	}
	*lp = list;
	free(next);
	return nw;
}


int main(int argc, char *argv[])
{
	FILE *fp;
	char **list;

	if (argc < 2)
	{
		printf("Usage: nnn + filename\n");
		return 1;
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Can't open file: %s\n", argv[1]);
		return 2;
	}
	int n;
	n = Getlist(fp, &list);
	if (n == 0)
		printf("get list number 0.\n");
	printf("n is %d\n", n);
	for (int i = 0; i < n; i++)
		printf("%d: %s\n", i, list[i]); 
	fclose(fp);
	return 0;
}
	


