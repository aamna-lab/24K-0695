#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn) {}

string Book::getTtile() {
    return title;
}

string Book::getAuthor(){
    return author;
}

string Book::getISBN(){
    return ISBN;
}
