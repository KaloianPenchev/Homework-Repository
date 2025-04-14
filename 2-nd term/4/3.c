#include <stdio.h>
#include <stdlib.h>


int isEven(int x){
    if(x % 2 == 0) return 1;
    return 0;
}

int isOdd(int x){
    if(x % 2 == 1) return 1;
    return 0;
}


void check_memory(void *ptr) {
    if(ptr == NULL) {
        printf("Error allocating memory!\n");
        exit(1); 
    }
}

int * filter(int *array, int numbers_count,  int (*callback)(int)){

    int *filtered_array = (int *) malloc(numbers_count * sizeof(int));
    check_memory(filtered_array);

    for(int i = 0; i < numbers_count; i++){
        if(callback(array[i])){
            filtered_array[i] = array[i];
        }
        else{
            filtered_array[i] = 0;
        }
    }

    return filtered_array;
}


int main() {
    int numbers_count = 0;

    printf("Enter numbers count: ");
    scanf("%d", &numbers_count);

    int *array = (int *) malloc(numbers_count * sizeof(int));
    check_memory(array);

    for(int i = 0; i < numbers_count; i++) {
        printf("Enter number #%d : ", i + 1);
        scanf("%d", &array[i]);
    }


    int * res_even = filter(array, numbers_count, isEven);

    for(int i = 0; i < numbers_count; i++){
        printf("%d ", res_even[i]);
    }

    printf("\n");

    int * res_odd = filter(array, numbers_count, isOdd);

    for(int i = 0; i < numbers_count; i++){
        printf("%d ", res_odd[i]);
    }
    
    free(array);
    free(res_even);
    free(res_odd);

    return 0;
}