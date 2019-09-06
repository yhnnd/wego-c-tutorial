#include <stdio.h>

enum weekday {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

int main() {
	enum weekday weekday;
	for (weekday = Monday; weekday <= Sunday; ++weekday) {
		switch (weekday) {
			case Monday:
				printf("%d Monday", weekday);
				break;
			case Tuesday:
				printf("%d Tuesday", weekday);
				break;
			case Wednesday:
				printf("%d Wednesday", weekday);
				break;
			case Thursday:
				printf("%d Thursday", weekday);
				break;
			case Friday:
				printf("%d Friday", weekday);
				break;
			case Saturday:
				printf("%d Saturday", weekday);
				break;
			case Sunday:
				printf("%d Sunday", weekday);
				break;
			default:
				printf("%d Error", weekday);
				break;
		}
		if (weekday != Sunday) {
			printf("\n");
		} else {
			break;
		}
	}
	return 0;
}
