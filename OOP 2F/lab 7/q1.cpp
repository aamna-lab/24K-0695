#include <iostream>
using namespace std;

class Account{
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
public:
    Account(int num=0, double b=0.0, string name="", string type="") 
        : accountNumber(num), balance(b), accountHolderName(name), accountType(type) {}

    void deposit(double amount) {
        if (amount > 0.0) {
            balance += amount;
            cout << "New balance is: " << balance << endl;
        } else {
            cout << "Invalid amount\n";
        }
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance \n";
        } else {
            balance -= amount;
            cout << "New balance is: " << balance << endl;
        }
    }

    virtual void calculateInterest() = 0;

    virtual void printStatement() {
        cout << "-------------------Bank Statement------------------------" << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void getAccountInfo() {
        cout << "Name: " << accountHolderName << endl;
        cout << "Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Type: " << accountType << endl;
    }
};

class SavingsAccount : public Account {
protected:
    float interestRate;
    float minimumBalance;
public:
    SavingsAccount(float i=0.0, float m=30.0, int num=0, double b=0.0, string name="", string type="")
        : interestRate(i), minimumBalance(m), Account(num, b, name, type) {}

    void calculateInterest() override {
        cout << "Interest = " << (balance * interestRate) / 100 << endl;
    }

    void getAccountInfo() override {
        Account::getAccountInfo();
        cout << "Interest Rate: " << interestRate << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
    }

    void printStatement() override {
        cout << "-------------------Bank Statement------------------------" << endl;
        cout << "Savings Account - Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
    }
    void withdraw (double amount){
        if(balance-amount <= minimumBalance){
            cout << "error" << endl;
        }
        else
       Account ::withdraw(amount);

    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int num=0, double b=0.0, string name="", string type="")
        : Account(num, b, name, type) {}

    void getAccountInfo() override {
        Account::getAccountInfo();
    }
    void calculateInterest() override{
        cout << "No interest" << endl;
    }

    void printStatement() override {
        cout << "-------------------Bank Statement------------------------" << endl;
        cout << "Checking Account - Balance: " << balance << endl;
    }
};

class FixedDepositAccount : public Account {
protected:
    float fixedInterestRate;
    string maturityDate;
public:
    FixedDepositAccount(float r=0.0, string d="", int num=0, double b=0.0, string name="", string type="")
        : fixedInterestRate(r), maturityDate(d), Account(num, b, name, type) {}

    void calculateInterest() override {
        cout << "Interest = " << (balance * fixedInterestRate) / 100 << endl;
    }

    void getAccountInfo() override {
        Account::getAccountInfo();
        cout << "Fixed Interest Rate: " << fixedInterestRate << endl;
        cout << "Maturity Date: " << maturityDate << endl;
    }

    void printStatement() override {
        cout << "-------------------Bank Statement------------------------" << endl;
        cout << "Fixed Deposit Account - Balance: " << balance << endl;
        cout << "Fixed Interest Rate: " << fixedInterestRate << endl;
        cout << "Maturity Date: " << maturityDate << endl;
    }
};

int main() {
    SavingsAccount sa(0.3, 400.0, 23456, 4567.89, "Aamna", "Savings");
    CheckingAccount ca(23456, 4567.89, "Aamna", "Checking");
    FixedDepositAccount fda(0.7, "13-04-2025", 89456, 97350, "Aamna", "Fixed Deposit");

cout << "Savings Account :\n";
sa.getAccountInfo();
sa.printStatement();
sa.deposit(6789.45);
sa.withdraw(456.78);

cout << "Fixed deposit :\n" ;
fda.getAccountInfo();
fda.printStatement();
fda.deposit(875.67);


    
}
