#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int p, int q, int r) {

  
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }


  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}



void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    
    merge(arr, l, m, r);
  }
}


void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%4d ", arr[i]);
    printf("\n");
}
void rand_array(int *arr, int n)
{
   int i;
    for (i = 0; i < n; ++i)
      arr[i] = rand() % 100 - 50;
    
}

int main()
{
    int n;
    printf("Enter size> ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    rand_array(arr, n);
    printArr(arr, n);
    printf("\n\n");
  mergeSort(arr, 0, n - 1);

  printf("Sorted array: \n");
  printArr(arr, n);
  free(arr);
}