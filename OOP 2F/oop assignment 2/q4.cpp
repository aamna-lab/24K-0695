//24K-0695 Aamna Rizwan_Q4
#include <iostream>
#include <string>
using namespace std;

int passwordGeneration(char c) {
    int hash = 5381;
    return (hash * 33) + c;
}

string hashPassword(const string &password) {
    int hash = 5381;
    for (char c : password) {
        hash = (hash * 33) + c;
    }
    return to_string(hash);
}

class User {
protected:
    string name, email;
    int id;
    string hashed_password;
    string permissions[10];
    int permCount;
public:
    User(string n, int i, string e, string p) : name(n), id(i), email(e), hashed_password(hashPassword(p)), permCount(0) {}
    virtual bool authenticate(string password) {
         return hashPassword(password) == hashed_password; 
    }
    virtual void display() { 
        cout << "Name: " << name << ", ID: " << id << ", Email: " << email << endl; 
    }
    virtual bool accessLab() {
         return false; 
        }
};

class Student : public User {
protected:
    bool assignments[5];
public:
    Student(string n, int i, string e, string p) : User(n, i, e, p) {
        for (int j = 0; j < 5; j++) assignments[j] = false;
    }
    void submitAssignment(int index) { if (index >= 0 && index < 5) assignments[index] = true; }
    void display() override {
        User::display();
        cout << "Assignments: ";
        for (int j = 0; j < 5; j++) cout << assignments[j] << " ";
        cout << endl;
    }
};

class TA : public Student {
protected:
    string projects[2];
    Student* assignedStudents[10];
    int projectCount, studentCount;
public:
    TA(string n, int i, string e, string p) : Student(n, i, e, p), projectCount(0), studentCount(0) {}
    void assignStudent(Student *s) { if (studentCount < 10) assignedStudents[studentCount++] = s; }
    void addProject(string project) { if (projectCount < 2) projects[projectCount++] = project; }
    void display() override {
        Student::display();
        cout << "Projects: ";
        for (int j = 0; j < projectCount; j++) cout << projects[j] << " ";
        cout << endl;
    }
};

class Professor : public User {
public:
    Professor(string n, int i, string e, string p) : User(n, i, e, p) {}
    void display() override { User::display(); }
};

void authenticateAndPerformAction(User* user, string action) {
    if (action == "access_lab" && user->accessLab()) {
        cout << "Lab access granted" << endl;
    } else {
        cout << "Action not allowed" << endl;
    }
}

int main() {
    Student s("Aamna", 1, "k240695@nu.edu.pk", "password");
    TA t("Laiba",2, "k240644@nu.edu.pk", "password");
    Professor p("Ms.Abeeha Sattar", 3455, "abeeha.sattar@nu.edu.pk", "password");

    s.submitAssignment(0);
    t.addProject("Project 1");
    t.assignStudent(&s);
    s.display();
    t.display();
    p.display();
    authenticateAndPerformAction(&t, "access_lab");
}
