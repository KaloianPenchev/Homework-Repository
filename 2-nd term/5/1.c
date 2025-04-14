#include<stdio.h>

typedef unsigned long long ull;
typedef ull(*function)(ull x, ull y);

ull reduce(ull arr[], ull arr_size, function fptr, ull initial_value){
    ull result = initial_value;

    for(ull i = 0; i < arr_size; i++){
        result = fptr(result, arr[i]);
    }

    return result;
}   

ull add(ull x, ull y){
    return x + y;
}

int main(){
    ull arr[3] = {1, 2, 3};

    ull reduced_val = reduce(arr, 3, add, 0);

    printf("%llu", reduced_val);

    return 0;
}