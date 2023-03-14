#include "head.h"

int Getline(FILE *fp, char *dest, int lim)
{
	char *d = dest;
	int c;

	while (--lim > 0 && (c = fgetc(fp)) != EOF && c != '\n')
		*d++ = c;
	if (c == '\n')
		*d++ = c;
	*d = '\0';
	return d - dest;
}

int Getword(FILE *fp, char *dest, int lim)
{
	char *d = dest;
	int c;

	while (Ispace(c = fgetc(fp)))
		;
	if (c != EOF)
		*d++ = c;
	if (!Isalpha(c))
	{
		*d = '\0';
		return c;
	}
	for ( ; --lim > 0; d++)
		if (!Isalnum(*d = fgetc(fp)))
		{
			ungetc(*d, fp);
			break;
		}
	*d = '\0';
	return *dest;
}

char *Strdup(const char *s)
{
	char *p;

	p = (char *) malloc(Strlen(s) + 1);
	if (p != NULL)
		Strcpy(p, s);
	return p;
}

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
/* read a text file into memory, split it into strings, every string ends with '\0'.
 * store every string pointer into a set of char *[].
 */
int Getlist(FILE *fp, char **lp[])
{
	/* get the file size */
	long int fsize;
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	if (fsize == 0L)
		return 0;

	/* get enough memory to read all the file into buffer. 
	 get enough memory to store every word's size */
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
	
	/* read the file to memory, insert a '\0' between every word.
	 "word" : all alphabit or digit, without punctuation.
	 store every word's size into "next" */
	fseek(fp, 0, SEEK_SET);
	char *bp = buf;
	int *np = next; 
	int wsize = 0;
	int state = 0;
	int c;
	do
	{
		c = fgetc(fp);
		if (Isalnum(c))
		{
			*bp++ = c;
			wsize++;
			state = 1;
		}
		else if (!Isalnum(c) && state == 1)
		{
			*bp++ = '\0';
			*np++ = wsize + 1;		//word's size + 1 ('\0')
			wsize = 0;
			state = 0;
		}
	} while (c != EOF);

	/* alloc memory to store pointers, which point to each word */
	nw = np - next;
	char **list = (char **) malloc(nw * sizeof(*list) + 1);
	if (list == NULL)
	{
		free(buf);
		free(next);
		return 0;
	}
	/* count the exact size of word buffer, resize the buffer */
	nc = bp - buf;
	bp = realloc(buf, nc);
	if (bp != NULL)
		buf = bp;
	/* get every word address, store into list */
	bp = buf;
	for (int i = 0; i < nw; i++)
	{
		list[i] = bp;
		bp += next[i];
	}
	/* add a NULL in the end */
	list[nw] = NULL;
	*lp = list;
	free(next);
	/* return the word's count */
	return nw;
}
