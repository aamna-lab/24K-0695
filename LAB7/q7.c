#include <stdio.h>
int main() {
    int i,n,number,count=0;
    printf("Enter array size\n");
    scanf("%d", &n);
    int arr[n];
    for(i=1;i<=n;i++){
        printf("Enter %d element\n",i);
        scanf("%d", &number);
        count++;
    }
    if(count){
        printf("Number %d occured more than once", count);
    }
}
