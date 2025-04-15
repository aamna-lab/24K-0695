#include "Book.h"
#include "Library.h"
#include <iostream>
using namespace std;

Library::Library(int max) : maxBooks(max), bookCount(0) {
            books = new Book*[maxBooks];
        }

void Library::addBook(const Book& book) {
   if (bookCount < maxBooks) {
        books[bookCount] = book;
        bookCount++;
        cout << "Book added successfully!" << endl;
    }
    else {
        cout << "Cannot add book. Library is full!" << endl;
}

void Library::removeBook() {
    int index;
    cout << "Enter index of book to remove: ";
    cin >> index;

    if (index < 0 || index >= bookCount) {
        cout << "Invalid index!" << endl;
        return;
    }

    delete books[index];
    for (int i = index; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
    }
    bookCount--;
}

void Library::searchBook() {
    string title;
    cout << "Enter book title to search: ";
    cin >> title;

    for (int i = 0; i < bookCount; i++) {
        if (books[i]->getTitle() == title) {
            cout << "Book found: " << books[i]->getTitle() << ", " << books[i]->getAuthor() << ", " << books[i]->getISBN() << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}
