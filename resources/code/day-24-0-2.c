#include <stdio.h>
#include <string.h>

typedef struct {
	char title[64];
	char author[32];
	char press[32];
} book;

int main() {
	book Book;
	strcpy(Book.title, "The Kite Runner");
	strcpy(Book.press, "Bloomsbury Publishing PLC");
	strcpy(Book.author, "Khaled Hosseini");
	printf("%-20s %s\n", "book title:", Book.title);
	printf("%-20s %s\n", "publishing house:", Book.press);
	printf("%-20s %s\n", "author:", Book.author);
	return 0;
}
