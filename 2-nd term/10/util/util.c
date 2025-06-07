#include <stdio.h>
#include <stdlib.h>
#include "util.h"

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
    if(index < 0 || index >= size){
        printf("Index out of bounds!");
        exit(ERROR_ASSERTING_INDEX);
    }
}

const char* education_level_to_string(EducationLevel level) {
    switch (level) {
        case EDUCATION_NONE: return "None";
        case EDUCATION_PRIMARY: return "Primary";
        case EDUCATION_SECONDARY: return "Secondary";
        case EDUCATION_HIGHER: return "Higher";
        default: return "Unknown";
    }
}

const char* work_status_to_string(WorkStatus status) {
    switch (status) {
        case WORK_UNEMPLOYED: return "Unemployed";
        case WORK_EMPLOYED: return "Employed";
        default: return "Unknown";
    }
}

const char* marital_status_to_string(MaritalStatus status) {
    switch (status) {
        case MARITAL_SINGLE: return "Single";
        case MARITAL_MARRIED: return "Married";
        default: return "Unknown";
    }
}