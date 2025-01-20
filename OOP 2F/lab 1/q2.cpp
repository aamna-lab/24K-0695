#include <iostream>
using namespace std;

int main() {
    int x;
    int marks;
    float total=0;
    cout << "Enter number of students" <<endl;
    cin >> x;
    for (int i=1;i<=x;i++){
        for (int j=1;j<=3;j++){
            cout << "Enter marks for subject " << j << " for student " << i << endl;
            cin >> marks;
            if (marks>=90){
                cout << "Grade for Subject " << j << " = A" << endl;
            }else if (marks>=80 && marks<=89){
                cout << "Grade for Subject " << j << " = B" << endl;
            }else if (marks>=70 && marks<=79){
                cout << "Grade for Subject " << j << " = C" << endl;
            }else if(marks>=60 && marks<=69){
                cout << "Grade for Subject " << j << " = D" << endl;
            }else 
            cout << "Grade for Subject" << j << "= F" << endl;
          total=total+marks;  
        }
        cout << "Total marks for student " << i << " = " << total << endl;
        cout << "Average marks for student " << i << " = " << total/3 << endl;
        
    }

}
