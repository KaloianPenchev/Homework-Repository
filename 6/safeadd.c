#include<stdio.h>
#include<stdlib.h>
#include"safeint.h"

int main(int argc, char* argv[]){
    if(argc > 3){
        printf("Too many arguments!");
        return -1;
    }
    
    SafeResult num1;
    SafeResult num2;
    
    num1 = safestrtoint(argv[1]);
    num2 = safestrtoint(argv[2]);
    if (num1.errorflag != 0 || num2.errorflag != 0) {
        printf("The inputs are invalid (either integer overflow/underflow or containing letters)!\n");
        return -1;
    }

    SafeResult res;
    
    res = safeadd(num1.value, num2.value);

    printf("%d\n", res.value);
    printf("%d\n", res.errorflag);

    return 0;
}