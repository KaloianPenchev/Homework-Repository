#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "person.h"

struct SchoolRoom{
    int room_number;
    struct Person people[50];
};

#endif
