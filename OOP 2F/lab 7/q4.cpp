
#include <iostream>
using namespace std;

class Person{
    public:
    string name;
    string address;
    int id,phoneNumber;
    Person(string n,string a,int i,int pn):
    name(n),address(a),id(i),phoneNumber(pn){}
    virtual void displayInfo(){
        cout << "Name : " << name << endl;
        cout << "ID : " << id << endl;
        cout << "Phone Number : " << phoneNumber << endl;
        cout << "Address : " << address << endl;
    }
    void updateInfo(){
        this->name=name;
        this->id=id;
        this->address=address;
        this->phoneNumber=phoneNumber;
    }
};

class Student : public Person{
    protected:
    int enrollmentYear;
    string coursesEnrolled;
    float gpa;
    public:
    Student() : Person("", "", 0, 0), enrollmentYear(0), coursesEnrolled(""), gpa(0.0) {}
    Student(int year,string ce,float g,string n,string a,int i,int pn):
    enrollmentYear(year),coursesEnrolled(ce), gpa(g), Person(n,a,i,pn){}
    void displayInfo() override{
        Person :: displayInfo();
        cout << "Enrollment Year : " << enrollmentYear << endl;
        cout << "Courses Enrolled : " << coursesEnrolled << endl;
        cout << "GPA : " << gpa << endl;
    }
    float getgpa(){
        return gpa;
    }

};

class Professor : public Person{
    protected:
    string department;
    string coursesTaught;
    int salary;
    public:
    Professor (string d, string ct,int sal,string n,string a,int i,int pn): 
    department(d),coursesTaught(ct),salary(sal),Person(n,a,i,pn){}
    void displayInfo() override{
        Person :: displayInfo();
        cout << "Department : " << department << endl;
        cout << "Courses Taught : " << coursesTaught << endl;
        cout << "Salary : " << salary << endl;
    }

};

class Staff : public Person{
    protected:
    string department;
    string position;
    int salary;
    public:
    Staff (string d, string p,int sal,string n,string a,int i,int pn): 
    department(d),position(p),salary(sal),Person(n,a,i,pn){}
    void displayInfo() override{
        Person :: displayInfo();
        cout << "Department : " << department << endl;
        cout << "Position : " << position << endl;
        cout << "Salary : " << salary << endl;
    }

};

class Course{
    protected:
    int courseID;
    int credits;
    string courseName;
    string instructor;
    string schedule;
    Student enrolledStudents[50];
    int studentCount=0;
    public:
    Course(int id,int cr,string name,string ins,string sd):
    courseID(id), credits(cr), courseName(name), instructor(ins),schedule(sd){}
    void registerStudent(Student student){
        if(studentCount < 50){
            enrolledStudents[studentCount] = student;
            studentCount++;
            cout << "Student " << student.name << " registered in " << courseName << endl;
        } else {
            cout << "Course is full! Cannot register more students.\n";
        } 
    }
    void calculateGrades(){
       cout << "Grades for course : "<< courseName << endl;
       for(int i=0; i<studentCount ; i++){
        cout << "Student : " << enrolledStudents[i].name << " GPA: " << enrolledStudents[i].getgpa() << endl;
       }

    }
};

int main(){
Student student(2024,"Multivariable Calculus",3.56,"Aamna","FB Area,Karachi ",0645,123456);
student.displayInfo();
Professor p("CS", "ICT", 34560, "Sir Ishtiaq", "Karachi,Pakistan",4500,345777);
p.displayInfo();
Staff staff("CS","Admin Office",24560,"Lucy","Karachi,Pakistan",45703,0456234);
staff.displayInfo();
Course course(101,3,"Multivariable Calculus", "Sir Mairaj", "Tuesday");
course.registerStudent(student);
course.calculateGrades();

}
