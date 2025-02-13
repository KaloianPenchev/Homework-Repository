#include<math.h>
#include<stdio.h>

#define ARR_SIZE 3

int fillArr(long arr[]){
    for(int i = 0; i < ARR_SIZE; i++){
        arr[i] = pow(arr[i], 4);
    }
}

int main(){
    long arr[] = {1, 2, 3};

    fillArr(arr);

    for(int i = 0; i < ARR_SIZE; i++){
        printf("%ld ", arr[i]);
    }

    return 0;
}