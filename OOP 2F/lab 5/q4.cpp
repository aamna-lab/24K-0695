#include <iostream>
using namespace std;

class BankAccount{
    private:
    int accountNumber;
    string accountHolderName;
    double balance;
    public:
    BankAccount( int acc, string name, double b){
       accountNumber = acc;
       accountHolderName =name;
      balance = b;
    }
    int getNum(){
        return accountNumber;
    }
    string getName(){
        return accountHolderName;
    }
    double getbalance(){
        return balance;
    }
    void setNum(int newNum){
        accountNumber = newNum;
    }
    void setName( string newName){
        accountHolderName = newName;
    }
    void setbalance (double b){
        balance = b;
    }
    void deposit (double amount){
        balance = balance + amount;
        cout << " deposit successful.New balance is :" << balance << endl;
    }
    void withdraw (double amount){
        if(amount< balance || amount==balance){
            balance = balance - amount;
            cout << " withdrawal successful. new balance is : " << balance << endl;
        }
    else{
        cout << "\nInsufficient balance" ;
    }
    }
    void display(){
        cout << "Account Number : " << getNum() << endl;
        cout << "Account Holder Name : " << getName() << endl;
        cout << "Current Balance : " << getbalance() << endl;
    }
};


int main() {
    BankAccount* b[3];
    b[0] = new BankAccount(12345, "Aamna", 34567.9087);
    b[1] = new BankAccount(670, "Hammad", 1234.678);
    b[2] = new BankAccount(76, "Hassaan", 78356.9332);
    for (int i = 0; i < 3; i++){
        b[i]->display();
        cout << endl;
    }
    b[0]->deposit(500.0);
    b[0]->display();
    cout << endl;
    b[0]->withdraw(200.0);
    b[0]->display();
    for (int i = 0; i < 3; i++)
        delete b[i];
    
    
  
}
