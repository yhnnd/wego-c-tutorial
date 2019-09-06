#include <stdio.h>

int main() {
	int a = 0;
	short b = 0;
	long c = 0;
	float d = 0;
	double e = 0;
	scanf("%d %hd %ld %f %lf", &a, &b, &c, &d, &e);
	printf("%d %hd %ld %f %lf", a, b, c, d, e);
	return 0;
}
