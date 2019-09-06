#include <stdio.h>

#define size 2

typedef int Int;
typedef Int IntArr [size];
typedef IntArr IntArr2d [size];

#define defIntArr(a,n) Int a [n]
#define defIntArr2d(a,m,n) defIntArr(a,m) [n]

int main() {
	int c = 0;
	printf("c = %d\nd = %d\n", c, (
	({
		(
		    c += printf("Do you "),
		    c += printf("really know ")
		);
	}),
	({
		c += printf("C programming?\n");
	}),
	({
		IntArr2d a [size] = {
			{
				{1, 2},
				{3, 4},
			},
			{
				{5, 6},
				{7, 8},
			}
		};
		defIntArr2d(b,2,2)[2] = {
			{
				{10, 20},
				{30, 40},
			},
			{
				{50, 60},
				{70, 80},
			}
		};
		int sum = 0;
		for (int r = 0; r < 3; ++r) {
			for (int i = 0; i < 2; ++i) {
				printf(" %s\n","------");
				if (r == 2) break;
				for (int j = 0; j < 2; ++j) {
					for (int k = 0; k < 2; ++k) {
						Int t = (r == 0 ? a : b)[i][j][k];
						printf("%3d", t);
						sum += t;
					}
					printf("\n");
				}
			}
		}
		sum;
	})));
	return 0;
}
