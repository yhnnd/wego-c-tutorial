#include <stdio.h>

int main() {
	float a = 3.141592653;
	double b = 3.141592653;
	long double c = 3.141592653;
	char hashTag = '#';
	char str[] = "I am a string";

	printf("float a       = %f;\n", a);
	printf("double b      = %lf;\n", b);
	printf("long double c = %Lf;\n", c);
	printf("char hashTag  = \'%c\';\n", hashTag);
	printf("char str[]    = \"%s\";\n", str);
	return 0;
}
