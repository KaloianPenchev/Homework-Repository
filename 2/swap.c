#include<stdio.h>

#define SWAP(A, B, TYPE) { TYPE TEMP = A; \
                           A = B;          \
                           B = TEMP; }

int main() {
    int x = 1, y = 2;
    
    SWAP(x, y, int);
    printf("%d %d", x, y);

    return 0;
}
