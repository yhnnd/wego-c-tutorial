#include <stdio.h>
#define SIZE 50

int fab(int n, int m[]) {
	if (m[n]) {
		return m[n];
	} else {
		m[n] = fab(n - 1, m) + fab(n - 2, m);
		return m[n];
	}
}

int memFab(int n) {
	int m[SIZE];
	int i;
	m[0] = 1;
	m[1] = 1;
	for(i = 2; i < SIZE; ++i) {
		m[i] = 0;
	}
	return fab(n, m);
}

int main() {
	int n;
	for (n = 1; n <= 40; ++n) {
		printf(" %10d", memFab(n));
		if (n % 10 == 0) printf("\n");
	}
	return 0;
}
