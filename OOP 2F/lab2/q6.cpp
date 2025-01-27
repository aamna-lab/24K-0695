#include <iostream>
using namespace std;

 struct Register{
    int courseID;
    string courseName;
  };

struct Student{
     struct Register r;
     string studentID;
     string firstName;
     string lastName;
     int cellNo;
     string email;
};

int main() {
    struct Student s[5];
    for(int i=0;i<5;i++){
        cout << "Enter course ID for student " << i+1 << endl;
        cin >> s[i].r.courseID;
        cout << "Enter course Name for student " << i+1 <<endl;
        cin >> s[i].r.courseName;
        cout << "Enter student ID for student " <<  i+1 << endl;
        cin >> s[i].studentID;
        cout << "Enter first name for student  " << i+1 <<  endl;
        cin >> s[i].firstName;
        cout << "Enter last name for student " << i+1 << endl;
        cin >> s[i].lastName;
          cout << "Enter email for student " <<  i+1 <<endl;
        cin >> s[i].email;
          cout << "Enter cell num for student " << i+1 << endl;
        cin >> s[i].cellNo;
    }
    for(int i =0;i<5;i++){
        cout << "Data for Student " << i+1 << endl;
        cout << "First Name : " << s[i].firstName << endl;
        cout << "Last Name : " << s[i].lastName << endl;
        cout << "Student Id : " << s[i].studentID << endl;
        cout << "email: " << s[i].email << endl;
        cout << "Cell Num : " << s[i].cellNo << endl;
        cout << "Course ID : " << s[i].r.courseID << endl;
        cout << "Course Name : " << s[i].r.courseName << endl << endl<< endl;
    }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
    
}
