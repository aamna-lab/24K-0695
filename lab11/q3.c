#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rep_word_in_str(char *str, const char *old, const char *new) {
    char buf[1024];
    char *pos;
    int old_len = strlen(old);
    int new_len = strlen(new);
    int i = 0;

    while ((pos = strstr(str, old)) != NULL) {
        strncpy(buf + i, str, pos - str);
        i += pos - str;
        strncpy(buf + i, new, new_len);
        i += new_len;
        str = pos + old_len;
    }

    strcpy(buf + i, str);
    strcpy(str - (i - strlen(buf)), buf);
}

void rep_word_in_file(const char *filename, const char *old, const char *new) {
    FILE *f = fopen(filename, "r+");
    if (f == NULL) {
        perror("Error opening file");
        return;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *content = (char *)malloc(size + 1);
    fread(content, 1, size, f);
    content[size] = '\0';

    rep_word_in_str(content, old, new);

    fseek(f, 0, SEEK_SET);
    fwrite(content, 1, strlen(content), f);

    free(content);
    fclose(f);
}

int main() {
    const char *file = "example.txt";
    const char *old = "oldword";
    const char *new = "newword";

    rep_word_in_file(file, old, new);

    printf("Word replacement complete.\n");
    return 0;
}
