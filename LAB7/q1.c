#include <stdio.h>
int main() {
   int arr[6]={1,2,3,4,5,6};
   int i,temp;
   for(i=0;i<6;i++){
       temp=arr[i]; //temp2
       arr[i]=arr[5]; //5
       arr[5]=temp;  //1
       printf("%d", arr[i]);
   }
}
