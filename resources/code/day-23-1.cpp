#include <stdio.h>

int main() {
	char s [101];
	FILE * fp = fopen("day-23-1.txt", "r");
	if (fp == NULL) {
		puts("file does not exist.");
	} else {
		while (fgets(s, 100, fp) != NULL) {
			printf(s);
		}
	}
	return 0;
}
