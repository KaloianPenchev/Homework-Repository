#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include "../citizen/citizen.h"

typedef enum {
    ERROR_ALLOCATING_MEMORY = 1,
    ERROR_OPENING_FILE,
    ERROR_ASSERTING_INDEX
} Error;

void assert_memory_allocation(void * ptr);

void assert_file_opening(void * ptr);

void assert_index(const unsigned int size, const unsigned int index);

#endif