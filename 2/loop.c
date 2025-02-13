#include <stdio.h>

#define SWAP(A, B, TYPE) { TYPE TEMP = A; \
                           A = B;          \
                           B = TEMP; }

#define SORT(ARRAY, SIZE, TYPE, COMPARE) \
                        for(TYPE i = 0; i < SIZE; i++) { \
                            for(TYPE j = 0; j < SIZE - i - 1; j++) { \
                                if((ARRAY[j]) COMPARE (ARRAY[j + 1])) { \
                                    SWAP(ARRAY[j], ARRAY[j + 1], TYPE); \
                                } \
                            } \
                        }

int main() {
    int array[5] = {5, 2, 9, 1, 6}; 
    SORT(array, 5, int, >);  

    
    for(int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
