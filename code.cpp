#include <iostream>
using namespace std;

class BankAccount{
    protected:
    int accountNumber;
    float balance;
    public:
    BankAccount(int num,float b) : accountNumber(num), balance(b){}
    virtual void calculateInterest() = 0;
    virtual void withdraw() = 0;
};

class SavingsAccount : public BankAccount{
    protected:
    float interestRate=0.05;
    float interest;
    public:
    SavingsAccount(float interR,float inter,int num,float b) : interestRate(interR), interest(inter), BankAccount(num,b){}
    void calculateInterest() override{
    interest = balance*interestRate;
    cout << "Your interest rate is : " << interestRate << endl;
    cout << "Your interest on balance " << balance << " is " << interestRate << endl;
    }
    
    void withdraw(float amount) override{
        if(amount>balance){
            cout << "invalid amount\n";
        }else if(balance<500.0){
            cout << "withdrawal failed\n";
        }else{
            balance=balance-amount;
        }
    }
};

class CurrentAccount : public BankAccount{
    
};
int main(){
    
}
