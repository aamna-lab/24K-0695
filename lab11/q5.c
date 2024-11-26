#include<stdio.h>
struct Date{
    int day;
    char month[20];
    int year;
}date;
 struct event_name{
        struct Date date;
        char location[30];
};
int main(){
    struct event_name e1[2]={{13, "December", 2024, "Karachi"} ,
    {4, "January" , 2025, "Lahore"}};
    for(int i=0;i<2;i++){
    printf(" Event #%d\nDate : %s %d, %d\nLocation: %s\n\n",i+1,e1[i].date.month, e1[i].date.day, e1[i].date.year,e1[i].location);
    }
    
    
}
