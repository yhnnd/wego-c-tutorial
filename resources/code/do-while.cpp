#include <stdio.h>

int main() {
	int n = 1;
	do {
		printf("%2d ֻ���� %2d ����, %2d ֻ�۾� %2d ���ȡ�\n", n, n, n * 2, n * 4);
		n++;
	} while (n <= 10);
	return 0;
}
