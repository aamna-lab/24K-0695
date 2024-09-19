#include <stdio.h>

int main()
{
    int c,cf,f;
    float percent;
    printf("Enter  total number of calories in food\n");
    scanf("%d",&c);
    printf("Enter fat in grams in food\n");
    scanf("%d",&f);
    if (f<0 || c<0){
        printf("Error; either the calories or fat grams were entered incorrectly");
    }else
    cf=f*9;
    if (cf>c){
        printf("Error; calories from fat greater than total calories");
    }else if (cf<c){
    percent=(cf/c)*100;
    printf("The percentage of calories that come from fat is : %d", cf);
    }
    
    
}
