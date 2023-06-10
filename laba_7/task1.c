#include <stdio.h>
#include <stdlib.h>


void ShellSort(int n, int *mass)
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}


  

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d\n", arr[i]);
}
void rand_array(int *arr, int n)
{
   int i;
   for (i = 0; i < n; ++i)
      scanf("%d", &arr[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    rand_array(arr, n);
   
    ShellSort(n, arr);
    printf("\n");
    printArr(arr, n);
    free(arr);
    return 0;
}
