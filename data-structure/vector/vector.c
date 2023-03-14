#include "vector.h"


int ElemSize(void)
{
	return sizeof(elem);
}
int ElemComp(elem a, const elem b)
{
	return a - b;
}
void PrnElem(elem e)
{
	printf("%6d ", e);
}
vector *NewVector(int n)
{
	vector *v;
	int cap;

	v = (vector *) malloc(sizeof(vector));
	if (v == NULL)
		Exit("malloc() return NULL\n");
	if ((cap = n) < MIN_VECTOR_ELEM)
		cap = MIN_VECTOR_ELEM;
	v->data = (elem *) malloc(cap * ElemSize());
	if (v->data == NULL)
		Exit("malloc() return NULL\n");
	v->size = 0;
	v->cap = cap;
	printf("New Vector: size: %3d, cap: %3d, elem size: %3d\n", v->size, v->cap, ElemSize());
	return v;
}
vector *MakeVector(int val[], int n)
{
	int i;
	vector *v;

	v = NewVector(n);
	v->size = n;
	for (i = 0; i < n; ++i)
		v->data[i] = val[i];
	return v;
}
vector *MakeN(int n)
{
	vector *v;
	int i;

	v = NewVector(n);
	v->size = n;
	for (i = 0; i < n; ++i)
		v->data[i] = i;
	return v;
}
void Print(vector *v)
{
	int i;

	printf("--- Vector: Size: %5d, Cap: %5d ----\n", v->size, v->cap);
	for (i = 0; i < v->size; ++i)
	{
		printf("[%5d]: ", i);
		PrnElem(v->data[i]);
		printf("\n");
	}
	printf("\n");
}
vector *Realloc(vector *v, int n)
{
	elem *new_d;

	printf("Before Realloc: size: %3d, cap: %3d, elem size: %3d\n", v->size, v->cap, ElemSize());
	if (n < v->cap)
		return v;
	new_d = (elem *) realloc(v->data, n * ElemSize());
	if (new_d == NULL)
		Exit("malloc() return NULL");
	v->cap = n;
	v->data = new_d;
	printf("After Realloc: size: %3d, cap: %3d, elem size: %3d\n", v->size, v->cap, ElemSize());
	return v;
}
vector *VCopy(vector *dest, const vector *src)
{
	int i;

	if (dest->cap < src->size)
		Realloc(dest, src->size);
	for (i = 0; i < src->size; ++i)
		dest->data[i] = src->data[i];
	dest->size = src->size;
	return dest;
}
vector *VCopyN(vector *dest, const vector *src, int n)
{
	int i;

	Realloc(dest, n);
	for (i = 0; i < n; ++i)
		dest->data[i] = src->data[i];
	for ( ; i < n; ++i)
		dest->data[i] = 0;
	dest->size = n;
	return dest;
}
vector *VCat(vector *dest, const vector *src)
{
	int i;

	Realloc(dest, dest->size + src->size);
	for (i = 0; i < src->size; ++i)
		dest->data[dest->size + i] = src->data[i];
	dest->size = dest->size + src->size;
	return dest;
}
int VCamp(const vector *s, const vector *d)
{
	int i, n;
	int r;

	n = (s->size > d->size) ? d->size : s->size;
	for (i = 0; i < n; ++i)
		if ((r = ElemComp(s->data[i], d->data[i])) != 0)
			return r;
	return s->size - d->size; 
}
elem *Data(vector *v)
{
	return v->data;
}
