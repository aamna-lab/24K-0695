#include <stdio.h>
int main() {
   char arr[100];
   int a=0,e=0,i=0,o=0,u=0,index;
   printf("Enter your string:\n");
   scanf("%s", arr);
   for(index=0;index<100;index++){
       if(arr[index]=='a' || arr[index]=='A'){
           a=a+1;
       }
       else if(arr[index]=='e' || arr[index]=='E'){
           e=e+1;
       }
       else if(arr[index]=='i' || arr[index]=='I'){
           i=i+1;
       }
       else if(arr[index]=='o' || arr[index]=='O'){
           o=o+1;
       }
       else if(arr[index]=='u' || arr[index]=='U'){
           u=u+1;
       }
   }
   printf("a=%d e=%d i=%d o=%d u=%d",a,e,i,o,u);
   
   
  
}
