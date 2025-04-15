#include "Book.h"
#include "Library.h"
#include <iostream>
using namespace std;

Library::Library(int count) : bookCount(count) {
            books = new Book*[bookCount];
        }

void Library::addBook() {
    string title, author, isbn;
    cout << "Enter book title: ";
    cin >> title;
    cout << "Enter book author: ";
    cin >> author;
    cout << "Enter book ISBN: ";
    cin >> isbn;

    books[bookCount] = new Book(title, author, isbn);
    bookCount++;
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
        if (books[i]->getTtile() == title) {
            cout << "Book found: " << books[i]->getTtile() << ", " << books[i]->getAuthor() << ", " << books[i]->getISBN() << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}
