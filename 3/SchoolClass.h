#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include "person.h"

struct SchoolClass{
    struct Person students[26];
    int class_number;
    struct Person teacher;
};

#endif
