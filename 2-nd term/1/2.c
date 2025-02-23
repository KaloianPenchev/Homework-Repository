#include <stdio.h>
#include <string.h>

int main() {
    char string[20];

    fgets(string, sizeof(string), stdin);

    
    char *ptr = strchr(string, '\n');
    if (ptr != NULL) {
        *ptr = '\0';
    }

    
    printf("%s\n", string);

    return 0;
}
