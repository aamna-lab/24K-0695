#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    float balance;
public:
    BankAccount(int num, float b) : accountNumber(num), balance(b) {}
    virtual void calculateInterest() = 0;
  
    void showBalance() { cout << "Account [" << accountNumber << "] Balance: " << balance << endl; }
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int num, float b) : BankAccount(num, b) {}
    void calculateInterest() override {
        float interest = balance * 0.05; 
        cout << "Savings Account Interest: " << interest << endl;
    }

  
    void deposit(float amount) { balance += amount; cout << "Cash Deposit: " << amount << endl; }
    void deposit(float amount, string type) { cout << type << " Deposit: " << amount << endl; balance += amount; }

    void withdraw(float amount) {
        if (balance < 500) cout << "Insufficient balance.\n";
        else if (amount > balance) cout << "Withdrawal failed.\n";
        else { balance -= amount; cout << "Withdrawal: " << amount << endl; }
    }
    SavingsAccount operator-(float amount) { return SavingsAccount(accountNumber, balance - amount); }
SavingsAccount operator*(float interestRate) { return SavingsAccount(accountNumber, balance * (1 + interestRate)); }
SavingsAccount operator/(int months) { return SavingsAccount(accountNumber, balance / months); }

};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(int num, float b) : BankAccount(num, b) {}

    void calculateInterest() override {
        cout << "Current Account has no interest.\n";
    }

    void deposit(float amount) { balance += amount; cout << "Cash Deposit: " << amount << endl; }
    void deposit(float amount, string type) { cout << type << " Deposit: " << amount << endl; balance += amount; }

    void withdraw(float amount) {
        if (balance - amount < -1000) cout << "Overdraft limit exceeded\n";
        else { balance -= amount; cout << "Withdrawal: " << amount << endl; }
    }
    CurrentAccount operator+(float amount) { return CurrentAccount(accountNumber, balance + amount); }
CurrentAccount operator-(float amount) { return CurrentAccount(accountNumber, balance - amount); }
CurrentAccount operator*(float interestRate) { return CurrentAccount(accountNumber, balance * (1 + interestRate)); }
CurrentAccount operator/(int months) { return CurrentAccount(accountNumber, balance / months); }
};


int main() {
    SavingsAccount sa(101, 600);
    CurrentAccount ca(102, 200);
    sa.showBalance();
    ca.showBalance();
    sa.deposit(100);            
    sa.deposit(200, "Check");    
    ca.deposit(500);            
    ca.deposit(300, "Online");   
    sa.withdraw(700);            
    sa.withdraw(100);            
    ca.withdraw(1100);           
    ca.withdraw(500);            
    sa.calculateInterest();
    ca.calculateInterest();
    sa = sa * 0.05;              
    sa = sa - 50;                
    ca = ca + 200;             
    ca = ca / 4;                 
    sa.showBalance();
    ca.showBalance();

    return 0;
}
