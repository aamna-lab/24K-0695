#include <iostream>A
#include <fstream>
using namespace std;

int main(){
    string name;
    string email;
    int yearsOfExperience;
    string summary;
    cout << "Enter your name\n" ; 
    getline(cin,name);
    cout << "Enter email\n"; 
    getline(cin,email);
    cout << "Enter your number of years of experience\n"; cin >> yearsOfExperience;
    cin.ignore();
    cout << "Enter a summary of your experience\n"; 
    getline(cin,summary);

    ofstream file;
    file.open("resume.txt", ios::trunc);

    if(!file){
        cerr << "Error : File could not be created\n";
        return 1;
    }

    file << "Name : " << name << endl;
    file << "Email : " << email << endl;
    file << "Years : " << yearsOfExperience << endl;
    file << "Summary : " << summary << endl;

    file.close();

    ifstream readFile("resume.txt");
    if(!readFile){
        cerr << "Error : File could not be opened for reading;\n";
        return 1;
    }

    string line;
    cout << "Info in file: \n";
    while (getline(readFile, line)){
        cout << line << endl;
    }

    readFile.close();

}
