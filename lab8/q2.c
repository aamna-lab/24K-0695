#include <stdio.h>
int main() {
    int n,num;
    printf("Enter value of n\n");
    scanf("%d", &n);
    printf("Enter the number you want to start with\n");
    scanf("%d", &num);
    int arr[2][n][2];
    for(int i=0;i<2;i++){
        for( int j=0;j<n;j++){
            for( int k=0;k<2;k++){
                 printf("{%d,%d}", num, num+2);
                num--;
            }
        }
       printf("{%d,%d}", num, num+2);
    }
    
}
