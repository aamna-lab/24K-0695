
#ifndef BOOK
#define BOOK

#include <string>
using namespace std;
class Book{
    string title;
    string author;
    string ISBN;

    public:
    Book(string t, string a, string isbn);

    string getTtile();
    string getAuthor();
    string getISBN();

};

#endif
