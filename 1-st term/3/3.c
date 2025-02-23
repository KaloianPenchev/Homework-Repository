#include<stdio.h>

void bubble_sort(int size, int arr[]){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }
}


void selection_sort(int size, int arr[]) {
    for (int i = 0; i < size - 1; i++) {
        int min_ind = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min_ind])
                min_ind = j;
        int swap = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = swap;
    }
}


void insertion_sort(int size, int arr[]) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}



int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    #if defined(_WIN32)
    bubble_sort(n, arr);
    #elif defined(__linux__)
    selection_sort(n, arr);
    #elif defined(__APPLE__)
    insertion_sort(n, arr);
    #endif


    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }


    return 0;



}