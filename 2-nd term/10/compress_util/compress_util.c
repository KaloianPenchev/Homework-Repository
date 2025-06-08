#include "compress_util.h"
#include <string.h>
#include <ctype.h>

void remove_spaces(char *str){
    int len = strlen(str);

    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        len--;
    }

    str[len] = '\0'; 
}

char * compress_info(char * buffer, int el, int ws, int ms) {
    
    *buffer = (el & 0x03)       // bits 0-1
            | ((ws & 0x01) << 2) //  bit 2
            | ((ms & 0x01) << 3); // bit 3

    return buffer;
}