/*
 * ADT list
 */
#include "0head.h"

struct ADTlist
{	
	int init();
	int destroy();
	int clear();
	int empty();
	int length();
	int get();
	int locate();
	int prior();
	int next();
	int insert();
	int remove();
	int reverse();
};
typedef struct ADTlist List;
