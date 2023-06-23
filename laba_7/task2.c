#include <stdio.h>
#include <stdlib.h>


char* reading()
{
  char *str = malloc(sizeof(char) * 11);
  int n = 0;
  while (scanf("%10[^ \n]", str + 10*n) == 1) {
    n++;
    str =  realloc(str, sizeof(char) * (10*n + 11));
  }
  if (n == 0) {
    free(str);
    return NULL;
  }
  n--;
  str = realloc(str, sizeof(char) * (10*n + strlen(str + 10 * n) + 1));     
  return str;
}
int main() {
  char *l = reading();
  if (l != NULL) {
    printf("%s\n", l);
    free(l);
  }
}
