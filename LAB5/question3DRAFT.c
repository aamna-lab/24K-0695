 #include<stdio.h>
int main(){
    int c;
    int cup,coffee,t;
    printf("Enter '1' for White Coffee\nEnter '2' for Black Coffee\n");
    scanf("%d", &c);
    printf("Enter '1' for normal size cup\nEnter '2' for double size cup\n");
    scanf("%d", &cup);
    printf("Enter '1' if coffee=manual otherwise,\nEnter '2' if coffee=auto\n");
    scanf("%d", &coffee);
    switch(coffee){
        case '1':
        switch(c){
        case '1':
        printf("If your cup size is normal\nPut water for 15 mins\nAdd sugar for 15 mins\nMix well for 20 mins\nAdd coffee for 2 mins\nAdd milk for 4 mins\nMix well for 20 mins\n");
        break;
         case '2':
        printf("if your cup is double then\nPut water for 22.5  mins\nAdd sugar for 22.5 mins\nMix well for 30 mins\nAdd coffee for 3 mins\nAdd milk for 6 mins\nMix well for 30 mins\n");
         break;
        switch(cup){
            case'1':
            printf("Your coffee will take 1 hour and 16 minutes");
            break;
            case '2':
            printf("Your coffee will take 1 hour 54  minutes");
            break;
        }
        break;
        case '2':
        printf("If your cup size is normal\nPut water for 20 mins\nAdd sugar for 20 mins\nMix well for 25 mins\nAdd coffee for 15 mins\nMix well for 25 mins\n");
        printf("If your cup size is double\nPut water for 30 mins\nAdd sugar for 30 mins\nMix well for 37.5 mins\nAdd coffee for 22.5 mins\nMix well for 37.5 mins\n");
         switch(cup){
            case'1':
            printf("Your coffee will take 1 hour and 45 minutes");
            break;
            case '2':
            printf("Your coffee will take 2 hours and 38 minutes");
            break;
         } default: 
         printf("invalid input");
    } 
    break;
    case '2':
    switch(c){
        case '1':
        switch(cup){
            case '1':
            printf("Your coffee will take 1 hour and 16 minutes");
            break;
            case '2':
            printf("Your coffee will take 1 hour 54  minutes");
            break;
        }
        break;
        case '2':
         switch(cup){
            case '1':
            printf("Your coffee will take 1 hour and 45 minutes");
            break;
            case '2':
            printf("Your coffee will take 2 houra 38  minutes");
            break;
        }
        break;
            
        }
        
    }
   
        
    
    
   
    
