#ifndef _VECTOR_HEAD_FILE_
#define _VECTOR_HEAD_FILE_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../error/error.h"

#define MIN_VECTOR_ELEM 32
typedef int elem;
struct vector
{
	int size;
	int cap;
	elem *data;
};
typedef struct vector vector;
int ElemSize(void);
int ElemComp(elem a, const elem b);
void PrnElem(elem e);

/* --------vector ---------*/
vector *NewVector(int n);
vector *VCopy(vector *dest, const vector *src);
vector *VCopyN(vector *dest, const vector *src, int n);
vector *VCat(vector *dest, const vector *src);
int VCamp(const vector *s, const vector *d);
elem *Data(vector *v);

vector *Realloc(vector *v, int n);
vector *MakeVector(int val[], int n);
vector *MakeN(int n);
void Print(vector *v);
#endif
