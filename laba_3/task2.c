#include <stdio.h>

void del(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                s1[i] = s1[amount1-1];
                s1[amount1-1] = "\0";
            }
        }
    }
}

int main () {
    char s1[100];
    char s2[100];
    int amount1 = 0;
    int amount2 = 0;
    while (1) {
        char s1_letters = getchar();
        if (s1 != '\n') {
            s1[amount1] = s1_letters;
            amount1++;
        }
        else {
            s1[amount1] = '\0';
            break;
        }
    }

    while (1) {
        char s2_letters = getchar();
        if (s2 != '\n') {
            s2[amount2] = s2_letters;
            amount2++;
        }
        else {
            s2[amount2] = '\0';
            break;
        }
    }
    
    del(s1, s2);
    printf("%s\n", s1);
    return 0;
}