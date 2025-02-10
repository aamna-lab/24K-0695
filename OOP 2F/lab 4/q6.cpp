
#include <iostream>
#include <string>
using namespace std;

class BankAccount{
    int accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(int accNum, string name, double initialBalance = 0.0)
        : accountNumber(accNum), ownerName(name), balance(initialBalance) {}

    void deposit(double amount){
        if (amount > 0){
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount){
        if (amount <= 0){
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > balance){
            cout << "Insufficient funds. Cannot withdraw more than available balance." << endl;
        }
        else{
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner's Name: " << ownerName << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main(){
    int accNum;
    string name;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accNum;
    cin.ignore();
    cout << "Enter owner's name: ";
    getline(cin, name);

    cout << "Enter initial balance (default is 0): ";
    cin >> initialBalance;

    BankAccount account(accNum, name, initialBalance);

    int choice;
    while (true)
    {
        cout << "\nBank Account System Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            double depositAmount;
            cout << "Enter deposit amount: ";
            cin >> depositAmount;
            account.deposit(depositAmount);
            break;
        }
        case 2:
        {
            double withdrawAmount;
            cout << "Enter withdrawal amount: ";
            cin >> withdrawAmount;
            account.withdraw(withdrawAmount);
            break;
        }
        case 3:
            account.displayDetails();
            break;
        case 4:
            cout << "Exiting the system. Thank you!" << endl;
            return 0;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
