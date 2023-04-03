#include <stdio.h>


int to_num(char *s1) {
    int result = 0;
    for (int j = 0; s1[j] != '\0'; j++) {
      int hex_val;
      if (s1[j] >= '0' && s1[j] <= '9') {
          hex_val = s1[j] - '0';
      }
      else if (s1[j] >= 'a' && s1[j] <= 'f') {
          hex_val = s1[j] - 'a' + 10;
      }
      else if (s1[j] >= 'A' && s1[j] <= 'F') {
          hex_val = s1[j] - 'A' + 10;
      }
      else {
          continue;
      }
      result <<= 4;
      result |= hex_val;
    }
    return result;
}
int main() {
    char s1[100];
    int i;
    for (i = 0;; i++) {
        s1[i] = getchar();
        if (s1[i] == '\n') {
            s1[i] == '\0';
            break;
        }
    }
    int a = to_num(s1);
    printf("%i\n", a);
}
