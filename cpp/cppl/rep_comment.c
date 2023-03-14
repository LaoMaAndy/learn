#include <stdio.h>

#define LINE_BUF 1024
char line_buffer[LINE_BUF];

int read_line(FILE *fp, char *buf, int buf_size)
{
	int c, i = 0;
	
	for (i = 0; i < buf_size && !feof(fp) && ((c = fgetc(fp)) != EOF) && c != '\n'; ++i)
		buf[i] = c;

	buf[i] = '\0';

	return i;
}

int write_buf(FILE *fp, char *buf, int buf_size)
{
	int i;

	for (i = 0; i < buf_size && buf[i] != '\0'; ++i)
		fputc(buf[i], fp);
	
	return i;
}

int process_buf(char *buf, int buf_size)
{
	char *p = buf, c;
	int i = 0;
	
	while ((c = buf[i]) != '\0')
	{
		
	}
	return i;
}
int main(int argc, char **argv)
{

	return 0;
}
