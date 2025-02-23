#include<stdio.h>

#include "SchoolClass.h"
#include "SchoolRoom.h"

struct School{
    struct SchoolClass classes[20];
    struct SchoolRoom rooms[10];
};

int main(){
    struct School myschool;
    
    return 0;
}