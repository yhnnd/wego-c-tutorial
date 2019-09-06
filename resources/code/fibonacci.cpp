#include <stdio.h>

int Fibonacci(int n) {
	if (n == 1 || n == 2) return 1;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
	int n;
	for (n = 1; n <= 40; ++n) {
		printf(" %10d", Fibonacci(n));
		if (n % 10 == 0) printf("\n");
	}
	return 0;
}
