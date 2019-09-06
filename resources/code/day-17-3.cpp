#include <stdio.h>

int main() {
	int n = 10, a;
	for (a = 1; a <= 100; ++a) {
		if (a / 10 == 7 || a % 10 == 7 || a % 7 == 0) {
			printf("%4s", "#");
			if (a % n == 0) printf("\n");
			continue;
		}
		printf("%4d", a);
		if (a % n == 0) printf("\n");
	}
	return 0;
}
