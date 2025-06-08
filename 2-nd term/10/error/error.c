#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void assert_memory_allocation(void * ptr){
    if(!ptr){
        printf("Failed to allocate memory!");
        exit(ERROR_ALLOCATING_MEMORY);
    }
}

void assert_file_opening(void * ptr){
     if(!ptr){
        printf("Failed to open file!");
        exit(ERROR_OPENING_FILE);
    }
}

void assert_index(const unsigned int size, const unsigned int index){
    if(index < 0 || index > size){
        printf("Index out of bounds!");
        exit(ERROR_ASSERTING_INDEX);
    }
}
