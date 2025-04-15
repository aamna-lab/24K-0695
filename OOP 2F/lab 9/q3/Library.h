#ifndef LIBRARY
#define LIBRARY

#include <string>
#include "Book.h"

class Library{
    Book** books;
    int maxBooks;
    int bookCount;

    public:
        Library(int max);

        void addBook(const Book& book);
        void removeBook();
        void searchBook();
};

#endif
