#include <stdio.h>

enum enumType {
    enumValue
};

int main() {
	enum enumType a = enumValue;
	int b = enumValue;
	printf("%s\n", a == b ? "true" : "false");
	return 0;
}
