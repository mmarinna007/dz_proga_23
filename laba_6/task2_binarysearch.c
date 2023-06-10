#include <stdio.h>

int bsearch_r (int *a, int x, int i, int j) {
    if (j < i) {
        return -1;
    }
    int k = i + ((j - i) / 2);
    if (a[k] == x) {
        return k;
    }
    else if (a[k] < x) {
        return bsearch_r(a, x, k + 1, j);
    }
    else {
        return bsearch_r(a, x, i, k - 1);
    }
}

int main () {
    int a[] = {-31, 0, 1, 2, 2, 4, 65, 83, 99, 782};
    int n = sizeof a / sizeof a[0];
    int x;
    printf("Enter ЖЕЛАЕМОЕ value: ");
    scanf("%d", &x);
  
    int i = bsearch_r(a, x, 0, n - 1);
    if (i >= 0)  
      printf("%d is at index %d.\n", x, i);
    else
      printf("%d is not found.\n", x);
    return 0;
}