#include<stdio.h>
#include<string.h>
void rev(char str[50]){
    int length=strlen(str);
    char reversed[50];
    for(int i=0;i<length;i++){
        reversed[i]=str[length-1-i];
    }
    reversed[length]='\0';
    printf("reversed string is %s",reversed);
    
}
int main(){
    char strmain[50];
    printf("Enter your string\n");
    scanf("%s", &strmain);
    rev(strmain);
}
