#include<stdio.h>

int main(){

    char string[20];

    fgets(string, sizeof(string), stdin);

    char * ptr = strchr(string, '\n');

    * ptr = '\0';

    for(size_t i = 0; i < sizeof(string); i++){
        printf("%c", string[i]);
    }
    
    return 0;
}