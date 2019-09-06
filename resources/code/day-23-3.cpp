#include <stdio.h>
#include <string.h>

int main() {
	char s [101];
	FILE * fp = fopen("day-23-1.txt", "r");
	if (fp == NULL) {
		puts("file does not exist.");
	} else {
		int letterCount = 0, lineCount = 0, lineCountPrev = 0;
		while (fscanf(fp, "%s", s) == 1) {
			printf("%s", s);
			letterCount += strlen(s) + 1;
			lineCount = letterCount / 42;
			if (lineCount != lineCountPrev) {
				printf("\n");
				lineCountPrev = lineCount;
			} else {
				printf(" ");
			}
		}
	}
	return 0;
}
