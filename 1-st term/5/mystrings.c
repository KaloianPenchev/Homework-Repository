#include<stdio.h>
#include "mystrings.h"

void strlenght(char s[]){
    int lenght = 0;

    for(char c = 0; s[c] != '\0'; c++){
        lenght++;
    }

    printf("%s => %d", s, lenght);
}

void strconcat(char s1[], char s2[]) {
    int i = 0, j = 0;
    char s3[50];

    while (s1[i] != '\0') {
        s3[i] = s1[i];
        i++;
    }

    while (s2[j] != '\0') {
        s3[i] = s2[j];
        i++;
        j++;
    }
    
    s3[i] = '\0';

    printf("%s + %s => %s\n", s1, s2, s3);
}


int strcompare(char s1[], char s2[]) {
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        int curr = s1[i] - s2[i];
        if (curr < 0) {
            return -1;
        } else if (curr > 0) {
            return 1;
        }
        i++;
    }

    return 0;
}
