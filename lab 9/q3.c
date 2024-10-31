#include <stdio.h>
void prime(int num){
    int prime=1;
    for(int i=2;i*i<num;i++){
        if(num%i==0){
            prime=0;
        }
    }if(prime){
        printf(" the number %d is prime",num);
    }else
    printf("Number not prime! :(");
}
int main(){
    int x;
    printf("Enter your number\n");
    scanf("%d",&x);
    prime(x);
}
 
