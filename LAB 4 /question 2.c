#include<stdio.h>
int main(){
	int a;
	printf("Enter your number\n");
	scanf("%d", &a);
	if (a>0 &&  a%10==0 && a%2==0){
	  printf("Valid input");
	}else
	  printf("Invalid input");


	
}
