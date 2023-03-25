// https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum { false, true } bool;

struct book {
    char title[64];
    char author[64];
    char press[64];
};

int printPattern(const char mode, const char searchMode, const char * str, const char * pattern) {
    int j, pos;
    if (mode == searchMode && pattern != NULL) {
        printf("| %20s ", "");
        char * substr = strcasestr(str, pattern);
        if (substr != NULL) {
            pos = (int) (substr - str);
        }
        for (j = 0; j < 43; ++j) {
            if (j >= pos && j < pos + strlen(pattern)) {
                printf("^");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    return 0;
}

int printBook(const struct book * Books, const int i, const int max, bool * disableTopBorder, const char searchMode, const char * pattern) {
    const char * br = "+-----------------------------------------------------------------+";
    if (i >= 0 && i < max) {
        if (*disableTopBorder == false) {
            printf("%s\n", br);
            *disableTopBorder = true;
        }
        if (isalpha(Books[i].title[0]) || isdigit(Books[i].title[0])) {
            printf("| %-20s %-43d|\n", "book number:", i + 1);
            printf("| %-20s %-43s|\n", "book title:", Books[i].title);
            printPattern('t', searchMode, Books[i].title, pattern);
            printf("| %-20s %-43s|\n", "publishing house:", Books[i].press);
            printPattern('p', searchMode, Books[i].press, pattern);
            printf("| %-20s %-43s|\n", "author:", Books[i].author);
            printPattern('a', searchMode, Books[i].author, pattern);
        } else {
            printf("| %-20s %d\n", "book number:", i + 1);
            printf("| %-20s %s\n", "book title:", Books[i].title);
            printf("| %-20s %s\n", "publishing house:", Books[i].press);
            printf("| %-20s %s\n", "author:", Books[i].author);
        }
        printf("%s\n", br);
    } else {
        printf("book not found\n");
    }
    return i;
}

int printMenu(int max, const bool disableTopBorder) {
    const char * br = "+-----------------------------------------------------------------+";
    if (disableTopBorder == false) {
        printf("%s\n", br);
    }
    printf("| Total Books: %-51d|\n", max);
    printf("%s\n", br);
    printf("| %-64s|\n", "1.[s] search book:");
    printf("| %-64s|\n", "description: search book title/author/press/number");
    printf("| %-64s|\n", "examples: [s title Kite]  [s author Khaled]  [s 1]");
    printf("%s\n", br);
    printf("| %-64s|\n", "2.[m] modify book:");
    printf("| %-64s|\n", "description: modify book [number] title/author/press");
    printf("| %-64s|\n", "examples:");
    printf("| %-64s|\n", "[m 1 title A Thousand Splendid Suns]");
    printf("| %-64s|\n", "[m 1 press Riverhead Books]");
    printf("%s\n", br);
    printf("| %-64s|\n", "3.[a] add book:");
    printf("| %-64s|\n", "example: [a title A Thousand Splendid Suns]");
    printf("%s\n", br);
    return 0;
}

int setBook(struct book * ptr, const char * title, const char * author, const char * press) {
    memset(ptr, 0, sizeof(struct book));
    strncpy(ptr->title, title, sizeof(ptr->title));
    strncpy(ptr->author, author, sizeof(ptr->author));
    strncpy(ptr->press, press, sizeof(ptr->press));
    return 0;
}

int main() {
    const char * br = "+-----------------------------------------------------------------+";
    bool hasError = false, disableBookTopBorder = false;
    int max = 7;
    struct book *Books = (struct book *) calloc(max, sizeof(struct book));
    setBook(Books, "The Kite Runner", "Khaled Hosseini", "Bloomsbury Publishing PLC");
    setBook(Books + 1, "The Catcher in the Rye", "J. D. Salinger", "Little, Brown and Company");
    setBook(Books + 2, "C Primer Plus, 5th Edition", "Stephen Prata", "Pearson Education");
    setBook(Books + 3, "A Thousand Splendid Suns", "Khaled Hosseini", "Riverhead Books");
    setBook(Books + 4, "ナミヤ雑貨店の奇蹟", "東野 圭吾", "角川書店");
    setBook(Books + 5, "Namiya Zakkaten no Kiseki", "Keigo Higashino", "Kadokawa Shoten");
    setBook(Books + 6, "半落ち", "横山秀夫", "講談社");
    struct book * ptr = NULL;
    int i;
    char cmd[128], seg[3][64], rest[64], mode, cmdtrim[128];
    for (;;) {
        printMenu(max, disableBookTopBorder);
        printf("command:");
        memset(cmd, 0, sizeof(cmd));
        fgets(cmd, 128, stdin);
        memset(cmdtrim, 0, sizeof(cmdtrim));
        sscanf(cmd, "%128[^\n]", cmdtrim);
        memset(seg, 0, sizeof(seg));
        memset(rest, 0, sizeof(rest));
        sscanf(cmdtrim, "%s %s %s %128[^\n]", seg[0], seg[1], seg[2], rest);
        disableBookTopBorder = false;
        switch (seg[0][0]) {
            case '1':
            case 's':
                mode = 0;
                if (isalpha(seg[1][0])) {
                    mode = seg[1][0];
                } else if (seg[1][0] == '*') {
                    if (strlen(seg[2]) == 0) {
                        for (i = 0; i < max; ++i) {
                            printBook(Books, i, max, &disableBookTopBorder, 0, NULL);
                        }
                        break;
                    }
                } else if (!isdigit(seg[1][0])) {
                    printf("%s\n| %46s %-16s |\n", br, "unknown command", cmdtrim);
                    hasError = true;
                    break;
                }
                if (strlen(rest) > 0) {
                    strcat(seg[2], " ");
                    strncat(seg[2], rest, sizeof(rest));
                }
                if (mode == 'n') {
                    if (atoi(seg[2]) > 0 && atoi(seg[2]) <= max) {
                        printBook(Books, atoi(seg[2]) - 1, max, &disableBookTopBorder, 0, NULL);
                    } else {
                        printf("%s\n| %-64s|\n", br, "book number out of limit");
                    }
                } else if (atoi(seg[1]) > 0 && atoi(seg[1]) <= max) {
                    if (atoi(seg[1]) > 0 && atoi(seg[1]) <= max) {
                        printBook(Books, atoi(seg[1]) - 1, max, &disableBookTopBorder, 0, NULL);
                    } else {
                        printf("%s\n| %-64s|\n", br, "book number out of limit");
                    }
                } else if (mode != 0 && strlen(seg[2]) > 0 && strchr("tap", mode) != NULL) {
                    for (i = 0; i < max; ++i) {
                        if (mode == 't' && strcasestr(Books[i].title, seg[2]) != NULL) {
                            printBook(Books, i, max, &disableBookTopBorder, mode, seg[2]);
                        } else if (mode == 'a' && strcasestr(Books[i].author, seg[2]) != NULL) {
                            printBook(Books, i, max, &disableBookTopBorder, mode, seg[2]);
                        } else if (mode == 'p' && strcasestr(Books[i].press, seg[2]) != NULL) {
                            printBook(Books, i, max, &disableBookTopBorder, mode, seg[2]);
                        }
                    }
                    if (disableBookTopBorder == false) {
                        printf("%s\n| %-14s %s - %c, %s: %-30s|\n", br, "no result.", "mode", mode, "pattern", seg[2]);
                    }
                } else if (seg[1][0] == '*' || isalpha(mode)) {
                    if (seg[1][0] == '*') {
                        memset(seg[1], 0, sizeof(seg[1]));
                        if (strlen(seg[2]) > 0) {
                            strncpy(seg[1], seg[2], sizeof(seg[1]));
                        }
                    } else if (strlen(seg[2]) > 0) {
                        strcat(seg[1], " ");
                        strncat(seg[1], seg[2], sizeof(seg[2]));
                    }
                    for (i = 0; i < max; ++i) {
                        if (strcasestr(Books[i].title, seg[1]) != NULL) {
                            printBook(Books, i, max, &disableBookTopBorder, 't', seg[1]);
                        } else if (strcasestr(Books[i].author, seg[1]) != NULL) {
                            printBook(Books, i, max, &disableBookTopBorder, 'a', seg[1]);
                        } else if (strcasestr(Books[i].press, seg[1]) != NULL) {
                            printBook(Books, i, max, &disableBookTopBorder, 'p', seg[1]);
                        }
                    }
                    if (disableBookTopBorder == false) {
                        printf("%s\n| %-14s %s - %c, %s: %-30s|\n", br, "no result.", "mode", '*', "pattern", seg[1]);
                    }
                } else {
                    printf("%s\n| %46s %-16s |\n", br, "unknown command", cmdtrim);
                    hasError = true;
                }
                break;
            case '2':
            case 'm':
                i = atoi(seg[1]);
                if (i > 0 && i <= max) {
                    ptr = Books + i - 1;
                    switch (seg[2][0]) {
                        case 't':
                            strncpy(ptr->title, rest, sizeof(ptr->title));
                            break;
                        case 'a':
                            strncpy(ptr->author, rest, sizeof(ptr->author));
                            break;
                        case 'p':
                            strncpy(ptr->press, rest, sizeof(ptr->press));
                            break;
                        default:
                            printf("%s\n| %46s %-16s |\n", br, "unknown command", cmdtrim);
                            hasError = true;
                    }
                    if (hasError == false) {
                        printBook(Books, i - 1, max, &disableBookTopBorder, 0, NULL);
                    }
                } else {
                    printf("%s\n| %-64s|\n", br, "book number out of limit");
                }
                break;
            case '3':
            case 'a':
                if (strlen(rest) > 0) {
                    strcat(seg[2], " ");
                    strncat(seg[2], rest, sizeof(rest));
                }
                Books = (struct book *) realloc(Books, ++max * sizeof(struct book));
                ptr = Books + max - 1;
                switch (seg[1][0]) {
                    case 't':
                        strncpy(ptr->title, seg[2], sizeof(ptr->title));
                        break;
                    case 'a':
                        strncpy(ptr->author, seg[2], sizeof(ptr->author));
                        break;
                    case 'p':
                        strncpy(ptr->press, seg[2], sizeof(ptr->press));
                        break;
                    default:
                        if (strlen(seg[2]) > 0) {
                            strcat(seg[1], " ");
                            strncat(seg[1], seg[2], sizeof(seg[2]));
                        }
                        strncpy(ptr->title, seg[1], sizeof(ptr->title));
                }
                printBook(Books, max - 1, max, &disableBookTopBorder, 0, NULL);
                break;
            default:
                printf("%s\n| %46s %-16s |\n", br, "unknown command", cmdtrim);
                hasError = true;
        }
        if (hasError) {
            printf("%s", br);
            break;
        } else {
            disableBookTopBorder = true;
            printf("|%64s |\n", "Press [ENTER]");
            printf("%s", br);
            char c = getchar();
            if (c != '\n') {
                while ((c = getchar()) != '\n' && c != EOF) {
                    continue;// discard extra characters
                }
            }
        }
    }
    free(Books);
    return 0;
}