#include <stdio.h>
struct Company{
    int year_established;
    char *departments[5];
};
int main(){
    struct Company c1;
    c1.year_established = 1986;
    c1.departments[0]="Marketing";
    c1.departments[1]="Human Resources";
    c1.departments[2]="IT";
    c1.departments[3]="Sales";
    c1.departments[4]="Finances";
    printf("Our Company established in %d\n",c1.year_established);
    for(int i=0;i<5;i++){
        printf("Department Name= %s\n", c1.departments[i]);
    }
}
