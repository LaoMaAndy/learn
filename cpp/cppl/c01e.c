#include <stdio.h>
/*
 * Exercise 1-1. Run the "hello, world" program on your system. Experiment with leaving out parts of the program, to see what error messages you get.
 */

/*
 * Exercise 1-2. Experiment to find out what happens when printf's argument string contains \c, where c is some character not listed above.
 */

/*
 * Exercise 1-3. Modify the temperature conversion program to print a heading above the table.
 */
void heading()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0 ;
	upper = 300;
	step = 30;
	
	fahr = lower;
	printf("==Heading : Change fahr to celsius===\n");

	while (fahr <= upper)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
/*
 * 1-4. Write a program to print the corresponding Celsius to Fahrenheit table 
 */
void cels(void)
{
	float fahr, cels;
	int lower, upper, step;
	
	lower = -20;
	upper = 280;
	step = 30;

	cels = lower;
	while (cels <= upper)
	{
		fahr = cels * (9.0 / 5.0) + 32.0;
		printf("%3.0f %6.2f\n", cels, fahr);	
		cels = cels + step;
	}
}
/*
 * Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
 */
void modify(void)
{ int fahr; 
	for(fahr = 300; fahr >=0; fahr = fahr - 20)
		printf("%3d %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}


//
// Exercise 1-5.Verfiy that the expression getchar() != EOF is 0 or 1.
//
void verify()
{
	int val;
	printf("Please input a char or EOF:\n");
	val = (getchar() !=EOF );
	printf("The getchar() !=EOF value is : %d\n", val);
}
//
// Exercise 1--7. Write a program to print the value of EOF
//
void printEOF()
{
	printf("The eof value is %d\n", EOF);
}
//
// Exercise 1-8. Write a program to count blanks, tabs, and newline.
//
void count_btn()
{
	int c , b, t, n;
	b = t = n = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
			++n;
		if (c == ' ')
			++b;
		if (c == '\t')
			++t;
	}
	printf("blanks: %d, tabls: %d, newlines: %d\n", b, t, n);
}
//
// Exercise 1-9.Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
//
void copy_blank()
{
	int c, nob;
	nob = 0;
		
	while ((c = getchar()) != EOF)
	{
	/* this code can work, but not good
		if (c != ' ')
		{
			putchar(c);
			nob = 1;
		}
		if (c == ' ')
			if (nob == 1)
			{
				putchar(' ');
				nob = 0;
			}
		
	*/
	/* this code can't work
		if (nob == 1)
			putchar(c);
		if (c == ' ')
			nob = 0;
		else 
			nob = 1;
	*/
	//This code is better
/*		
		if (c != ' ' || nob == 1)
			putchar(c);
		if (c == ' ')
			nob = 0;
		else 
			nob = 1;
*/
	//this version is best
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (nob == 1)
			{	
				putchar(' ');
				nob = 0;
			}
		}
		else
		{
			putchar(c);
			nob = 1;
		}

	}
}
//
//Exercise 1-10. Write a program to copy its  input to its output, replacing each tab by 't, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
//
void replacing()
{
	int c;
	
	while ((c = getchar()) != EOF)
	{
		if ((c !='\t') && (c != '\b') && (c != '\\'))
			putchar(c);
		if (c == '\t')
		{
			putchar('\\');
			putchar('t');
		}
		if (c == '\b')
		{
			putchar('\\');
			putchar('b');
		}
		if (c == '\\')
		{
			putchar('\\');
			putchar('\\');
		}
	}

}

//
// Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
//
//
// Exercise 1-12. Write a program that prints its input one word per line.
//

void word_per_line()
{
	int c, state;
	state = 0;
	
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (state == 1)
			{
				putchar('\n');
				state = 0;
			}
		}
		else 			
		{
			putchar(c);	
			state = 1;
		}
	} 		
}
//
// Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
//
#define NWORD	100	
void histogram()
{
	int c, n, nw,  state;
	int wl[NWORD];
	
	for (n = 0; n < NWORD; ++n)
		wl[n] = 0;
	nw = state = 0;

	while (nw < NWORD && (c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (state == 1)
			{
				++nw;
				state = 0;
			}
		}
		else
		{
			++wl[nw];
			state = 1;
		}
	}

	for (n = 0; n < nw; ++n)
	{
		printf("%-2d: ", wl[n]);
		for (c = 0; c < wl[n]; ++c)
			putchar('#');
		putchar('\n');
	}
	putchar('\n');
}

void v_histogram()
{
	int c, n, nw, state, wl[NWORD];

	for (n= 0; n < NWORD; ++n)
		wl[n] = 0;
	nw = state = 0;

	while ((nw < NWORD) && ((c = getchar()) != EOF))
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (state == 1)
			{
				++nw;
				state = 0;
			}
		}
		else
		{
			++wl[nw];
			state = 1;
		}
	}
	
	int max = 0;
	for (n = 0; n < nw; ++n)
	{	
		if (wl[n] > max)
			max = wl[n];
	}

	for (n = 0; n < max; ++n)
	{
		for (c = 0; c < nw; ++c)
		{
			if (wl[c] + n >= max)
				printf("  #");
			else
				printf("   ");
		}
		putchar('\n');
	}
	
	for (n = 0; n < nw; ++n)
		printf("---");
	putchar('\n');

	for (n = 0; n < nw; ++n)
		printf("%3d", wl[n]);
	putchar('\n');

	printf("\nword max length is %d\n", max);
}
//
// Exercise 1-14. write a program to print a histogram of the frequencies of different characters in its input.
//
#define MAX_ALPHA 128
#define VISUAL_ALPHA_START '!'
#define HISTO_CHAR '#'
void freq(void)
{
	int na[MAX_ALPHA];
	int i, c, n;
	
	for (i = 0; i < MAX_ALPHA; ++i)
		na[i] = 0;
		 
	while ((c = getchar()) != EOF)
	{
		if (c < MAX_ALPHA)
			++na[c];
	}
	for (i = VISUAL_ALPHA_START; i < MAX_ALPHA; ++i)
		if (na[i] != 0)
		{
			printf(" %c (%2d) : ", (char)i, na[i]);
			for (n = 0; n < na[i]; ++n)
				putchar(HISTO_CHAR);
			putchar('\n');
		}
	putchar('\n');
}

//
//Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
//
float fahr2c(float fahr)
{
	return (5.0 / 9.0 * (fahr - 32.0));
}
void fahr3(void)
{
	int i;
	for (i = 0; i <= 300; i = i + 20)
		printf("%3d %6.1f\n", i, fahr2c((float)i));
}

//
// Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
//
#define LONGER_THAN 5
void print_longer(void)
{
	char buffer[LONGER_THAN + 1];
	int c, i, j;
	
	i = j = 0;
	while ((c = getchar()) != EOF)
	{
		if (c != '\n')
		{
			if (i < LONGER_THAN)
				buffer[i] = c;
			else if (i == LONGER_THAN)
			{
				buffer[i] = '\0';
				while (j < i)
					putchar (buffer[j++]);
				putchar (c);
				j = 0;
			}
			else if (i > LONGER_THAN)
				putchar (c);
			++i;
		}
		else 
		{
			if (i > LONGER_THAN)
				putchar('\n');
			i = 0;
		}
	}	
}


//
// Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
//
//There are two way : 
//	1)store all charactor into a buffer , when feedline is met ,remove all the blanks from buffer. then output it.
//	2)only store the blanks into a buffer, if a non-blank charactor is met, output the buffer; when a feedline is met , clearn the buffer.


#define MAX_CHAR_LINE	256
void remove_trail(void)
{
	char buffer[MAX_CHAR_LINE + 1];
	int c, i, j; 
	int re;

	re = i = j = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' )
		{
			if (i >= MAX_CHAR_LINE)
				i = 0;
			buffer[i++] = (char)c;
		}
		else if (c == '\n')
		{
			if (re != 0)
			{
				putchar('\n');
				i = 0;
				re = 0;
			}
		}
		else
		{
			if (i > 0)
				while (j < i)
					putchar (buffer[j++]);
			putchar(c);
			i = j = 0;
			re = 1;
		}
					
	}
}


void remove_trail_2(void)
{
	char buffer[MAX_CHAR_LINE+1];
	int c, i, j;
	int re; 

	re = i = j = 0;
	while ((c = getchar()) != EOF)
	{
		if (c != '\n')
		{
			buffer[i++] = (char)c;
			if (i >= MAX_CHAR_LINE)
				i = 0;
			re = 1;
		}
		else if (re != 0 && i > 0)
		{
			do
			{
				--i;
			}while ((i >= 0) && (buffer[i] == ' ' || buffer[i] == '\t'));

			while (j <= i)
				putchar(buffer[j++]);

			putchar('\n');
			i = j = re = 0; 
		}
	}
}
//
// Exercise 1-19. Write a funciton reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time
//
char* reverse(char *a)
{
	char *p, *s, temp;
	p = s = a;

	while (*p != '\0')
		++p;
	
	while (p > s)
	{
		--p;
		temp = *p;
		*p = *s;
		*s = temp;
		++s;
	}
	return a;
}

#undef MAX_LINE_CHAR
#define MAX_LINE_CHAR 128
void test_reverse(void)
{
	char buffer[MAX_LINE_CHAR + 1];
	int c, i = 0;

	while ((c = getchar()) != EOF)
	{
		if (c != '\n' && i < MAX_LINE_CHAR)
		{
			buffer[i++] = (char) c;
		}
		else
		{
			buffer[i] = '\0';
			reverse(buffer);
			printf("%s\n", buffer);
			i = 0;
		}
	}
}

//
// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
//
#define TAB_STOP 8
void datab(void)
{
	int c;
	int i = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			i = 0;
			putchar('\n');
		}
		else if (c == '\t')
		{
			int n;
			n = i + TAB_STOP - i % TAB_STOP;
			for (; i < n; ++i)
				putchar(' ');
		}
		else 
		{
			putchar(c);
			++i;
		}
	}
}
//
// Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be giben preference?
//
char *entab(char *s)
{
	char *p, *r;
	int i, sp;

	p = r = s;
	i = sp = 0;

	while (*p != '\0')
	{
		if (*p == '\n')
		{
			*r = '\n';
			i = sp = 0;
			++r;
		}
		else 
		{
			if (i % TAB_STOP == 0 && sp > 0)
			{
				*r = '\t';
				++r;
				sp = 0;
			}
			if (*p == ' ')
			{
				*(r + sp) = ' ';
				++sp;
				++i;
			}
			else if(*p == '\t')
			{
				*r = '\t';
				++r;
				i += TAB_STOP - i % TAB_STOP;
				sp = 0;
			}
			else 
			{
				r += sp;
				*r = *p;
				++r;
				++i;
				sp = 0;
			}
		}
		++p;
	}
	*r = '\0';
	return s;
}
#undef MAX_CHAR_INPUT
#define MAX_CHAR_INPUT 128

void test_entab(void)
{
	char line[MAX_CHAR_INPUT + 1];
	int c, i;

	for (i = 0; i < MAX_CHAR_INPUT && (c = getchar()) != EOF; ++i)
		line[i] = c;
	line[i] = '\0';
	
	entab(line);
	printf("%s\n", line);
}
//
// Exercise 1-22. Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
//

//In this case, program will update ' ' with '\n' before the fold_column will reach.
//if there is a very long word, program will do nothing.

#define FOLD_COLUMN 4

char *fold(char *s)
{
	char *p, *mid, *st;

	st= mid = p = s;
	
	do
	{
		if (*p == ' ' || *p == '\n' || *p == '\0')
		{
			if (p - st > FOLD_COLUMN)
			{
				if (mid > st)
				{
					*mid = '\n';
					st = mid;
					mid = p;
				}
				if (p - mid > FOLD_COLUMN)
				{
					if (*p != '\0')
						*p = '\n';
					st= mid = p;
				}
			}
			else 
			{
				mid = p;
			}
			if (*p == '\n')
				st = mid = p;
		}
	}while (*p++ != '\0');

	return s;
}

char *fold2(char *s)
{
	char *p, *mid, *st;

	st = mid = p = s;
	
	do
	{
		if (*p == ' ' || *p == '\n' || *p == '\0')
		{
			if (p - st > FOLD_COLUMN)
			{
				if (mid > st)
					*mid = '\n';
				st = mid;
				if (p - mid > FOLD_COLUMN)
				{
					if (*p != '\0')
						*p = '\n';
					st = p;
				}
			}
			mid = p;
			if (*p == '\n')
				st = mid = p;
		}
	}while (*p++ != '\0');

	return s;
}
#define TEST_BUFFER 1024
void test_fold(void)
{
	char buf[TEST_BUFFER + 1];
	int i, c;

	for (i = 0; i < TEST_BUFFER && (c = getchar()) != EOF; ++i)
		buf[i] = c;

	buf[i] = '\0';
	
	fold2(buf);
	printf("%s", buf);
}
//
// Exercise 1-23. Write a program to remove all comments from a c program. Don't forget to handle quoted strings and character constants properly. C comments do not next.
//
enum COMT_FLAG 
{
	IN_CODE,
	IN_STAR_COMMENT,
	IN_SLASH_COMMENT,
	END_COMMENT,
	IN_QUOT,
	OUT_QUOT,
};

char *r_comt(char *s)
{
	char *p, *cur;
	enum COMT_FLAG flag, quot;

	p = cur = s;
	flag = IN_CODE;
	quot = OUT_QUOT; 

	while (*p != '\0')	
	{
		switch(*p)
		{
		case '\"':
			if (flag == IN_CODE)
			{
				if (*(p - 1) != '\\')
				{
					if (quot == OUT_QUOT)
						quot = IN_QUOT;
					else 
						quot = OUT_QUOT;
				}
			}
			break;
		case '/':
			if (quot == OUT_QUOT && flag != IN_SLASH_COMMENT)
			{
				if (flag != IN_STAR_COMMENT && *(p + 1) == '*')
					flag = IN_STAR_COMMENT;
				else if (flag == IN_STAR_COMMENT && *(p - 1) == '*')
					flag = END_COMMENT;
				if (flag != IN_STAR_COMMENT && *(p + 1) == '/')
					flag = IN_SLASH_COMMENT;
			}
			break;
		case '\n':
			if (flag == IN_SLASH_COMMENT)
				flag = END_COMMENT;
			break;
		default:
			break;	
		}
		if (flag == IN_CODE)
		{
			*cur = *p;
			++cur;
		}
		else if (flag == END_COMMENT)
		{
			flag = IN_CODE;
		}
		p++;
	}

	*cur = '\0';
	return s;
}


char *r_comt2(char *s)
{
	char *p, *cur;
	enum COMT_FLAG flag;

	p = cur = s;
	flag = IN_CODE;

	while (*p != '\0')	
	{
		switch(*p)
		{
			case '\"':
				if (*(p - 1) != '\\' && flag == IN_QUOT)
					flag = IN_CODE;
				if (flag == IN_CODE)
					flag = IN_QUOT;
				break;
			case '/':
				if (*(p + 1) == '*' && flag == IN_CODE)
					flag = IN_STAR_COMMENT;
				if (*(p - 1) == '*' && flag == IN_STAR_COMMENT)
					flag = END_COMMENT;
				if (*(p + 1) == '/' && flag == IN_CODE)
					flag = IN_SLASH_COMMENT;
				break;
			case '\n':
				if (flag == IN_SLASH_COMMENT)
					flag = END_COMMENT;
				break;
			default:
				break;	
		}
		if (flag == IN_CODE || flag == IN_QUOT)
		{
			*cur = *p;
			++cur;
		}
		else if (flag == END_COMMENT)
		{
			flag = IN_CODE;
		}
		p++;
	}

	*cur = '\0';
	return s;
}


#define MAX_FILE_SIZE (20 * 1024)

void test_comment(void)
{
	char buf[MAX_FILE_SIZE];
	int i , c ;

	for (i = 0; i < MAX_FILE_SIZE && (c = getchar()) != EOF; ++i)
	{
		buf[i] = (char)c;
	}
	buf[i] = '\0';

	r_comt2(buf);
	printf("%s", buf);
}
//
// Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.)
//

enum CHECK_FLAG
{
	FLAG_IN_COMMENT_STAR,
	FLAG_IN_COMMENT_SLASH,
	FLAG_IN_CODE,
	FLAG_OUT_COMMENT,
	FLAG_FOR_OUT,
	FLAG_FOR_FIRST,
	FLAG_FOR_SECOND,
	FLAG_FOR_THIRD,
}; 
char *check_cp(char *s)
{
	int par, brak, brace, qt_s, qt_d;
	int line, par_line, brak_line, brace_line, qt_s_line, qt_d_line;
	enum CHECK_FLAG flag, for_flag;
	char *p;

	line = 1;
	par = brak = brace = qt_s = qt_d = 0;
	flag = FLAG_IN_CODE;
	for_flag = FLAG_FOR_OUT;
	p = s;

	do
	{
		if (flag == FLAG_IN_COMMENT_SLASH)
		{
			while (*p++ != '\n')
				;
			flag = FLAG_IN_CODE;
			++line;
		}
		if (flag == FLAG_IN_COMMENT_STAR)
		{
			while (!((*p == '*' && *(p + 1) == '/') || *p == '\0'))
			{
				if (*p == '\n')
					++line;
				++p;
			}
			flag = FLAG_IN_CODE;
		}
		if (flag == FLAG_IN_CODE)
		{
			switch (*p)
			{
				case '/':
					if (*(p + 1) == '*')
						flag = FLAG_IN_COMMENT_STAR;
					else if (*(p + 1) == '/')
						flag = FLAG_IN_COMMENT_SLASH;
					break;
				case '"':
					++qt_d;
					do
					{
						++p;
					} while (!((*p == '"' && *(p - 1) != '\\') || *p == '\n' || *p == '\0' || *p ==';'));
					if (*p == '"')
						++qt_d;
					qt_d_line = line;
					break;	
				case 'f':
					if (*(p + 1) == 'o' && *(p + 2) == 'r')
					{
						for_flag = FLAG_FOR_FIRST;
						--par;
					}
					break;
				case '\n':
					++line;
					break;
				case '(':
					++par;
					par_line = line;
					break;
				case ')':
					--par;
					par_line = line;
					break;
				case '[':
					++brak;
					brak_line = line;
					break;
				case ']':
					--brak;
					brak_line = line;
					break;
				case '\'':
					if (*(p - 1) != '\\')
					{
						++qt_s;
						qt_s_line = line;
					}
					break;
				case ';':	
					if (for_flag == FLAG_FOR_FIRST)
						for_flag = FLAG_FOR_SECOND;
					else if (for_flag == FLAG_FOR_SECOND)
						for_flag = FLAG_FOR_THIRD;
					//fall through
				case '{':
					if (par > 0)
						printf("line(%03d) expect symbol: )\n", par_line);
					if (par < 0)
						printf("line(%03d) expect symbol: (\n", par_line);
					if (brak > 0)
						printf("line(%03d) expect symbol: ]\n", brak_line);
					if (brak < 0)
						printf("line(%03d) expect symbol: [\n", brak_line);
					if (qt_d % 2 != 0)
						printf("line(%03d) expect symbol: \"\n", qt_d_line);
					if (qt_s % 2 != 0)
						printf("line(%03d) expect symbol: \'\n", qt_s_line);
					if (*p == '{')
						++brace;
					par = brak = qt_d = qt_s = 0;
					if (for_flag == FLAG_FOR_THIRD)
					{
						++par;
						for_flag = FLAG_FOR_OUT;
					}
					break;
				case '}':
					--brace;
					break;
				case '\0':
					if (brace > 0)
						printf("Expects symbol: }\n");
					if (brace < 0)
						printf("Expects symbol: {\n");
					break;
				default:
					break;
			}
		}
	} while (*p++ != '\0');

	printf("That's all, folks.\n");
}

void test_check(void)
{
	char buf[MAX_FILE_SIZE];
	int i , c ;

	for (i = 0; i < MAX_FILE_SIZE && (c = getchar()) != EOF; ++i)
	{
		buf[i] = (char)c;
	}
	buf[i] = '\0';

	check_cp(buf);
}
#define TEST(func) printf("Testing function "#func":\n");func()
int main(void)
{
	TEST(test_check);
	//TEST(test_comment);
	//TEST(test_fold);
	//TEST(test_entab);
	//TEST(datab);
	//TEST(test_reverse);
	//TEST(remove_trail_2);
	//TEST(remove_trail);
	//TEST(print_longer);
	//TEST(fahr3);
	//TEST(freq);
	//TEST(v_histogram);
	//TEST(histogram);
	//TEST(word_per_line);
	//TEST(replacing);
	//TEST(copy_blank);
	//TEST(count_btn);
	//TEST(printEOF);
	//TEST(verify);
	//modify();
	//cels();
	//heading();
	
	return 0;
}

