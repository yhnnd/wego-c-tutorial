#include <stdio.h>

int * swapAndReturnMax (int * a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
	return (*a) > (*b) ? a : b;
}

int main() {
	typeof(swapAndReturnMax) * fn = swapAndReturnMax;
	int a = 1, b = 2, max;
	max = *fn(&a, &b);
	printf("a = %d\nb = %d\nmax = %d\n", a, b, max);
	return 0;
}
