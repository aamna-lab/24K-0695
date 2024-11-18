#include <stdio.h>
struct Date{
    int date;
    int month;
    int year;
};
int numOfDays(d1,d2){
    if(d2>d1){
       return d2-d1;
    }else
    return d1-d2;
}
void dayWeek(struct Date date){
    int q = date.date;
    int m = date.month;
    int y = date.year;
    if (m <= 2) {
        m += 12;
        y--;
    }
    int K = y % 100;  
    int J = y / 100;
    int h = (q + ((13 * (m + 1)) / 5) + K +(K / 4) + (J / 4) + 2 * J) % 7;
    if(h==0){
        printf("Sunday\n");
    }else if (h==1){
        printf("Monday\n");
    }else if (h==2){
        printf("Tuesday\n");
    }else if (h==3){
        printf("Wednesday\n");
    }else if (h==4){
        printf("Thursday\n");
    }else if (h==5){
        printf("Friday\n");
    }else if (h==6){
        printf("Saturday\n");
    }else
    printf("invalid input");
}

int main() {
