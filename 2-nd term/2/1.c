#include<stdio.h>

int str_len(char *str){
    int len = 0;

    for(char *ptr = str; * ptr != '\0'; ptr++){
        len++;
    }

    return len;
}

int main(){
    char str[] = "Hello World!";
    char *ptr = str;

    int lenght = str_len(ptr);

    printf("Lenght: %d", lenght);

    return 0;
}