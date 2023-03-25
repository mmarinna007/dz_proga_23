#include <stdio.h>

int main () {
    char times [10];
    char number;
    while ((number = getchar()) != '\n') {
        if (number >= 0 && number <= 9) {
            times[number]++;
        }
    }

    for (int i = 0; i <= 9; i++) {
        char line[100];
        int count_line = 0;
        for (int j = 0; j < times[i]; j++) {
            line[count_line] = '#';
            count_line++;
        }
        line[count_line] = '\0';
        printf("%i": "%s\n", i, line);
    }

    int max_amount = 0;
    for (int i = 0; i <= 9; i++) {
        int a = times[i];
        if (a > max_amount) {
            max_amount = a;
        }
    }

    for (i = max_amount; i >= 1; i--) {
        char line[100];
        int count_line = 0;
        for (j = 0; j <= 9; j++) {
            if (times[j] >= i) {
                line[count_line] = '#';
            }
            else {
                line[count_line] = ' ';
            }
            count_line++;
            line[count_line] = ' ';
            count_line++;
        }
        line[count_line] = '\0';
        printf("%s", line);
    }
    printf("0 1 2 3 4 5 6 7 8 9\n");
}