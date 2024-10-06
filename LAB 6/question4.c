#include <stdio.h>
int main() {
    int num,a,sum=0, usernum;
    printf("enter your number\n");
    scanf("%d", &num);
    usernum=num;
    while(num!=0){
        a=num%10;
        num=num/10;
        a=a*a*a;
        sum=sum+a;
        printf("%d\n",a);
        
    }if(sum==usernum){
        printf("armstrong");
    }else
    printf("not armstrong"); 
}
