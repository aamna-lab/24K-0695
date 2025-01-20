#include <iostream>
using namespace std;

int main() {
    int x;
    int marks;
    float total,avg;
    
    cout << "Enter number of students" <<endl;
    cin >> x;
    for (int i=1;i<=x;i++){
        total=0;
        for (int j=1;j<=3;j++){
            cout << "Enter marks for subject " << j << " for student " << i << endl;
            cin >> marks;
          total=total+marks;  
        }
        cout << "Total marks for student " << i << " = " << total << endl;
        cout << "Average marks for student " << i << " = " << total/3 << endl;
        avg= total/3;
        if (avg>=90){
                cout << "Grade = A" << endl;
            }else if (avg>=80 && avg<=89){
                cout << "Grade  = B" << endl;
            }else if (avg>=70 && avg<=79){
                cout << "Grade = C" << endl;
            }else if(avg>=60 && avg<=69){
                cout << "Grade  = D" << endl;
            }else 
            cout << "Grade =  F" << endl;
        
    }

}
