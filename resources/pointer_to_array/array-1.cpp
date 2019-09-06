#include <stdio.h>

int main() {
    int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int (*p)[10] = &ia;
    int i;
    for (i = 0; i < sizeof(ia) / sizeof(ia[0]); ++i) {
    	printf("%d ", p[0][i]);
	}
	return 0;
}
