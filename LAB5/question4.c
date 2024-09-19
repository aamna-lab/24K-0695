#include<stdio.h>
int main(){
    float ph;
    printf("Enter value of pH\n");
    scanf("%f",&ph);
    
    if (ph>7){
        if (ph<12){
            printf("Alkaline");
        }else 
        printf("Very Alkaline");
    }else if (ph==7){
        printf("Nuetral");
    }else if (ph>2){
        printf("Acidic");
    }else 
    printf("Very acidic");
    
    
}
