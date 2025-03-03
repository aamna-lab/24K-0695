#include<iostream>
using namespace std;

class LoanHelper{
    private:
    const float interest;
    float amount;
    int m;
    public:
    LoanHelper(float a,int month, float interestRate): amount(a), m(month), interest(interestRate){}
    float getAmount(){
       float monthlypayment = amount / m;
       float pay_i = monthlypayment * (1 + interest);  
      return pay_i;
    }
    int getMonths(){
        return m;
}
};
int main(){
    int month;
    float loan,i;
    cout << "Enter loan amount: "<< endl;
    cin >> loan;
    cout<< "Enter number of months" << endl;
    cin >> month;
    cout << "Enter interest\n" ;
    cin >> i;
    if (i<=0.0 || i>=0.5){
        cout << "\nerror!, wrong value";
        return 1;
    }
    else{
        LoanHelper l(loan,month,i);
        cout << "You have to pay " << l.getAmount() << " for " << l.getMonths() << "months to repay loan" << endl;
    }
    
}
