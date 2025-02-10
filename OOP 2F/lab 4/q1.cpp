#include <iostream>
using namespace std;
class Student {
private:
    int studentId;
    string name;
    int age;
    char grade; 
public:
    Student() {
        studentId = 0;
        age = 0;
        grade = 'N'; 
        name = "";
    }
    Student(int id, int age1, char grade1, string n) {
        studentId = id;
        age = age1;
        grade = grade1;
        name = n;
    }
    int getAge() {
        return age;
    }
    string getName() {
        return name;
    }
    char getGrade() {
        return grade;
    }
    int getId() {
        return studentId;
    }
    void isEligibleForScholarship() {
        if (grade == 'A') {
            cout << "Eligible for Scholarship" << endl;
        } else {
            cout << "Not Eligible for Scholarship" << endl;
        }
    }
    void displayDetails() {
        cout << "Name: " << getName() << endl;
        cout << "Student Id: " << getId() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Grade: " << getGrade() << endl;
    }
};

int main() {
    Student object(240695, 18, 'A', "Aamna");
    object.displayDetails();
    object.isEligibleForScholarship();

}

