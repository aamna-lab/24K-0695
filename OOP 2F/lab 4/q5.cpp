#include <iostream>
using namespace std;

class Employee{
private:
    int employeeID;
    string name;
    string department;
    double salary;

public:
    Employee() : employeeID(0), name("Unknown"), department("Unknown"), salary(0.0) {}
    Employee(int ID, string n, string dep, double s) : employeeID(ID), name(n), department(dep), salary(s) {}

    void giveBonus(double amount)
    {
        salary += amount;
        cout << "\nAdded bonus successfully.";
    }
    bool isManager()
    {
        return (this->department == "Management");
    }
    void displayDetails()
    {
        cout << "\nID: " << employeeID;
        cout << "\nName: " << name;
        cout << "\ndepartment: " << department;
        cout << "\nsalary: " << salary;
    }
};

int main()
{
    Employee object(235, "Aamna Rizwan", "Management" , 334567);
    object.displayDetails();
    object.giveBonus(20000);
    object.displayDetails();
    if (object.isManager()){
        cout << "\nThis employee is a manager" << endl ;
    }
}
