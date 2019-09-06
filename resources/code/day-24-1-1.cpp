#include <stdio.h>
#include <string.h>

struct book {
	char title[64];
	char author[32];
	char press[32];
};

int main() {
	struct book Books[3] = {
		{"The Kite Runner", "Khaled Hosseini", "Bloomsbury Publishing PLC"},
		{"The Catcher in the Rye", "J. D. Salinger", "Little, Brown and Company"},
		{"C Primer Plus, 5th Edition", "Stephen Prata", "Pearson Education"}
	};
	int i;
	while (true) {
		printf("book number(1-3): ");
		scanf(" %d", &i);
		if (--i >= 0 && i < sizeof(Books)/sizeof(Books[0])) {
			printf("%-20s %s\n", "book title:", Books[i].title);
			printf("%-20s %s\n", "publishing house:", Books[i].press);
			printf("%-20s %s\n", "author:", Books[i].author);
		} else {
			printf("out of limit\n");
			break;
		}
	}
	return 0;
}
