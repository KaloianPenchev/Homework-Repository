#include "maths.h"

int factoriel(int x){
    int res = 1;
    
    for(int i = 2; i <= x; i++){
        res *= i;
    }

    return res;
}