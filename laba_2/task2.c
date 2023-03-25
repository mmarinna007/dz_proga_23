#include <stdio.h>

int main() {
    char i;
    int space = 1;
    while((i = getchar()) != 0) {
        if (i != ' ' && i != '\t') {
            putchar(i);
            space = 0;
        }
        else {
            space = space + 1;
            if (space == 1) {
                putchar('\n');
            }
        }
    }
}