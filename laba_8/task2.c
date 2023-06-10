#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArr(char **arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%s\n", arr[i]);
}
void ShellSort(int n, char **mass)
{
    int i, j, step;
    char* tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (strlen(tmp) < strlen(mass[j - step]))
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}
char* reading()
{
  char *str = malloc(sizeof(char) * 11);
  int n = 0;
  while (scanf("%10[^ \n]", str + 10*n) == 1) {
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
int main() {
  int n;
  scanf("%i", &n);
  char delete_blocking_sym;
  scanf("%c", &delete_blocking_sym);
  char **mass = malloc(sizeof(char*) * n);
  for (int i = 0; i < n; i++) {
    mass[i] = reading();
  }
  ShellSort(n, mass);
  printArr(mass, n);
  for (int i = 0; i < n; i++) {
    free(mass[i]);
  }
  free(mass);
}
