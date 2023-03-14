//
// to fold a long statement into 80 character width and start with //
// 
#include <stdio.h>
#include <stdlib.h>


#define FOLD_LENGTH 80

char *fold(char *s, char *t, long size)
{
	// fold the line into 80 character width and start with //	
	char *p, *q;
	long i = 0;


}

int fold_statement(FILE *fp)
{
	long size, i;
	char *p, *q;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	if (size == 0)
		return 0;
	
	q = p = (char *)malloc(size + 1);
	if (p == NULL)
		return 0;

	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < size; i++)
		*p++ = (char)fgetch(fp);

	*p = '\0';
	fseek(fp, 0, SEEK_SET);

	return 1;
}

int main(int argc, char **argv)
{
	// Describe:
	//	if argc == 1, then request a filename by keyboard
	//	open this file, if fail, exit
	//	malloc a buffer, read the file into memory, if fail, exit
	//	malloc another buffer, bigger than previous
	//	call function, fold it 
	//	write the file, 
	//	close the file, release the buffer

	return 0;
}
