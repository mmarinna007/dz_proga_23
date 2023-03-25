#include <stdio.h>

int main() {
int char_exists = 0;
int sym;

while (sym = getchar()) {
    if (sym != ' ' && sym != '\t') {
        if (sym != '\n') {
            char_exists = 1;
        }
        
        if (char_exists == 1) {
            putchar(sym);
            if (sym == '\n') {
                char_exists = 0;
            }
        }
    }
    else if (sym == '\0') {
        break;
    }
}
}