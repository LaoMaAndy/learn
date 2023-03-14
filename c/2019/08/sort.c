/*
   sort.c
   */
#include "template/head.h"

//int main() {
//	printf("This is ok\n");
//	return 0;
//}
//
void swap(int v[], int i, int j) {
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void quicksort(int v[], int left, int right) {
	int i, last;

	if (left >= right)
		return;
	last = left + (right - left) / 2;
	swap(v, left, last);
	for (i = left; i < 


