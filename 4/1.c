#include<stdio.h>

#define SUM(A, B) (((A) + (B)) * ((A) + (B)))

int main(){

    int x = 1, y = 2;

    printf("%d", SUM(x, y));

    return 0;
}