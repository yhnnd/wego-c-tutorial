#include <stdio.h>

#define size 2

typedef int Int;
typedef Int IntArr [size];
typedef IntArr IntArr2d [size];
typedef IntArr2d IntArr3d [size];

int main() {
	int c = 0;
	IntArr3d a = {
		{
			{1, 2},
			{3, 4},
		},
		{
			{5, 6},
			{7, 8},
		}
	};
	for (int i = 0; i < 2; ++i) {
		printf(" %s\n","------");
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				printf("%3d", a[i][j][k]);
			}
			printf("\n");
		}
	}
	return 0;
}
