#include<stdio.h>
int main(){
    float bill;
    int id,unit;
    char name[100];
    printf("Enter your customer ID\n");
    scanf("%d", &id);
    printf("Enter your first name\n");
    scanf("%s", &name);
    printf("Enter total amount of units consumed\n");
    scanf("%d", &unit);
    if (unit>=0 && unit<=199){
    bill=unit*16.20;
    printf("Your bill is : %.2f\n", bill);
    }else if (unit>=200 && unit<=299){
        bill=unit*20.10;
        printf("Your bill is : %.2f\n", bill);
    }else if (unit>=300 && unit<=499){
        bill=unit*27.10;
        printf("Your bill is : %.2f\n", bill);
    }else if (unit>=500){
        bill=unit*35.90;
        if (bill>18000.0){
            bill=bill+(9*bill/50);
            printf("Your bill is : %.2f\n", bill);
        }else printf("Your bill is :%.2f\n", bill);
    }
    
    }
