#include<stdio.h>
int main()
{
   int d1=1207;
   float fwd_t=118.0;
   float bwd_t=123.0;
   float total_fuel, fuel_cost, c_avg, L1;
   printf("Enter car's fuel average in kilometres per litre");
   scanf("%f", &c_avg);
   if c_avg<=0
   printf("Invalid car fuel average");
   else 
   L1=1207/c_avg;
   fuel_cost= (L1*fwd_t)+(L1*bwd_t);
   total_fuel=L1+L1;
   printf(" The total fuel was:  \n", total_fuel);
   printf(" The total cost for fuel was:  \n", fuel_cost);
      
}




   




