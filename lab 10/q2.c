#include <stdio.h>
#include<math.h>
struct coordinates{
    int x1,x2;
    int y1,y2;
};
int distance(int x_2, int y_2, int x_1, int y_1){
    float answer,final;
    int x = x_2-x_1;
    int y = y_2-y_1;
    answer= pow(x,2)+pow(y,2);
    final= pow(answer,0.5);
    return final;
}
int main() {
    float d_final;
    int x1,y1,x2,y2;
    struct coordinates c1;
    printf("Enter 1st x-coordinate\n");
    scanf("%d", &c1.x1);
    printf("Enter 1st y-coordinate\n");
    scanf("%d", &c1.y1);
     printf("Enter 2nd x-coordinate\n");
    scanf("%d", &c1.x2);
    printf("Enter 2nd y-coordinate\n");
    scanf("%d", &c1.y2);
    if(c1.x1>10 || c1.x1<-100 || c1.x2>100 || c1.x2<-100 ||
    c1.y1>100 || c1.y1<-100 || c1.y2>100 || c1.y2<-100){
        printf("Input exceeding boundary");
        return 0;
    }
    d_final = distance (c1.x2,c1.y2,c1.x1,c1.y1);
    printf("Your distance between x and y points is %f ",d_final);}
