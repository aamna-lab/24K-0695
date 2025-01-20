#include <iostream>
using namespace std;

int main() {
    int x;
    int prime=0;
    cout << "Enter number" << endl;
    cin >> x ;
    for (int i =2;i<x/2;i++){
        if(x%i!=0){
            prime=0;
        }else 
        prime=1;
    }
    if(prime==1){
        cout << "Number " << x << " is prime" << endl;
    }else
    cout << "Number " << x << " is not prime" <<endl;
}
