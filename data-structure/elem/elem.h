#ifndef _ELEM_HEAD_FILE_
#define _ELEM_HEAD_FILE_
/* elem data type and basic function */
struct elem;
typedef struct elem elem;
typedef elem *elem_ptr;

/* user who defined elem type, must implement these functions */
elem *ElemNew(void);
void ElemFree(elem *p);
int  ElemComp(const elem *x, const elem *y);
elem *ElemCopy(elem *dest, const elem *src);
void ElemPrn(const elem *e);
int ElemSize();

int ElemIndex(elem *e);
int ElemVal(elem *e);
elem *SetElemIndex(elem *e, int i);
elem *SetElemVal(elem *e, int v);

elem *MakeElem(int i, int v, const char *str, const char *def);
elem_ptr *MakeElems(int index[], int value[], int n);

#endif