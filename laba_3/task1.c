#include <stdio.h>
#include <ctype.h>
#define FREE (0)
int main() {
    char i;
    char start = FREE;
    char end;
    int direction;
    int space = 1;
    while((i = getchar()) != 0) {
       if (isalnum(i) != 0) {
           if (start == FREE) {
               start = i;
           }
           else {
               end = i;
               if (start - end < 0) {
                   direction = 1;
               }
               else {
                   direction = -1;
               }
               for (i = start; i != end; i += direction) {
                   putchar(i);
               }
               i = getchar();
               if (i == '-') {
                   start = end;
               }
               else {
                   putchar(end);
                   start = (isalnum(i)) ? i : FREE;
               }
           }
       }
       else if (start == FREE) {
           putchar(i);
       }
    }
}