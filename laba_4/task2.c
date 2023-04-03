#include <stdio.h>

int main() {
    int a;
    scanf("%i", &a);
	int b = 1;
	int i = 0;
	while (i < 31 && b < a) {
	    i++;
	    b <<= 1;
	}
	if (b != a && i != 31) {
	    b >>= 1;
	}
	
	int c = 0;
	b >>= 1;

	while (b > 0) {
		int k = a & b;
	    if (k > 0) {
	        c += 1;
	    }
	    b >>= 2;
	}
	printf("%d\n", c);
}
