#include<stdio.h>
int main(){
    int amount,amount_d,discount,saved;
    printf("Enter total cost of all items\n");
    scanf("%d", &amount);
    if (amount>=500){
     printf("Congratulations! You are eligible for discounts\n");
      if (amount>=500 && amount<2000){
       amount_d=amount-(amount/20);
       saved=amount/20;
       printf("You are eligible for 5 percent discount\n");
       printf("The actual amount is: %d \n", amount);
       printf("Your discounted amount is : %d \n", amount_d);
       printf("You saved : %d \n", saved);
      }else if (amount>=2000 && amount<4000){  
       amount_d=amount-(amount/10);
       saved=amount/10;
       printf("The actual amount is: %d \n", amount);
       printf("You are eligible for 10 percent discount!\n");
       printf("Your discounted amount is: %d \n", amount_d);
       printf("You saved : %d \n", saved);
     }else if (amount<=4000 && amount<6000){
         amount_d=amount-(amount/5);
         saved=amount/5;
         printf("The actual amount is : %d\n", amount);
         printf("You are eligible for 20 percent discount!\n");
         printf("Your discounted amount is : %d \n",amount_d);
         printf("You saved: %d \n", saved);
     }else if (amount>6000){
         amount_d=amount-(7*amount/20);
         saved=(7*amount/20);
         printf("The actual amount is: %d \n", amount);
         printf("You are eligible for 35 percent discount!\n");
         printf("Your discounted amount is : %d \n", amount_d);
         printf("You saved: %d \n", saved);
     }}else
     printf("Sorry, you are not eligible for discount");
     }
