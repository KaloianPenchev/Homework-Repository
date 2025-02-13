#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transformation.h"

transformation string_to_int(char str[]) {
    transformation res;
    res.result = 0;
    res.error[0] = '\0';
    
    int length = strlen(str);
    int is_negative = 0;
    int start_index = 0;

    if (str[0] == '-') {
        is_negative = 1;
        start_index = 1;
    }

    for (int i = start_index; i < length; i++) {
        if (str[i] < '0' || str[i] > '9') {
            strcpy(res.error, "Invalid input string");
            return res;
        }
    }
    
    for (int i = start_index; i < length; i++) {
        res.result = res.result * 10 + (str[i] - '0');
    }

    if (is_negative) {
        res.result = -res.result;
    }

    return res;
}
