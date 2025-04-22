#include <iostream>
#include <fstream>
using namespace std;

struct Student{
    int id;
    string name;
    float gpa;
};

int main(){
    Student students[5];

    ofstream studentsFile("students.txt", ios::out);
    if(!studentsFile){
        cout << "Error opening file for writing." << endl;
        return 1;
    }

    for(int i = 0; i < 5; i++){
        cout << "Enter details for student " << (i + 1) << endl;
        cout << "ID: ";
        cin >> students[i].id;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "GPA: ";
        cin >> students[i].gpa;

        studentsFile << students[i].id << " " << students[i].name << " " << students[i].gpa << endl;
        cout << endl;
    }
    studentsFile.close();

    Student newStudent;
    cout << "Enter details for the additional student" << endl;
    cout << "ID: ";
    cin >> newStudent.id;
    cout << "Name: ";
    cin >> newStudent.name;
    cout << "GPA: ";
    cin >> newStudent.gpa;

    studentsFile.open("students.txt", ios::app);
    if(!studentsFile){
        cout << "Error opening file for appending." << endl;
        return 1;
    }
    studentsFile << newStudent.id << " " << newStudent.name << " " << newStudent.gpa << endl;
    studentsFile.close();

    ifstream readFile("students.txt", ios::in);
    if(!readFile){
        cout << "Error opening file for reading." << endl;
        return 1;
    }

    cout <<"Existing records of all students: \n";
    Student tempStudent;

    while(readFile >> tempStudent.id >> tempStudent.name >> tempStudent.gpa){
        cout << "ID: " << tempStudent.id << " Name: " << tempStudent.name << " GPA: " << tempStudent.gpa << endl;
    }
    readFile.close();
}

















//approach 2 searching from start end and middle of the file 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    float gpa;
};

int main() {
    Student students[5];

    ofstream studentsFile("students.txt", ios::out);
    if (!studentsFile) return 1;

    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details for student " << (i + 1) << endl;

        cout << "ID: ";
        getline(cin, students[i].id);

        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "GPA: ";
        while (!(cin >> students[i].gpa)) {
            cout << "Invalid GPA. Enter a number: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore();

        studentsFile << students[i].id << " " << students[i].name << " " << students[i].gpa << endl;
    }
    studentsFile.close();

    Student newStudent;
    cout << "\nEnter details for the additional student" << endl;

    cout << "ID: ";
    getline(cin, newStudent.id);

    cout << "Name: ";
    getline(cin, newStudent.name);

    cout << "GPA: ";
    while (!(cin >> newStudent.gpa)) {
        cout << "Invalid GPA. Enter a number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore();

    studentsFile.open("students.txt", ios::app);
    if (!studentsFile) return 1;
    studentsFile << newStudent.id << " " << newStudent.name << " " << newStudent.gpa << endl;
    studentsFile.close();

    ifstream readFile("students.txt");
    if (!readFile) return 1;

    int count = 0;
    string line;
    while (getline(readFile, line)) {
        count++;
    }
    readFile.close();

    if (count == 0) return 0;

    int firstIndex = 0;
    int midIndex = count / 2;
    int lastIndex = count - 1;

    readFile.open("students.txt");
    Student temp;
    int currentLine = 0;

    cout << "\nReading specific students:\n";

    while (readFile >> temp.id >> temp.name >> temp.gpa) {
        if (currentLine == firstIndex) {
            cout << "\nFrom Start:\nID: " << temp.id << "\tName: " << temp.name << "\tGPA: " << temp.gpa << endl;
        }
        if (currentLine == midIndex) {
            cout << "\nFrom Middle:\nID: " << temp.id << "\tName: " << temp.name << "\tGPA: " << temp.gpa << endl;
        }
        if (currentLine == lastIndex) {
            cout << "\nFrom End:\nID: " << temp.id << "\tName: " << temp.name << "\tGPA: " << temp.gpa << endl;
        }
        currentLine++;
    }

    readFile.close();
    return 0;
}
