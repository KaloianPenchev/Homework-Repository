#include <stdio.h>
#include "transformation.h"

int main() {
    char test1[] = "-423";
    char test2[] = "12ab23";
    
    transformation res1 = string_to_int(test1);
    transformation res2 = string_to_int(test2);
    
    printf("%s => result: %ld, error: %s \n", test1, res1.result, res1.error);
    printf("%s => result: %ld, error: %s", test2, res2.result, res2.error);
    
    return 0;
}
