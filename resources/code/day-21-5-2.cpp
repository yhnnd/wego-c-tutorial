void getMinMax(int a[], int length, int ** min, int ** max) {
	*min = a, *max = a;
	int i = 0;
	for(i = 1; i < length; ++i) {
		if(a[i] > **max) {
			*max = a + i;
		} else if (a[i] < **min) {
			*min = a + i;
		}
	}
}


#include <stdio.h>

void func(int a[], int length, void (* p) (int[], int, int **, int **)) {
	int * min = NULL, * max = NULL;
	p(a, length, &min, &max);
	printf("min is %d\n", *min);
	printf("max is %d\n", *max);
}


int main() {
	int a[] = {2, 4, 1, 3};
	func(a, sizeof(a) / sizeof(a[0]), getMinMax);
	return 0;
}

