#include<stdio.h>

#define COLS 4

void printArr(int (*ptr)[COLS], int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < COLS; j++){
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }
}

int main(){
    int arr[2][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };

    int (*ptr)[COLS] = arr;

    printArr(ptr, 2);
    
    return 0;
}