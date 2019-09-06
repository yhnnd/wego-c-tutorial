#include <stdio.h>

int main(int argc, char ** argv) {
	if (argc == 10) {
		printf("\n%28s","九九乘法表");
	} else if (argc % 10 == 1 || argc <= 11) {
	} else {
		if (argc % 10 == 2) printf("|");
		if (argc <= 20) {
			printf("%4d|", (argc - 1) % 10);// 打印第一行
		} else {
			if (argc % 10 == 0) {
				printf("%4d|", (argc/10 - 1) * ((argc-1) % 10));// 打印右数第一列
			} else {
				printf("%4d|", (argc/10) * ((argc-1) % 10));
			}
		}
	}
	if (argc % 10 == 0) {
		printf("\n+----+----+----+----+----+----+----+----+----+\n");
	}
	if (argc == 100) {
		return 0;
	}
	return main(++argc, argv);
}
