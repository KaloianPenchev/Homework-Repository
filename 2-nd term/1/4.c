#include<stdio.h>

int comparasc(const void * const ptr1, const void * const ptr2){
    const int * const utilptr1 = ptr1;
    const int * const utilptr2 = ptr2;

    if(* utilptr1 > * utilptr2){
        return 1;
    }
    else if(* utilptr1 < * utilptr2){
        return -1;
    }

    return 0;
}

int comparedecs(const void * const ptr1, const void * const ptr2){
    const int * const utilptr1 = ptr1;
    const int * const utilptr2 = ptr2;

    if(* utilptr1 > * utilptr2){
        return -1;
    }
    else if(* utilptr1 < * utilptr2){
        return 1;
    }

    return 0;
}

int main(){

    int a, b;

    printf("Enter value for the first const variable: ");
    scanf("%d", &a);

    printf("Enter value for the second const variable: ");
    scanf("%d", &b);

    const void * const ptr1 = &a;
    const void * const ptr2 = &b;

    printf("Comparison №1: %d\n", comparasc(ptr1, ptr2));
    printf("Comparison №2: %d", comparedecs(ptr1, ptr2));

    return 0;
}