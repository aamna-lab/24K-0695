#include<stdio.h>
int main(){
    int num1,num2;
    char op;
    printf("Enter an operator (+, -, /, *):\n");
    scanf("%c" ,&op);
    printf("Enter your first number\n");
    scanf("%d",&num1);
    printf("Enter your second number\n");
    scanf("%d", &num2);
    switch(op){
        case '+':
          printf("%d + %d = %d", num1, num2, num1+num2);
        break;
        case '-':
          printf("%d - %d = %d", num1, num2, num1-num2);
        break;
        case '*':
          printf("%d*%d=%d", num1, num2,num1*num2);
        break;
        case '/' :
          printf("%d/%d=%d", num1, num2, num1/num2);
        break;
        default:
          printf("Invalid operator");
    }
          
    }
