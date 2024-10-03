#include <stdio.h>
int main() {
    int a=0;
    do{
    a++;
    if(a==1 || a==5){
        printf("* * * * *\n");
    }else if(a==2 || a==4){
        printf("  *   *  \n");
    }else
    printf("    *    \n");
    }while(a<5);
} 
