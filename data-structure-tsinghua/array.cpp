/*
 data structure: array
 */
#include "0head.h"

#define Data int
class Array
{
private: 
	int size, cur;
	Data *base;
public:
	int create(void);
	int resize();
	int free();
	int append(Data d);
	int get(int, Data *d);
	Data get(void);

};

int main(void)
{
	printf("hello, word\n");
	return 0;
}

