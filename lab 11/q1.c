#include <stdio.h>
void display(int arr[], int size) {
    if (size == 0) {
        return;
    }
    printf("%d ", arr[0]);
    display(arr + 1, size - 1);
}
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are: ");
    display(arr,n);
}
