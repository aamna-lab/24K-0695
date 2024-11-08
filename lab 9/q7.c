#include <stdio.h>
#include <string.h>
void sort(char a[5][20], int n) {
    char temp[20];
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i][0] > a[j][0]) {
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
        }
    }
}
int main() {
    char w[5][20];
    int n = 5, i;
    for (i = 0; i < n; i++) {
        scanf("%s", w[i]);
    }
    sort(w, n);
    for (i = 0; i < n; i++) {
        printf("%s\n", w[i]);
    }
}
