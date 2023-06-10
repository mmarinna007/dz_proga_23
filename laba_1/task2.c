#include <stdio.h>

int len(char a[]) {
    int i;
    for (i = 0; a[i] != '\0'; ++i);
    return i;
}

void pr_string(int len) {
    for (int i = 0; i < len; ++i) {
        printf("*");
    }
}

int main() {
    char name[50];
    scanf("%s", name);
    int len_name = len(name);

    pr_string(len_name + 2);
    printf("\n");

    printf("*%s*", name);

    printf("\n");
    pr_string(len_name + 2);
    return 0;
}