#include <stdio.h>
int main() {
    int f,n;
    int prime=1;
    printf("Enter a number\n");
    scanf("%d", &f);
    if(f<=1){
        printf("Not a prime number\n");
    }
    for(n=2 ; n*n<f ;n++)
        if(f % n==0){
           prime=0;
           break;
        }

        if(prime==1){
        printf("prime\n");
    }else 
    printf("not a prime\n");
    
   
    
    
    

    int  a=0, b=1, c, i;
 
    for(i=1; i<=f ; i++){
        printf(" %d  ",a);
        c=a+b;
        a=b;
        b=c;
        
    }
    
    
    
}
