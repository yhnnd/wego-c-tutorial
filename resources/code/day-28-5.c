#include <stdio.h>

typedef int * (* funcType) (int *, int *);

int * swapAndReturnMax (int * a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
	return (*a) > (*b) ? a : b;
}

int * justReturnMax (int * a, int * b) {
	return (*a) > (*b) ? a : b;
}

int main() {
	funcType fn = swapAndReturnMax;
	int a = 1, b = 2, max;
	max = *fn(&a, &b);
	printf("a = %d\nb = %d\nmax = %d\n", a, b, max);
	fn = justReturnMax;
	printf("\na = %d\nb = %d\nmax = %d\n", a, b, max);
	return 0;
}
