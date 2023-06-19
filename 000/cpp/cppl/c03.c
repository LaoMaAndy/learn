//
// Chapter 3: Control Flow
//
// 3.1 Statements and Blocks
//
// 3.2 If-Else
//
// 3.3 Else-If
//
#include <stdio.h>
// Binsearch: find x in v[0] <= v[1] <= ... <= v[n - 1] 
int my_binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		//printf("mid is %d\n", mid);
		if (x < v[mid]) 
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else 
			return mid;
	}
	return -1;
}

void test_my_binsearch(void)
{
	int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	printf("search 1 is %d\n", my_binsearch(1, v, 14));
	printf("search 6 is %d\n", my_binsearch(6, v, 14));
	printf("search 10 is %d\n", my_binsearch(10, v, 14));
	printf("search 14 is %d\n", my_binsearch(14, v, 14));
	printf("search 20 is %d\n", my_binsearch(20, v, 14));
}

//
// 3.4 switch
//
//Count digits, white space, others
//
void count_digits(void)
{
	int c, i, nwhite, nother, ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; i ++)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
	{
		switch (c)
		{
			case '0':	case '1':	case '2':	case '3':	case '4':
			case '5':	case '6':	case '7':	case '8':	case '9':
				ndigit[c - '0']++;
				break;
			case ' ':
			case '\n':
			case '\t':
				nwhite++;
				break;
			default:
				nother++;
				break;
		}
	}
	printf("digits = ");
	for (i = 0; i < 10; i ++)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}

//
// 3.5 Loops--While and for
//
void skip_white(void)
{
	int c;

	while (c == ' ' || c == '\n' || c == '\t')
		;
	putchar(c);
}
#include <ctype.h>
// atoi: convert s to integer; version 2
int atoi_v2(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	
	return sign * n;
}
#define LINE_BUF 1024
void test_atoi_v2(void)
{
	int c, i = 0;
	char buf[LINE_BUF];

	printf("Please input a number :");
	for (i = 0; i < LINE_BUF && (c = getchar()) != EOF && c != '\n'; ++i)
		buf[i] = c;
	buf[i] = '\0';

	printf("The number is: %d\n", atoi_v2(buf));
}

//
// Shellsort: sort v[0]...v[n-1] into increasing order
//
void shellsort(int v[], int n)
{
	int gap, i, j, temp;
	int k, n1, n2, n3;
	n1 = n2 = n3 = 1;

	printf("Start sorting:\n");
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		printf("n1 loop, times :%d, gap = %d \n", n1++, gap);
		for (k = 0; k < n; ++k)
			printf("%d ", v[k]);
		printf("\n");
		
		n2 = 1;
		for (i = gap; i < n; i++)
		{
			printf("\tn2 loop, times :%d , i = %d \n\t", n2++, i);
			for (k = 0; k < n; ++k)
				printf("%d ", v[k]);
			printf("\n");
			n3 = 1;

			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
			{
				printf("\t\tn3 loop, times :%d , j = %d, j + gap is %d \n\t\t", n3++, j, j + gap);
				for (k = 0; k < n; ++k)
					printf("%d ", v[k]);
				printf("\n");

				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}

void de_shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] < v[j + gap]; j -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
}

void test_shellsort(void)
{
	int i[] = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int n = (sizeof(i) / sizeof(int));
	int k; 

	printf("sizeof(i) is: %ld\n", sizeof(i));
	printf("Before sort:\n");
	for (k = 0; k < n; ++k)
		printf(" %d", i[k]);
	printf("\n");

	shellsort(i, n);
	
	printf("After sort:\n");
	for (k = 0; k < n; ++k)
		printf(" %d", i[k]);
	printf("\n");

	de_shellsort(i, n);
	
	printf("After revorse sort:\n");
	for (k = 0; k < n; ++k)
		printf(" %d", i[k]);
	printf("\n");

}
	
//
// bubbleosrt
void bubblesort(int v[], int n)
{
	int i, j, temp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1])
			{
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
}

void test_bubblesort(void)
{
	int i[] = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 15, 17, 16};
	int n = (sizeof(i) / sizeof(i[0])) ;
	int k; 

	printf("sizeof(i) is: %ld\n", sizeof(i));
	printf("Before sort:\n");
	for (k = 0; k < n; ++k)
		printf(" %d", i[k]);
	printf("\n");

	bubblesort(i, n);
	
	printf("After sort:\n");
	for (k = 0; k < n; ++k)
		printf(" %d", i[k]);
	printf("\n");
}
	
//
// Reverse: reverse string s in place
//
#include <string.h>

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
#undef LINE_BUF
#define LINE_BUF 1024

void test_reverse(void)
{
	char buf[LINE_BUF + 1];
	char test[4] = "test";
	int c, i = 0;

	while (i < LINE_BUF && (c = getchar()) != EOF && c != '\n')
		buf[i++] = c;
	buf[i] = '\0';
	buf[i + 1] = '\0';
	printf("sizeof buf is %ld, Current i is %d\n", sizeof(buf), i);
	printf("sizeof test is %ld, test string %s\n", sizeof(test), test);
	printf("strlen(test) is %ld\n", strlen(test));

	reverse(buf);
	printf("Reverse string is :\n%s\n",buf);
}
	
//
// 3.6 Loops--Do-while
//
// itoa: convert n to characters in s
void my_itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0) // record sign
		n = -n;
	i = 0;
	do
	{
		s[i++] = n % 10 + '0';
	}while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

#undef LINE_BUF
#define LINE_BUF 256
void test_my_itoa(void)
{
	char buf[LINE_BUF];
	int c, i = 0;

	printf("Input a number:\n");
	for (i = 0; i < LINE_BUF && (c = getchar()) != EOF && c != '\n'; ++i)
		buf[i] = c;
	buf[i] = '\0';
	
	printf("The input number is: %d\n", i = atoi_v2(buf));
	my_itoa(i, buf);
	printf("itoa is            : %s\n",buf); 
}
//
// 3.7 Break and Continue
//
// trim: remove trailing blanks, tabs, newlines
int trim(char s[])
{
	int n;

	for (n = strlen(s) - 1; n >= 0; --n)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	s[n + 1] = '\0';
	return n;
}

void test_trim(void)
{
	char s[] = "This is a test \t\t       ";

	printf("%s<--END\n", s);
	trim(s);
	printf("%s<--END\n", s);
}
	
#define TEST(func) printf("Testing function "#func":\n");func()

int main(void)
{
	TEST(test_bubblesort);
	//TEST(test_trim);
	//TEST(test_my_itoa);
	//TEST(test_reverse);
	//TEST(test_shellsort);
	//TEST(test_atoi_v2);
	//TEST(skip_white);
	//TEST(count_digits);
	//TEST(test_my_binsearch);

	return 0;
}

