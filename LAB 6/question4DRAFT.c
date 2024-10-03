#include <stdio.h>
int main(){
    int num,sum=0,a;
    int newnum;
    printf("Enter your number:\n");
    scanf("%d", &num);
   newnum=num;
    do{
        a=num%10;
        num=num/10;
        a=a*a*a;
        sum=sum+a;
    }while(num!=0);
    if(sum==newnum){
        printf("Number is an Armstrong Number\n");
    }else
    printf("Number not Armstrong");
        
    }
