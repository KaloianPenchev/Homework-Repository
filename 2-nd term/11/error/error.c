#include "error.h"

void assert_memory_allocation(void* ptr) {
    if (!ptr) {
        printf("Failed to allocate memory!");
        exit(ERROR_ALLOCATING_MEMORY);
    }
}

void assert_file_opening(void* ptr) {
    if (!ptr) {
        printf("Failed to open file!");
        exit(ERROR_OPENING_FILE);
    }
} 