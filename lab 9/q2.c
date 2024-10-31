#include <stdio.h>
    void swapInteger(int n1,int n2){
        int temp;
        temp=n1;
        n1=n2; 
        n2=temp;
        printf("first number is %d , second number is %d", n1,n2);
        
    }
int main(){
    int a,b;
    printf("Enter 1st number\n");
    scanf("%d", &a);
    printf("Enter 2nd number\n");
    scanf("%d",&b);
    swapInteger(a,b);
}
