#include <stdio.h>
int main(){
    int x;
    printf("Enter your number\n");
    scanf("%d", &x);
    x%10==0? printf("Last Digit Zero") : printf("Last Digit Non-zero");
}
