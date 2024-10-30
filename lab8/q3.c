#include <stdio.h>
int main(){
    int arr[3][3];
    int saddle;
    for(int i=0;i<3;i++){
        for( int j=0;j<3;j++){
            printf("Enter element in %d row and %d column \n", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for( int j=0;j<3;j++){
            int current=arr[i][j];
            saddle=1;
            for(int col=0;col<3;col++){
                if(arr[i]<current){
                    saddle=0;
                    break;
                }
            }if(saddle){
                for(int row=0;row<3;row++){
                    if(arr[row][j]>current){
                        saddle=0
                        break;
                    }
                }
               
            }
            if(saddle)
            printf("saddle found at %d row and %d column and it is %d\n",i,j,arr[i][j]);
            else 
            printf("no saddle");
        }
        
    }

}
