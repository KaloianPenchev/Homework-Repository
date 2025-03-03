#include<stdio.h>
#include<string.h>

void strhalf(char str[], char ** ptr){
    if(ptr == NULL){
        return;
    }
    
    int mid = strlen(str) / 2;

    *ptr = str + mid;
}


int main(){
    char str[] = "Tues";
    char *ptr;

    strhalf(str, &ptr);

    printf("%s\n", ptr);

    return 0;
}