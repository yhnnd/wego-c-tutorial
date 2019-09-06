#include <stdio.h>
#include <math.h>

int main() {
	int a[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
	int i, len = sizeof(a) / sizeof(a[0]);
	for (i = 0; i < len; ++i) {
		printf("%d 的 %2d 次方是 %4.f\n", 2, i, pow(2,i));
	}
	return 0;
}
