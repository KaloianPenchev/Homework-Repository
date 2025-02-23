#include<stdio.h>

void swap_variables_through_pointers(void * ptr1, void * ptr2){
    
    int * utilptr1 = ptr1;
    int * utilptr2 = ptr2;

    int c = * utilptr1;
    * utilptr1 = * utilptr2;
    * utilptr2 = c;
}

int main(){
    int a, b;

    printf("Enter value for the first variable: ");
    scanf("%d", &a);

    printf("Enter value for the second variable: ");
    scanf("%d", &b);

    void * ptr1 = &a;
    void * ptr2 = &b;

    swap_variables_through_pointers(ptr1, ptr2);

    printf("Value for the first variable: %d\n", a);
    printf("Value for the second variable: %d", b);
}