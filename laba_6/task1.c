#include <stdio.h>

#define SWAP(p1, p2, typeSize) \
{ \
    int size = typeSize; \
    char *cp1 = p1; \
    char *cp2 = p2; \
    while (size > 0) { \
        char buf = *cp1;\
        *cp1 = *cp2; \
        *cp2 = buf; \
        cp1++; \
        cp2++; \
        size--; \
    } \
}

int f(int x)
{
  return x * x;
}

int main() {
    int a = 10;
    int b = 20;
    SWAP(&a, &b, sizeof(int));
    printf("a = %d\n", a);
  printf("b = %d\n", b);
}