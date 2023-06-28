#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArr(char **arr, int n)
{
    int i = 0;
    for (i = 0; i < n; ++i)
        (void)printf("%s\n", arr[i]);
}
void ShellSort(int n, char **mass)
{
    int i = 0, j = 0, step = 0;
    char* tmp = NULL;
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
  char delete_blocking_sym = 0;
  scanf("%c", &delete_blocking_sym);
  if (n == 0) {
    free(str);
    return NULL;
  }
  n--;
  str = realloc(str, sizeof(char) * (10*n + strlen(str + 10 * n) + 1));     
  return str;
}
int main(void) {
  int n = 0;
  (void)printf("Enter size of array: ");
  if (scanf("%i", &n) < 1) {
      (void)fprintf(stderr, "Failed scan integer\n");
      return 1;
  }

  char delete_blocking_sym = 0;
  (void)scanf("%c", &delete_blocking_sym);

  char **mass = malloc(sizeof(char*) * n);
  if (mass == NULL) {
      (void)fprintf(stderr, "Failed allocate memory\n");
      return 0;
  }
  for (int i = 0; i < n; i++) {
    
    mass[i] = reading();
  }
  ShellSort(n, mass);

  (void)printf("Sorted:\n");
  printArr(mass, n);
  for (int i = 0; i < n; i++) {
    free(mass[i]);
  }
  free(mass);
}
