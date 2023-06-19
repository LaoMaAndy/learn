/* mem.c */
#include <stdio.h>

int g = 0;
int main() {
	int l;
	static int s = 0;
	printf("globel var address: %p\n", &g);
	printf("static var address: %p\n", &s);
	printf("local  var address: %p\n", &l);

	return 0;
}

