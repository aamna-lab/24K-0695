#ifndef LIBRARY
#define LIBRARY

#include <string>
#include "Book.h"

class Library{
    Book** books;
    int bookCount;

    public:
        Library(int count);

        void addBook();
        void removeBook();
        void searchBook();
};

#endif
