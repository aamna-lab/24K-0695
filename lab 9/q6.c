#include<stdio.h>
void maxmin( int arr2[5]){
     int min=arr2[0];
     int max=arr2[0];
    for(int i=1;i<5;i++){
        if(arr2[i]<min){
           min=arr2[i];
        }if(arr2[i]>max){
            max=arr2[i];
        }
    }
    printf(" Maximum value is : %d\n", max);
    printf("Minimum value is : %d\n",min);
}

int main(){
    int arr[5];
    for( int j=0;j<5;j++){
        printf("Enter %d number\n", j);
        scanf("%d",&arr[j]);
    }
    maxmin(arr);
}
