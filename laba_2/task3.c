#include <stdio.h>

int main() {
    int count = 0;
    char i;
    char prev = 0;
    int j;
    while (1) {
        i = getchar();
        if (i == prev){
            count++;
        }
        else if (count >= 3) {
            for (j = 0; j < count; j++) 
                putchar(prev);
            count = 1;
        }
        else {
            count = 1;
        }
        if (i == 0) {
            break;
        }
        prev = i;
    }
}