#include <stdio.h>

int main () {
    int times [10] = {0};
    char number;
    while ((number = getchar()) != '\n') {
        if (number >= '0' && number <= '9') {
            times[number-48]++;
        }
    }

   for (int i = 0; i <= 9; i++) {
        printf("%d: ", i);
        for (int j = 0; j < times[i]; j++) {
            printf("#");
        }
        printf("\n");
    }

    int max_count = 0;
    for (int i = 0; i <= 9; i++) {
        int a = times[i];
        if (a > max_count) {
            max_count = a;
        }
    }

    for  (; max_count > 0; max_count--) {
        for (int i = 0; i < 10; i++) {
            printf(times[i] >= max_count ? "# " : "  ");
        }
        printf("\n");
    }
    printf("0 1 2 3 4 5 6 7 8 9\n\n");
    return 0;
}