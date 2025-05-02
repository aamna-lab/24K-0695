#include <iostream>
#include <string>
using namespace std;

class FileException : public exception {
public:
    virtual const char* what() const throw() {
        return "FileException";
    }
};

class FileNotFoundException : public FileException {
public:
    const char* what() const throw() {
        return "FileNotFoundException - File not found!";
    }
};

class PermissionDeniedException : public FileException {
public:
    const char* what() const throw() {
        return "PermissionDeniedException - Access denied!";
    }
};

void readFile(const string& filename) {
    if (filename == "missing.txt") throw FileNotFoundException();
    if (filename == "secret.txt") throw PermissionDeniedException();
    cout << "Reading file: " << filename << endl;
}

int main() {
    try {
        readFile("secret.txt");
    } catch (FileException& e) {
        cout << "Reading 'secret.txt': " << e.what() << endl;
    }

    try {
        readFile("missing.txt");
    } catch (FileException& e) {
        cout << "Reading 'missing.txt': " << e.what() << endl;
    }

    return 0;
}
