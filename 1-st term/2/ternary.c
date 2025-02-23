#include<stdio.h>

#define COMPARE(X, Y) ((X > Y) ? X : Y)


int main(){

    int a = 1, b = 2;

    printf("%d", COMPARE(a, b));
    return 0;
}