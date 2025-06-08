#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    ERROR_ALLOCATING_MEMORY = 1,
    ERROR_OPENING_FILE
} Error;

void assert_memory_allocation(void* ptr);
void assert_file_opening(void* ptr);

#endif