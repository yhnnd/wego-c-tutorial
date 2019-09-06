#include <stdio.h>
#include <string.h>

int main() {
	char a[101], b[101];
	printf("please input a string and a substring\n");
	scanf("%s %s", a, b);
	char * p = strstr(a, b);
	if (p != NULL) {
		printf("%d\n", p - a);
	} else {
		printf("\"%s\" does not contain \"%s\"\n", a, b);
	}
	return 0;
}
