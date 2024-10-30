#include<stdio.h>
int main(){
    int n,i;
    printf("Enter the number of rows of upper half");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for( int j=i;j<n;j++){
            printf(" ");
        }
    }
    for(int j=0;j<(2*i -1);j++){
        printf("*");
    }printf("\n");
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}
