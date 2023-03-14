/*
 * command & arguments.
 */
#include "000string.c"

/* count number of char , line, word */
void wordcount(FILE *fp)
{
	int nc, nw, nl, inword;
	int c;

	nc = nw = nl = inword = 0;
	while ((c = fgetc(fp)) != EOF)
	{
		nc++;
		if (c == '\n')
			nl++;
		if (Ispace(c))
			inword = 0;
		else if (inword == 0)
		{
			inword = 1;
			++nw;
		}
	}
	printf("char: %d, word: %d, line: %d\n", nc, nw, nl);
}

extern struct ckey keytab[];
struct ckey *searchkey(char *word, struct ckey *tab, int n)
{
	int cond;
	struct ckey *low = &tab[0];
	struct ckey *high = &tab[n];
	struct ckey *mid;

	while (low < high)
	{
		mid = low + (high - low) / 2;
		if ((cond = Strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return NULL;
}

#define MAX_WORD 100
void ckeycount(FILE *fp)
{
	char word[MAX_WORD];
	struct ckey *p;

	/*
	while (Getword(fp, word, MAX_WORD) != EOF)
		printf("%s\n", word); return;
	*/

	while (Getword(fp, word, MAX_WORD) != EOF)
		if (Isalpha(word[0]))
			if ((p = searchkey(word, keytab, keycount)) != NULL)
				p->count++;
	for (p = keytab; p < keytab + keycount; p++)
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
}

// table lookup
void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}


/*
 * test 
 */

void test(int argc, char *argv[])
{
	
	FILE *fp;

	if (argc == 1)
	{
		printf("usage: use a filename as argument.\n");
		return ;
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Can not open file: %s. \n", argv[1]);
		return ;
	}
	printf("word count: %s\n", argv[1]);
	wordcount(fp);
	
	printf("count key words: %s\n", argv[1]);
	fseek(fp, 0, SEEK_SET);
	//for (int i = 0; i < keycount; i++)
	//	printf("%3d: %s\n", keytab[i].count, keytab[i].word);
	//filecopy(fp, stdout);	
	ckeycount(fp);

	fclose(fp);
}

		
/*
 * Main function.
 */

int main(int argc, char *argv[])
{
	test(argc, argv);	
	return 0;
}

