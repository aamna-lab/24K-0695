#include <stdio.h>
int main() {
    int a=3,user;
    printf("Enter number\n");
    scanf("%d", &user);
    if (user==0){
        printf("error, enter a non-zero number");
    }
    while(user!=0){
    user=user+a;
    printf("%d\n", user);
    }
}
