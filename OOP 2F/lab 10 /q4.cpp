#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream file_1("info.txt", ios::out);
    if (file_1.is_open())
    {
        file_1 << "C++ is a powerful programming language.\n";
        file_1.close();

        fstream file_2("info.txt", ios::in | ios::out);

        cout << "Initial Position of Get Pointer: " << file_2.tellg() << endl;
        cout << "Initial Position of Put Pointer: " << file_2.tellp() << endl;

        // Using index 9 as powerful starts at index 9
        file_2.seekg(9, ios::beg);
        string word;
        file_2 >> word;
        cout << "Word at 9th position: " << word << endl;

        file_2.seekp(9, ios::beg);
        file_2 >> "dynamic ";
        file_2.flush();

        cout << "New Position of Get Pointer: " << file_2.tellg() << endl;
        cout << "New Position of Put Pointer: " << file_2.tellp() << endl;

        file_2.seekg(0, ios::beg);
        string content;
        getline(file_2, content);
        cout << "Updated content of the file: " << content << std::endl;

        file_2.close();
    }
    else
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }
    return 0;
}
