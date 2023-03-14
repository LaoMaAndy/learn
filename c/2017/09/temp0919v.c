#include <stdlib.h>

#define VECD double
typedef struct vec_info
{
	VCTD *base, *top;
	int size;
} vechead;

vechead *vecinit(int n);
int vecresize(vechead *p, int n);
int vecap(vechead *v, VECD d);
int vecget(vechead *v, VECD *dp);
int vecgetn(vechead *v, VECD *dp, int n);
int vecupd(vechead *v, VECD d, int n);
int vecins(vechead *v, VECD d, int n);
int vecdel(vechead *v, VECD d, int n);
void vecfree(vechead *p);
void vecreset(vechead *p);
int veccount(vechead *p);
int vecmax(vechead *p);


