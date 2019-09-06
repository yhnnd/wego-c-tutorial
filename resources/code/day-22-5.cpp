#include <stdio.h>
#include <string.h>

int main() {
	char a[101], c;
	printf("please input a string and a char\n");
	scanf("%s %c", a, &c);
	char * p = strchr(a, c);
	if (p != NULL) {
		printf("%d\n", p - a);
	} else {
		printf("\"%s\" does not contain '%c'\n", a, c);
	}
	return 0;
}

