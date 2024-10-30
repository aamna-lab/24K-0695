
#include <stdio.h>
int main(){
    int m1[3][3];
    int m2[3][3];
    int m3[3][3];
    int m4[3][3];
    for(int i=0;i<3;i++){ //for matrix1
        for(int j=0;j<3;j++){
            printf("Enter value in %d row and %d column in matrix 1--",i,j);
            scanf("%d", &m1[i][j]);
            
        }
    }
    for(int i=0;i<3;i++){ //for matrix2
        for(int j=0;j<3;j++){
            printf("Enter value in %d row and %d column in matrix 2--",i,j);
            scanf("%d", &m2[i][j]);
            
        }
    }
    for( int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            m3[i][j]=m1[i][0]*m2[0][j] + m1[i][1]*m2[1][j] + m1[i][2]*m2[2][j];
             printf(" new matrix with %d row and %d column is %d\n", i,j,m3[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            m4[i][j]=m3[i][j]-m1[i][j];
        }
    }
    printf("subtraction result is {%d %d %d , %d %d %d, %d %d %d}", m4[0][0],m4[0][1],m4[0][2],m4[1][0],m4[1][1],m4[1][2],m4[2][0],m4[2][1],m4[2][2]);
    
    
}
