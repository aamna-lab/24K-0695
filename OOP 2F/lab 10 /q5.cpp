#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream file("data.txt", ios::out);
    if (!file) {
        cout << "Could not create file.\n";
        return 1;
    }

    file << "AI is the future. AI will transform the world. Embrace AI now.";
    file.close();

    string searchWord, replaceWord;
    cout << "Enter word to search: ";
    cin >> searchWord;
    cout << "Enter word to replace with: ";
    cin >> replaceWord;

    if (replaceWord.length() > searchWord.length()) {
        cout << "Must be equal or shorter than search word.\n";
        return 1;
    }

  
    fstream data("data.txt", ios::in | ios::out);
    if (!data) {
        cout << "Could not open file.\n";
        return 1;
    }

    string word = "";
    char ch;

    while (data.get(ch)) {
        if (isalpha(ch)) {
            word += ch;
        } else {
            if (word == searchWord) {
                streampos currentPos = data.tellg();
                streampos wordStart = currentPos - (word.length() + 1);

                data.seekp(wordStart);
                data.write(replaceWord.c_str(), replaceWord.length());

                int spaceLeft = word.length() - replaceWord.length();
                for (int i = 0; i < spaceLeft; i++) {
                    data.put(' ');
                }

                data.seekg(currentPos); 
            }

            word = ""; 
        }
    }

    data.close();

    ifstream updated("data.txt");
    cout << "Updated file:\n";
    string line;
    while (getline(updated, line)) {
        cout << line << endl;
    }
    updated.close();

}
