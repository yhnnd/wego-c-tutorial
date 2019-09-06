#include <stdio.h>

int main() {
	int a = 1;
	typeof(a)* pa = &a;// typeof(a)* => int*
	typeof(a) b = a * 4;// typeof(a) => int
	typeof(b)* pb = &b;// typeof(b)* => int*
	printf("val(%p) = %d\n", &a, a);
	printf("val(%p) = %d\n", pa, *pa);
	printf("val(%p) = %d\n", &b, b);
	printf("val(%p) = %d\n", pb, *pb);
	return 0;
}
