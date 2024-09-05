#include<stdio.h>
int main()
{
  float p, r, t, si;
  printf("Enter value of the Principle: \n");
  scanf("%f", &p);
  printf("Enter Rate of Interest: \n");
  scanf("%f", &r);
  printf("Enter time in years: \n");
  scanf("%f", &t);
  if p<100 || p>1000000
  printf("Invalid Input for Principle");
  if r<5% || r>10%
  printf("Invalid Input for Rate of Interest");
  if t<1 || t>10 
  printf("Invalid input for Time");
  si=(p*r*t)/100;
  printf("The simple interest according to given data is:  ", si);
}





