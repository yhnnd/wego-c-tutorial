#include <stdio.h>

int main() {
	char s[][64] = {
		"From fairest creatures we desire increase,",
		"That thereby beauty's rose might never die,",
		"But as the riper should by time decease,",
		"His tender heir might bear his memory"
	};
	FILE * fp = stdout;
	if (fp == NULL) {
		puts("file does not exist.");
	} else {
		for(int i = 0; i < sizeof(s)/sizeof(s[0]); ++i) {
			fprintf(fp, "%s\n", s[i]);
		}
	}
	return 0;
}
