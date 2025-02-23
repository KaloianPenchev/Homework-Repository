#include<stdio.h>
#include"util.h"

void errormsg(char operation){
    printf("'%c' caused overflow/underflow!\n", operation);
}