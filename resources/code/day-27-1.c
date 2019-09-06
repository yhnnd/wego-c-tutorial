#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char * a;
	a = (char *) malloc(sizeof(char) * 64);
	strcpy(a, "All Men Are Created Equal.");
	printf("%s\n", a);
	free(a);
	a = NULL;
	return 0;
}
