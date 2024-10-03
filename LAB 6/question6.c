#include <stdio.h>
int main() {
    int a=0;
    do{
    a++;
    if(a==1 || a==6){
        printf("*       *\n");
    }else
    printf("* * * * *\n");
    }while(a<6);    
}
 
