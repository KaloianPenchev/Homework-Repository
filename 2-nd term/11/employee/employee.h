#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_NAME_LEN 100

typedef struct Employee {
    char name[MAX_NAME_LEN];
    unsigned int subordinates_count;
    struct Employee** subordinates;
} Employee;

#endif 