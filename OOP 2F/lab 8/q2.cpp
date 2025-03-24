#include <iostream>
using namespace std;

class Account {
protected:
    string accountNumber, accountHolder;
    double balance;
public:
    Account(string num, string name, double b) : accountNumber(num), accountHolder(name), balance(b) {}

    Account operator+(const Account &acc) {
        return Account("Merged", "Multiple Holders", this->balance + acc.balance);
    }
    Account& operator-=(double amount) {
        balance -= amount;
        return *this;
    }
    bool operator>(const Account &a) {
        return this->balance > a.balance;
    }
    friend ostream& operator<< (ostream& os, const Account& a);
};

ostream& operator<< (ostream& os, const Account& a) {
    os << "\nAccount Number: " << a.accountNumber
       << "\nHolder: " << a.accountHolder
       << "\nBalance: " << a.balance;
    return os;
}

int main() {
    Account acc1("24K-0695", "Aamna Rizwan", 50000);
    Account acc2("24K-0644", "Laiba Khan", 40000);
    cout << acc1 << endl;
    cout << acc2 << endl;
    return 0;
}
