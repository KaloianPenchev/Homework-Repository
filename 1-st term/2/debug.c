#include <stdio.h>

#define DEBUG(X) #X, X, __FILE__, __LINE__

int main(){
    int something = 10;

    printf("name = %s, val = %d, file = %s, line = %d", DEBUG(something));

    return 0;
}
