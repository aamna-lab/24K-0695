#include <stdio.h>
struct travel{
    char pkg[60];
    char dest[40];
    int duration;
    int cost;
    int seats;
};
void display(struct travel t[3]){
    for(int i=0;i<3;i++){
        printf("Package name : %s\n", t[i].pkg);
        printf("Destination : %s\n",  t[i].dest);
        printf("Duration (in weeks): %d\n", t[i].duration);
        printf("Total Cost : %d\n", t[i].cost);
        printf("Number of Seats available: %d\n", t[i].seats);
        printf("\n");
    }
}
int main() {
    int num;
    struct travel t1[3] = {
    {"MalaysiaWonder", "Malaysia", 4, 2500, 10},
    {"NorthPakistan", "Pakistan", 5, 4000, 4},
    {"TheExpress", "England", 3, 5000, 5}
     };

    display(t1);
    printf("Enter '1' if you want the MalaysiaWonder package\n");
    printf("Enter '2' if you want the NorthPakistan package\n");
    printf("Enter '3' if you want the TheExpress package\n");
    scanf("%d", &num);
    switch(num){
        case 1:
        t1[0].seats--;
        printf("1 seat booked for Malaysia!");
        printf("Seats left for Malaysia now: %d",t1[0].seats);
        break;
        case 2:
        t1[1].seats--;
        printf("1 seat booked for Pakistan!");
        printf("Seats left for Pakistan now: %d",t1[1].seats);
        break;
        case 3:
        t1[2].seats--;
        printf("1 seat booked for England!");
        printf("Seats left for England now: %d",t1[2].seats);
        break;
        default: printf("ERROR!");
    }
    
    
    
}
