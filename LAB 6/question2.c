#include <stdio.h>
int main() {
    int a,i;
    int prime=1;
    printf("Enter a number\n");
    scanf("%d", &a);
    if(a<=1){
        printf("Not a prime number\n");
    }
    for(i=2; i*i<=a ; i++){
        if(a % i==0){
           prime=0;
           break;
        }
    }
        if(prime==1){
        printf("prime\n");
    }else 
    printf("not a prime\n");
    
   
    
    
    
}
