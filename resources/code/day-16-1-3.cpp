#include <stdio.h>

int main() {
	int i, j = 0, k = 0;
	for (i = 1; i <= 1000; ++i) {
		if (i < 10) {
			printf("%4d", i);
			++j;
		} else if (i < 100) {
			if (i / 10 == i % 10) {
				printf("%4d", i);
				++j;
			}
		} else if (i / 100 == i % 10) {
			printf("%4d", i);
			++j;
		}
		if(j % 10 == 0 && j != k) {
			printf("\n");
			k = j;
		}
	}
	printf("\n\nthere are %d palindrome numbers between %d and %d.\n", j, 1, 1000);
	return 0;
}
