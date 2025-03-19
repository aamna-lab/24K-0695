#include <iostream>
using namespace std;

class Media {
protected:
    string title;
    int publicationDate;
    string uniqueID;
    string publisher;
    bool isCheckedOut;

public:
    Media(string t, int pubDate, string id, string pub) : 
        title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out.\n";
        } else {
            cout << title << " is already checked out.\n";
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned.\n";
        } else {
            cout << title << " was not checked out.\n";
        }
    }

    string getTitle() { return title; }
    int getPublicationDate() { return publicationDate; }
};

class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string t, int pubDate, string id, string pub, string auth, string isbn, int pages) :
        Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director;
    int duration;
    float rating;

public:
    DVD(string t, int pubDate, string id, string pub, string dir, int dur, float rate) :
        Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << "/10" << endl;
    }
};

class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, int pubDate, string id, string pub, string art, int tracks, string gen) :
        Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Library {
private:
    Media* collection[50];
    int itemCount;

public:
    Library() : itemCount(0) {}

    void addMedia(Media* media) {
        if (itemCount < 50) {
            collection[itemCount++] = media;
            cout << "Media added to the library.\n";
        } else {
            cout << "Library is full! Cannot add more media.\n";
        }
    }

    void searchMedia(string title) {
        cout << "Searching for title: " << title << endl;
        for (int i = 0; i < itemCount; i++) {
            if (collection[i]->getTitle() == title) {
                collection[i]->displayInfo();
                return;
            }
        }
        cout << "No media found with the title: " << title << endl;
    }

    void searchMedia(int publicationYear) {
        cout << "Searching for media published in year: " << publicationYear << endl;
        for (int i = 0; i < itemCount; i++) {
            if (collection[i]->getPublicationDate() == publicationYear) {
                collection[i]->displayInfo();
            }
        }
    }
};

int main() {
    Library library;
    Book book1("C++ Programming", 2022, "B001", "Pearson", "Bjarne Stroustrup", "123456789", 500);
    DVD dvd1("Inception", 2010, "D001", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD cd1("Thriller", 1982, "C001", "Epic Records", "Michael Jackson", 9, "Pop");
    library.addMedia(&book1);
    library.addMedia(&dvd1);
    library.addMedia(&cd1);
    cout << "\n--- Library Collection ---\n";
    book1.displayInfo();
    dvd1.displayInfo();
    cd1.displayInfo();
    book1.checkOut();
    book1.returnItem();
    cout << "\n--- Searching for Media ---\n";
    library.searchMedia("C++ Programming");
    library.searchMedia(2010);

}

