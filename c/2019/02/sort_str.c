/* sort_str.c */
#include "template/head.h"
struct File_Buf
{
	char **ptr;
	char *buf;
	unsigned nword;
};
typedef struct File_Buf file_buf;
file_buf *file_read_buf(FILE *fp);
file_buf *file_word(file_buf *p);
file_buf *file_word(FILE *fp)
{
	//file_buf fb;
	// Get file size.

	// alloc memory to store file

	// alloc memory to store pointer array

	// read file, one word by one word

	// store each pointer to array

	// resize memory, free unused memory

	// return structure pointer
	
}
void str_swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
int str_search(const char *x, char *v[], int n)
{
	int high, low, mid;
	int r;

	high = n;
	low = 0;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		r = Strcmp(v[mid], x);
		if (r > 0)
			high = mid;
		else if (r < 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
void str_sort(char *v[], int n)
{
	int i, last;

	if (n <= 1)
		return;
	str_swap(v, 0, n / 2);
	last = 0;
	for (i = 1; i < n; ++i)
		if (Strcmp(v[i], v[0]) < 0)
			str_swap(v, ++last, i);
	str_swap(v, 0, last);
	str_sort(v, last);
	str_sort(v + last + 1, n - last - 1);
}
