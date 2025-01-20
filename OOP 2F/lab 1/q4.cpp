#include <iostream>
using namespace std;
int main(){
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = sizeof(height) / sizeof(height[0]);
    int sPos =0, ePos = size -1, maxArea = 0, currentArea;
    while(sPos < ePos){
        if(height[sPos] < height[ePos]){
            currentArea = height[sPos] * (sPos-ePos);
        }
        else if(height[sPos] > height[ePos]){
            currentArea = height[ePos] * (ePos - sPos);
        }
         if (currentArea > maxArea) {
            maxArea = currentArea;
        }
        if (height[sPos] < height[ePos]) {
            sPos++;
        } else {
            ePos--;
        }
    }
    cout << "Area: " << maxArea;
}
