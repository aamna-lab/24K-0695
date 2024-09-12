#include<stdio.h>
int main(){
    char input;
    printf("Enter input\n");
    scanf("%c", &input);
    if(input>=48 && input<=57){
     printf("Input is a digit");
    }else if(input>=65 && input<=90){
        printf("Input is a Capital Alphabet");
    }else if(input>=33 && input<=47){
        printf("Input is a special character");
    }else if(input>=97 && input<=122){
        printf("Input is a small alphabet");
    }else printf("Input not valid");
    
    }
