/*
   read & write a same file
*/
#include "0head.c"

void rw(FILE *fp)
{
	size_t rp = 0, wp = 0;

	int c;
	printf("Current ftell is: %ld\n", ftell(fp));
	c = fgetc(fp);
	printf("Current ftell is: %ld\n", ftell(fp));
	fputc(toupper(c), fp);
	printf("Current ftell is: %ld\n", ftell(fp));
	c = fgetc(fp);
	printf("Current ftell is: %ld\n", ftell(fp));
	fputc(toupper(c), fp);
	printf("Current ftell is: %ld\n", ftell(fp));
}

int test_rw(int argc, char *argv[])
{
	char def[] = "testfile";
	const char *fname;
	FILE *fp;
	fname = argc <= 1 ? def : argv[1];
	fp = fopen(fname, "r+");
	if (fp == NULL)
	{
		printf("Can't open file: %s\n", fname);
		return 1;
	}
	rw(fp);
	fclose(fp);
	return 0;
}

size_t strupd(const char *src, char *dest, const char *find, const char *replace)
{
	size_t flen = strlen(find), rlen = strlen(replace);
	const char *sp = src;
    char *dp = dest;
	char *cur;

	while (*sp != '\0')
	{
		if (*sp == *find && (strncmp(sp, find, flen) == 0))
		{
			strcpy(dp, replace);
			dp += rlen;
			sp += flen;
		}
		else
			*dp++ = *sp++;
	}
	return dp - dest;
}

/*		
while ((cur = strstr(sp, find)) != NULL)
	{
		strncpy(dp, sp, cur - sp);
		dp += cur - sp;
		strcpy(dp, replace);
		dp += rlen;
		sp = cur + flen;
	}
	strcpy(dp, sp);
	
	return dest;
}
*/

void test_strupd(void)
{
	char *s = "This a test , i love it";
	char *find = "i";
	char *rep = "IIII";
	char *dest = (char *) malloc(200);

	strupd(s, dest, find, rep);
	printf("src: %s\n", s);
	printf("find: %s\n", find);
	printf("replace: %s\n", rep);
	printf("dest: %s\n", dest);
}	

size_t fupd(FILE *fp, const char *s, const char *upd)
{
	size_t pos = ftell(fp);
	fseek(fp, 0, SEEK_END);
	size_t length = ftell(fp) - pos;
	fseek(fp, pos, SEEK_SET);
	char *rbuf = (char *) malloc(length);
	if (rbuf == NULL)
	{
		printf("can not malloc read buffer\n");
		return 0;
	}
	size_t wsize = (length / strlen(s) + 1) *strlen(upd) + 1;
	char *wbuf = (char *) malloc(wsize);
	printf("Read buf size: %ld, write buf size: %ld\n", length, wsize);
	if (wbuf == NULL)
	{
		free(rbuf);
		printf("Can not malloc write buf\n");
		return 0;
	}
	size_t a = fread(rbuf, length, 1, fp);
	printf("read size is: %ld\n", a);
	if (a != 1L)
	{
		printf("Read size is: %ld, not equal to file length: %ld\n", a, length);
		free(rbuf);
		free(wbuf);
		return 0;
	}
	strupd(rbuf, wbuf, s, upd);
	fseek(fp, pos, SEEK_SET);
	size_t len = strlen(wbuf);
	printf("write buf size is: %ld\n", len);
	return fwrite(wbuf, len, 1, fp);
}

int test_fupd(int argc, char *argv[])
{
	char def[] = "testfile";
	const char *fname;
	FILE *fp;
	fname = argc <= 1 ? def : argv[1];
	fp = fopen(fname, "r+");
	if (fp == NULL)
	{
		printf("Can't open file: %s\n", fname);
		return 1;
	}
	fupd(fp, "t", "T T");
	fclose(fp);
	return 0;
}



int main(int argc, char *argv[])
{
	test_strupd();
	test_fupd(argc, argv);
}
