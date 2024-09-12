#include<stdio.h>
int main(){
	int a;
	printf("Enter your number\n");
	scanf("%d", &a);
	if (a%3==0){
	 printf("This number is a multiple of 3\n");
	}else
	 printf("This number is not a multiple of 3\n");
}
