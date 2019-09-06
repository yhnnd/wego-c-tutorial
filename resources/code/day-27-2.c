#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct array {
	int * get;
	int lengthPrev, length, size;
};

int initArray(struct array ** a, int size) {
	if(size < 1) return 0;
	*a = (struct array *) malloc(sizeof(int *) + sizeof(int) * 3);
	(*a)->get = (int *) malloc(sizeof(int) * size);
	return (*a)->size = size;
}

int setArray(struct array * a, int pos, int val) {
	while(pos + 1 > a->size) {
		a->get = (int *) realloc(a->get, sizeof(int) * a->size * 2);
		a->size *= 2;
	}
	if(a->length < pos + 1) {
		a->lengthPrev = a->length;
		a->length = pos + 1;
	}
	return a->get[pos] = val;
}

int delArray(struct array ** a) {
	free((*a)->get);
	(*a)->get = NULL;
	free((*a));
	*a = NULL;
}

int shrink_to_fit(struct array *a) {
	a->get = (int *) realloc(a->get, sizeof(int) * a->length);
	return a->size = a->length;
}

int main() {
	struct array * a;
	initArray(&a, 1);
	int i, n;
	for(i = 0, n = 1; i < 17; ++i) {
		setArray(a, i, n);
		n *= 2;
		printf("size = %2d\tlength = %2d\tget[%2d] = %-5d\n", a->size, a->length, i, a->get[i]);
	}
	shrink_to_fit(a);
	printf("size = %2d\tlength = %2d\t\n", a->size, a->length);
	for(i = 1, n = 10000; i < 8; ++i) {
		setArray(a, i*n, i*n);
		printf("size = %d\tlength = %d\tget[%d] = %-5d\n", a->size, a->length, i*n, a->get[i*n]);
	}
	delArray(&a);
	return 0;
}
