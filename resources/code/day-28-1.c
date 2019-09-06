#include <stdio.h>

typedef int Integer;

int main() {
	Integer a = 1;
	Integer * pa = &a;
	Integer b = a * 4;
	Integer * pb = &b;
	printf("val(%p) = %d\n", &a, a);
	printf("val(%p) = %d\n", pa, *pa);
	printf("val(%p) = %d\n", &b, b);
	printf("val(%p) = %d\n", pb, *pb);
	return 0;
}
