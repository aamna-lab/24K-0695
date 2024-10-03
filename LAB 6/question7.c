#include <stdio.h>
int main() {
    char a;
    for(a=65; a<=70;a++){
        if(a==65 || a==70){
            printf(" %c %c %c %c %c\n",a,a+1,a+2,a+3,a+4);
        }else 
            printf(" %c       %c\n",a,a+4);
        
        
    }    
    
}
