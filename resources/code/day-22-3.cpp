#include <stdio.h>
#include <string.h>

int main() {
	char a[101] = "", b[101] = "";
	printf("please input two strings\n");
	scanf("%s %s", a, b);
	strcat(a, b);
	printf("%s\n", a);
	return 0;
}

