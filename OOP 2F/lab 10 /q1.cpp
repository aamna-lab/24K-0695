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
