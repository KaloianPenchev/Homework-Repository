#include<stdio.h>
#include "mystrings.h"

int main(int argc, char ** argv){

    if(argc > 2){
        printf("Too many arguments!");
        return 0;
    }
    else{
        strlenght(argv[1]);
    }

    return 0;
}