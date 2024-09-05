#include<stdio.h>
int main ()
{
   float salary, tax_rate, tax;
   printf("Enter your salary and tax_rate");
   scanf("%f","%f", &salary, &tax_rate);
   tax= (salary*tax_rate)/100;
   printf("Your taxes are : ", tax);
   salary= salary - tax;
   printf("Your salary after tax deductions is : ", salary);

}
    
    


    
