#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void check_memory_allocation(void * ptr){
    if(ptr == NULL){
        printf("Error allocating memory!");
        exit(1);
    }
}

void check_file_opening(void * ptr){
    if(ptr == NULL){
        printf("Error opening the file!");
        exit(1);
    }
}

void check_index_bounds(const unsigned int size, const unsigned int index){
    if(index < 0 || index > size){
        printf("Index out of bounds!");
        exit(1);
    }
}