#include <iostream>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    bool avail;

public:
    Book() {
        bookId = 0;
        title = "";
        author = "";
        avail = false;
    }
    Book(int id, string t, string a, bool available = true) {
        bookId = id;
        title = t;
        author = a;
        avail = available;
    }
    int getId() {
        return bookId;
    }
    bool getAvailability() {
        return avail;
    }
    string getTitle() {
        return title;
    }
    string getAuthor() {
        return author;
    }
    void setAvailability(bool availability) {
        avail = availability;
    }
    void display() {
        cout << "ID: " << getId() << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Availability (1 if Yes, 0 if No): " << getAvailability() << endl;
    }
};

class Library {
private:
    Book** books;
    int capacity;
    int num;

public:
    Library(int c) {
        capacity = c;
        num = 0;
        books = new Book*[capacity];
    }

    ~Library() {
        for (int i = 0; i < num; i++) {
            delete books[i];
        }
        delete[] books;
    }

    void addBook(int bookId, string title, string author) {
        if (num < capacity) {
            books[num] = new Book(bookId, title, author); 
            num++;
            cout << "Book added!" << endl;
        } else {
            cout << "Book cannot be added. Max Capacity has been reached" << endl;
        }
    }
    void borrow(int id) {
        for (int i = 0; i < num; i++) {
            if (books[i]->getId() == id) {
                if (books[i]->getAvailability()) {
                    cout << "Book borrowed successfully" << endl;
                    books[i]->setAvailability(false); 
                    return;
                } else {
                    cout << "Book not available" << endl;
                    return;
                }
            }
        }
        cout << "No such ID found" << endl;
    }

    void returnBook(int id) {
        for (int i = 0; i < num; i++) {
            if (books[i]->getId() == id) {
                if (!books[i]->getAvailability()) {
                    cout << "Book returned successfully" << endl;
                    books[i]->setAvailability(true); 
                    return;
                } else {
                    cout << "Book has already been returned" << endl;
                    return;
                }
            }
        }
        cout << "No such ID found" << endl;
    }

    void displayAvailableBooks() {
        cout << "\nAvailable books in the library:" << endl;
        bool found = false;
        for (int i = 0; i < num; ++i) {
            if (books[i]->getAvailability()) { 
                books[i]->display();
                found = true;
            }
        }
        if (!found) {
            cout << "No books are currently available." << endl;
        }
    }
};

int main() {
    Library library(5);
    library.addBook(1, "Heartlines", "Susannah Mc.Farlane");
    library.addBook(2, "The Plain Truth", "Jodi Picoult");
    library.addBook(3, "Scarpetta", "Ian Rankins");
    library.displayAvailableBooks();
    library.borrow(1);
    library.displayAvailableBooks();


    return 0;
}

