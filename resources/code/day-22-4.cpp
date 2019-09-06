#include <stdio.h>
#include <string.h>

int main() {
	char a[101] = "", b[101] = "";
	printf("please input two strings\n");
	scanf("%s %s", a, b);
	printf("%d\n", strcmp(a, b));
	return 0;
}
