#include <stdio.h>

void bubbleSort(int *arr, int arr_size, void (*swap_ptr)(int *, int *)) {
    for (int i = 0; i < arr_size - 1; i++) {
        for (int *j = arr; j < arr + arr_size - i - 1; j++) {  
            if (*j > *(j + 1)) {  
                swap_ptr(j, j + 1);  
            }
        }
    }
}


void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}


int main() {
    int arr[] = {8, 3, 5, 6, 4};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, arr_size, swap);

    for (int *ptr = arr; ptr < arr + arr_size; ptr++) {  
        printf("%d ", *ptr);
    }
    printf("\n");

    return 0;
}
