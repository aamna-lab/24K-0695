#include<stdio.h>
int main(){
    int w,v,s;
    printf("Enter '1' if it is a weekday else enter '2'\n");
    scanf("%d", &w);
    printf("Enter '1' if we are on vacation else enter '2'\n");
    scanf("%d", &v);
    if (w==2 || v==1){
        printf("Sleep In!!");
        
    }else printf("Cannot Sleep In:(");
}
