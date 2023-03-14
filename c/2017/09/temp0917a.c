/*
 * data structure stack
 */

#define STKD	double;
typedef struct stk_info
{
	STKD *top, *base;
	int size;
} stkhead;

stkhead *stkinit(int n);
int stkresize(stkhead *s, int n);
int stkpush(stkhead *s, STKD *data);
int stkpop(stkhead *s, STKD *data);
int stkgetop(stkhead *s, STKD *data);
int stkgetn(stkhead *s, STKD *data);
void stkfree(stkhead *s);
void stkreset(stkhead *s);
int stkcount(stkhead *s);
int stkmax(stkhead *s);


