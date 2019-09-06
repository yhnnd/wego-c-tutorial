#include <stdio.h>

int main() {
	int n = 1;
	do {
		printf("%2d 只青蛙 %2d 张嘴, %2d 只眼睛 %2d 条腿。\n", n, n, n * 2, n * 4);
		n++;
	} while (n <= 10);
	return 0;
}
