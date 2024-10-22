#include <stdio.h>
int main() {
    int arr[10];
    int n; int i; int number;
    int count=0;
    printf(" Enter 10 integers :\n");
    for(i=0;i<10;i++){
        scanf("%d", &arr[i]); }
    for (i=0;i<10;i++){
        for(n=i+1;n<10;n++){
            if(arr[i]==arr[n]){
                count++;
                number=arr[i];
            }
        }
        if(count>0){
        printf("The integer %d is repeated %d times\n", number,count);
    }
    
    }
}
