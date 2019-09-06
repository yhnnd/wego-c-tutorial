
#include <stdio.h>

void printLength(int n) {
	printf("数组长度是 %d\n", n);
}

int main() {
	int a[3] = {0, 0, 0};
	void (* p) (int) = printLength;
	p(sizeof(a) / sizeof(a[0]));
	return 0;
}
