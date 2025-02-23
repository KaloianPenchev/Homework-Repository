#include<stdio.h>

#define DEBUG

void sort(int size, int arr[]){
    for(int i  = 0 ; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }

    int sum = 0;

    #if defined DEBUG
    for(int i = 0; i < size; i++){
        if(i % 3 == 0){
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    #endif

    for(int i = 0; i < size; i++){
        if(i % 3 == 0){
            sum +=arr[i];
        }
    }

    printf("%d", sum);

}


int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    sort(n, arr);
}