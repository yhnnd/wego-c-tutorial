#include <stdio.h>
#include <string.h>

int main() {
	char a[101], b[101];
	printf("please input two strings\n");
	scanf("%s %s", a, b);
	char * p = strpbrk(a, b);
	if (p != NULL) {
		printf("%d\n", p - a);
	} else {
		printf("\"%s\" does not contain any char in \"%s\"\n", a, b);
	}
	return 0;
}

