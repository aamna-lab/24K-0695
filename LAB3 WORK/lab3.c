#include<stdio.h>
int main ()
{
   float salary, tax rate, tax;
   printf("Enter your salary and tax rate");
   scanf("%f","%f", salary, tax rate);
   tax= (salary*tax rate)/100;
   printf("Your taxes are : ", tax);
   salary= salary - tax;
   printf("Your salary after tax deductions is : ", salary);

}
    
    


    