#include <stdio.h>
#include <string.h>
int main() {
    int i;
    char original[100];
    char string[100];
    printf("Enter string\n");
    scanf("%s", &string);
    strcpy(original, string);
    int n= strlen(string);
    char *strrev(char *string);
    
    if(strcmp(original, string) == 0){
        printf("string is palindrome");
    }
    else printf("strinf is not a palindrome");
}
