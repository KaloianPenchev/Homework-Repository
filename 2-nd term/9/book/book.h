#ifndef BOOK_H_
#define BOOK_H_

#define MAX_NAME_LENGTH 30
#define MAX_AUTHOR_LENGTH 30
#define MAX_GENRE_LENGTH 20
#define MAX_ISBN_LENGTH 13

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char author[MAX_AUTHOR_LENGTH + 1];
    char genre[MAX_GENRE_LENGTH + 1];
    int year_of_publication;
    char isbn[MAX_ISBN_LENGTH + 1];
} Book;

#endif