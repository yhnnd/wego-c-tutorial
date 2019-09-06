#include<stdio.h>
int func(int a[], int i, int j) {
	a[i] = j;
}

int main() {
	int a[3] = {0, 0, 0};
	func(a, 1, 10);
	printf("%d, %d, %d\n", a[0], a[1], a[2]);
	return 0;
}
