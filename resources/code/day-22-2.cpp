#include <stdio.h>
#include <string.h>

int main() {
	char a[101], b[101] = "";
	printf("please input a string (no more than 100 chars)\na = ");
	scanf("%s", a);
	strcpy(b, a);
	printf("b = %s\n", b);
	return 0;
}
