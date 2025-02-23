#include<stdio.h>

int main(){
    double a, b;

    printf("Enter value for the first variable: ");
    scanf("%lf", &a);

    printf("Enter value for the second variable: ");
    scanf("%lf", &b);

    double * ptr1 = &a;
    double * ptr2 = &b;

    printf("Address of the first pointer: %p\n", &ptr1);
    printf("Address of the second pointer: %p\n", &ptr2);

    printf("Value of the first variable trought the pointer: %lf\n", * ptr1);
    printf("Value of the second variable trought the pointer: %lf\n", * ptr2);

    return 0;
}