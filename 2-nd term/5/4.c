#include <stdio.h>

typedef union {
    long odd;
    short even;
} type_union;

int isEven(int x){
    return x % 2 == 0;
}

void fill(type_union *arr, int size) {
    for(short i = 0; i < size; i++){
        if(isEven(i)){
            arr[i].even = i;
        } else {
            arr[i].odd = i;
        }
    }
}

void print(type_union *arr, int size) {
    
    for(int i = 1; i < size; i += 2){
        printf("%ld ", arr[i].odd);
    }
    printf("\n");

    
    for(int i = 0; i < size; i += 2){
        printf("%hd ", arr[i].even);
    }
    printf("\n");
}

int main(){
    type_union array[10];

    fill(array, 10);
    print(array, 10);

    return 0;
}
