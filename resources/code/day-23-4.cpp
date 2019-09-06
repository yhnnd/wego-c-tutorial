#include <stdio.h>
#include <string.h>

int main() {
	char s[] = "From fairest creatures we desire increase,\n\
That thereby beauty's rose might never die,\n\
But as the riper should by time decease,\n\
His tender heir might bear his memory";
	FILE * fp = stdout;
	if (fp == NULL) {
		puts("file does not exist.");
	} else {
		for(int i = 0, len = strlen(s); i < len; ++i) {
			putc(s[i], fp);
		}
	}
	return 0;
}
