#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

typedef struct {
    long result;
    char error[100];
} transformation;

transformation string_to_int(char str[]);

#endif
