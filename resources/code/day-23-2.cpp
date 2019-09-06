#include <stdio.h>

int main() {
	char c;
	FILE * fp = fopen("day-23-1.txt", "r");
	if (fp == NULL) {
		puts("file does not exist.");
	} else {
		while ((c = fgetc(fp)) != EOF) {
			putchar(c);
		}
	}
	return 0;
}

