#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strend(char *s, char *t) {
    
    int len_s = strlen(s);
    int len_t = strlen(t);
    if (len_t <= len_s) {
        for (int i = len_t - 1; i >= 0; i--){
            if (t[i] != s[i-len_t+len_s]) {
                return 0;
            }
        } 
        return 1;
    }
    else {
        return 0;
    }
}
char* reading()
{
  char *str = malloc(sizeof(char) * 11);
  int n = 0;
  while (scanf("%10[^\n]", str + 10*n) == 1) {
    n++;
    str =  realloc(str, sizeof(char) * (10*n + 11));
  }
  char delete_blocking_sym;
  scanf("%c", &delete_blocking_sym);
  if (n == 0) {
    free(str);
    return NULL;
  }
  n--;
  str = realloc(str, sizeof(char) * (10*n + strlen(str + 10 * n) + 1));     
  return str;
}

int main()
{
  char *s = reading();
  char *t = reading();
  int result = strend(s, t);
  free(s);
  free(t);
  printf("%i\n", result);
  
}
