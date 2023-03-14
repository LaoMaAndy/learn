/*
function: convert, file get
*/
#define NEED_STRING
#include "0head.c"


int Atoi(const char *s)
{
	int val, sign;

	while (Isspace(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	for (val = 0; Isdigit(*s); s++)
		val = val * 10 + (*s - '0');
	return sign * val;
}

double Atof(const char *s)
{
	double val, power;
	int sign;

	while (Isspace(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	for (val = 0.0; Isdigit(*s); s++)
		val = val * 10.0 + (*s - '0');
	if (*s == '.')
		s++;
	for (power = 1.0; Isdigit(*s); s++)
	{
		val = val * 10.0 + (*s - '0');
		power *= 10.0;
	}
	return sign * val / power;
}

char *Itoa(int n, char *dest)
{
	char *d = dest;
	int sign;

	if ((sign = n) < 0)
		n = -n;
	do
	{
		*dest++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		*dest++ = '-';
	*dest = '\0';
	Reverse(d);
	return d;
}

void Printd(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10 > 0)
		Printd(n / 10);
	putchar(n % 10 + '0');
}

unsigned Getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

int Getline(FILE *fp, char *buf, int bsize)
{
	int c;
	char *b = buf;

	while ((c = fgetc(fp)) != EOF && c != '\n')
		*buf++ = c;
	if (c == '\n')
		*buf++ = c;
	*buf = '\0';
	return buf - b;
}

int Getword(FILE *fp, char *buf, int bsize)
{
	int c;
	char *b = buf;

	while (Isspace(c = fgetc(fp)))
		;
	if (c != EOF)
		*buf++ = c;
	if (!Isalpha(c))
	{
		*buf = '\0';
		return c;
	}
	for ( ; --bsize > 0; buf++)
		if (!Isalnum(*buf = fgetc(fp)))
		{
			ungetc(*buf, fp);
			break;
		}
	*buf = '\0';
	return b[0];
}



void test_type(void)
{
	char a[100] = "AbCdEfGhIjK012#^";
	char b[100] = "-1234567.00";
	char c[100] = " -908076.543a";
	int d = -12345678;
	char e[100];
	unsigned f = 0x1F320;

	PRN_STR(-----------);
	PRN_VAR(a, s);
	PRN_FUN(Atoi(b), d);
	PRN_FUN(Atof(b), .2f);
	PRN_FUN(Atof(c), f);
	PRN_FUN(Itoa(d, e), s);
	PRN_CAL(Printd(13579));
	PRN_STR();
	PRN_FUN(Getbits(f, 15, 4), X);
}

void test_get(int argc, char *argv[])
{
	FILE *fp;
	char buf[1000];
	int n = sizeof(buf) / sizeof(buf[1]);
	
	if (argc == 1)
	{
		printf("usage: command + argument.\n");
		exit(0);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Can't open file: %s\n", argv[1]);
		exit(0);
	}
	while (Getline(fp, buf, n) != 0)
		printf("%s\n", buf);
	printf("Press Enter to continue: \n");
	getchar();
	fseek(fp, 0, SEEK_SET);
	printf("===== Getword()=======\n");
	while (Getword(fp, buf, n) != EOF)
		printf("%s\n", buf);
}
	
/*
 * Main fucntion
 */

int main(int argc, char *argv[])
{
	test_type();
	printf("press Enter to continue\n");
	getchar();
	test_get(argc, argv);

	return 0;
}

