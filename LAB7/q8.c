#include <stdio.h>
int main() {
char array[50];
int i;
printf("enter operation\n");
scanf("%s", &array);
for(i=0;i<50;i++){
    if(array[i]=='+'){
        printf("add operation : %d + %d = %d\n", array[i-1], array[i+1], array[i-1]+ array[i+1]);
    }else if(array[i]=='-'){
         printf("subtract operation : %d + %d = %d\n", array[i-1], array[i+1], array[i-1] - array[i+1]);
    }
}
}
