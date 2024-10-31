#include <stdio.h>
void math(int a,int b, char op){
    if(op=='+'){
         printf("Your answer is %d", a+b);
    }else if(op=='-'){
        printf("Your answer is %d", a-b);
    }else if(op=='*'){
        printf("Your answer is %d", a*b);
    }else if(op=='/'){
        printf("your answer is %d", a/b);
    }else 
    printf("invalid operation entered\nEnter a valid operation such as + or - or / or *");
}
int main(){
    int n1,n2;
    char opr1;
    printf(" Enter 1st number\n");
    scanf("%d", &n1);
    printf("Enter  2nd number\n");
    scanf("%d",&n2);
    printf("Enter the type of operation ( + - * /)\n");
    scanf(" %c", &opr1);
    math(n1,n2,opr1);
}
