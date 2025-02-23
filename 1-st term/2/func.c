#include<stdio.h>

#define COMMAND(NAME, TYPE) TYPE ## _ ## NAME ## _command
#define DEFINE_COMMAND(NAME, TYPE) void COMMAND(NAME, TYPE) (void)

DEFINE_COMMAND(func1, type1){
    printf("HELLO1 ");
}
DEFINE_COMMAND(func2, type2){
    printf("HELLO2");
}

int main(){

    type1_func1_command();
    type2_func2_command();
    return 0;
}
