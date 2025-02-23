#include<stdio.h>

void bubblesort(int arr[], int arr_sz, 
    int (* compare) (const void * const, const void * const), 
    void (* swapelements) (void *, void * )){
    

    for(int i = 0; i < arr_sz - 1; i++){
        for(int j = 0; j < arr_sz - i - 1; j++){
            if(compare(&arr[j], &arr[j + 1])){
                swapelements(&arr[j], &arr[j + 1]);
            }
        }
    }

}

int compare_increasing(const void * const ptr1, const void * const ptr2){
    const int * const utilptr1 = ptr1;
    const int * const utilptr2 = ptr2;

    if(* utilptr1 > * utilptr2){
        return 1;
    }
    
    return 0;
}

int compare_decreasing(const void * const ptr1, const void * const ptr2){
    const int * const utilptr1 = ptr1;
    const int * const utilptr2 = ptr2;

    if(* utilptr1 < * utilptr2){
        return 1;
    }

    return 0;
}


void swap(void * ptr1, void * ptr2){
    
    int * utilptr1 = ptr1;
    int * utilptr2 = ptr2;

    int c = * utilptr1;
    * utilptr1 = * utilptr2;
    * utilptr2 = c;
}
int main(){
    int arr[5] = {2, 3, 1, 9, 4};

    bubblesort(arr, 5, compare_increasing, swap);

    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    bubblesort(arr, 5, compare_decreasing, swap);

    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}