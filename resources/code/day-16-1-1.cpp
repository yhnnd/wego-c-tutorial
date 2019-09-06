#include <stdio.h>

int main() {
	int a, b;
	for (a = 1; a < 26; ++a) {
		for (b = 1; b < 26; ++b) {
			if (a * b % 26 == 1) {
				printf("%2d 的逆为 %2d，\t%2d 可以被选作密匙。\n", a, b, a);
			}
		}
	}
	return 0;
}
