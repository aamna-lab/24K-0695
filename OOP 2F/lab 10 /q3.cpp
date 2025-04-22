
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream createChapter1("chapter1.txt");
    createChapter1 << "Chapter 1: The World\n";
    createChapter1 << "Story started\n";
    createChapter1 << "Earth was the world\n";
    createChapter1.close();

    
    ofstream createChapter2("chapter2.txt");
    createChapter2 << "Chapter 2: The Universe\n";
    createChapter2 << "2nd chapter started\n";
    createChapter2 << "Earth was in the universe\n";
    createChapter2.close();

   
    ifstream chapter1("chapter1.txt");
    ifstream chapter2("chapter2.txt");
    ofstream book("book.txt", ios::app);
    
    if(!chapter1.is_open() || !chapter2.is_open() || !book.is_open()) {
        cerr << "Error : File could not be opened" << endl;
        return 1;
    }

    string line;
    while (getline(chapter1, line)) {
        book << line << "\n";
    }
 
    while (getline(chapter2, line)) {  
        book << line << "\n";  
    }
    
    chapter1.close();
    chapter2.close();
    book.close();

    ifstream verify("book.txt");
    cout << "Contents of book.txt:\n";
    while (getline(verify, line)) {
        cout << line << endl;
    }
    verify.close();

    return 0;
}
