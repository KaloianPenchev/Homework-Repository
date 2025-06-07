#ifndef UTIL_H
#define UTIL_H

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

const char* education_level_to_string(EducationLevel level);
const char* work_status_to_string(WorkStatus status);
const char* marital_status_to_string(MaritalStatus status);

#endif