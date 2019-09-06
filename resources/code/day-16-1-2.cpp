#include <stdio.h>
#define cube(a) ((a) * (a) * (a))

int main() {
	int n, a, b, c;
	for (n = 100; n < 1000; ++n) {
		a = n / 100;
		b = n % 100 / 10;
		c = n % 10;
		if (cube(a) + cube(b) + cube(c) == n) {
			printf("%d\n", n);
		}
	}
	return 0;
}
