#include <stdio.h>
#include <stdlib.h>
  

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  

int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
  
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
  

void insertionSort(int *arr, int n)
{
   
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i]; 
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j = j - 1;
        }
        arr[j + 1] = key; 
    }
}
 
void quickSortIterative(int arr[], int l, int h)
{
    
    int stack[h - l + 1];
  
    
    int top = -1;
  
   
    stack[++top] = l;
    stack[++top] = h;
  
    
    while (top >= 0) {
        
        h = stack[top--];
        l = stack[top--];
        
        if (h - l + 1 <= 15) {
            insertionSort(arr + l, h - l + 1);
        }
        else {
            int p = partition(arr, l, h);
            if (p - 1 > l) {
                stack[++top] = l;
                stack[++top] = p - 1;
            }
      
            
            if (p + 1 < h) {
                stack[++top] = p + 1;
                stack[++top] = h;
            }
        }
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
    quickSortIterative(arr, 0, n - 1);
    
    printArr(arr, n);
    free(arr);
    return 0;
}