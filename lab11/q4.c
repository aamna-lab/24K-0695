#include <stdio.h>
struct Student{
    int roll_no;
    char name[40];
    struct Marks{
        int maths;
        int science;
        int english;
    }marks;
};
int main(){
    int avg;
    struct Student s1[5]= {
    {695 , "Aamna" , {70, 85 , 97}},
    {678 , "Zunairah" ,{87, 76 , 88}},
    {940, "Abeeha", {98 , 67, 78}}, 
    {644, "Laiba" , {87, 98, 88}},
    {765, "Hammad" , {67 , 74 , 76}}
    };
    for (int i=0; i<5 ; i++){
        avg=(s1[i].marks.maths+s1[i].marks.english+s1[i].marks.science)/3;
        printf("Name : %s\nRoll number : %d\nAverage Marks:%d\n\n", s1[i].name, s1[i].roll_no , avg);
    }

}
