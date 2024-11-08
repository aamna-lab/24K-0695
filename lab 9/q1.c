#include <stdio.h>
#include <string.h>
int main() {
    char w[5][20];
    int i, j, l, p;
    for (i = 0; i < 5; i++) {
        printf("Enter the %d position word\n",i);
        scanf("%s", w[i]);
    }
    for (i = 0; i < 5; i++) {
        l = strlen(w[i]);
        p = 1;
        for (j = 0; j < l / 2; j++) {
            if (w[i][j] != w[i][l - j - 1]) {
                p = 0;
                break;
            }
        }
        if (p) printf("Palindrome\n");
        else printf("Not Palindrome\n");
    }
}
