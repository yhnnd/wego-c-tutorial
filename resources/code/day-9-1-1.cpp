#include <stdio.h>

int main() {
	int a = 1000000000;
	unsigned int b = 1000000000;
	long c = 1000000000;
	long long d = 1000000000000000000;
	unsigned long long e = 1000000000000000000;

	printf("int a                = %20d;\n", a);
	printf("unsigned b           = %20u;\n", b);
	printf("long c               = %20ld;\n", c);
	printf("long long d          = %20lld;\n", d);
	printf("unsigned long long e = %20llu;\n", e);
	return 0;
}
