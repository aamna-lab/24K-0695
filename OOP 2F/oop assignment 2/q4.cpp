#include <iostream>
using namespace std;

class User{
    protected:
    string name;
    int ID;
    string permission[10];
    string email;
    //hashed password
    public:
    //constructor
    virtual void display(){
        cout << "Name : " << name <<  endl;
        cout << "ID : " << id <<  endl;
         cout << "Email : " << email<<  endl;
    }
    //access lab function
};

class Student : public User{
    protected:
    bool assignment[5];
    public:
    //constructor
    void display() override{
        User :: display();
    }
    //list of assignment
    //functuonality
};

class TA : public Student{
    protected:
    string projects[2];
    public:
    //constructor
    //function to display projects
    //override display func
    //TA can manage onlt 10 studnets
};

class Professor : public User{
    public:
    //override display
    //functionality to allow ta's to work with them
};

void authenticateAndPerformAction (User* user,string action){
    
}




int main() {
 
}
