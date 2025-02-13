#include<stdio.h>
#include <string.h>
#include "mystrings.h"

int main(int argc, char ** argv){
    if(argc > 3){
        printf("Too many arguments!");
        return 0;
    }
    else if( strlen(argv[1]) > 50 || strlen(argv[2]) > 50){
        printf("Strings must be under 50 characters!\n");
        return 0;
    }
    else{
        strconcat(argv[1], argv[2]);
    }
    
    return 0;
}