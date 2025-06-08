#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee/employee.h"
#include "error/error.h"

Employee* read_employee_from_file(FILE* file) {
    if (feof(file)) {
        return NULL;
    }

    Employee* employee = (Employee*)malloc(sizeof(Employee));
    assert_memory_allocation(employee);

    size_t name_len;
    if (fread(&name_len, sizeof(size_t), 1, file) != 1) {
        free(employee);
        return NULL; 
    }

    fread(employee->name, sizeof(char), name_len, file);
    fread(&employee->subordinates_count, sizeof(unsigned int), 1, file);

    if (employee->subordinates_count > 0) {
        employee->subordinates = (Employee**)malloc(sizeof(Employee*) * employee->subordinates_count);
        assert_memory_allocation(employee->subordinates);
        for (unsigned int i = 0; i < employee->subordinates_count; i++) {
            employee->subordinates[i] = read_employee_from_file(file);
        }
    } else {
        employee->subordinates = NULL;
    }

    return employee;
}

void print_hierarchy(Employee* employee, int level) {
    if (employee == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%s\n", employee->name);

    for (unsigned int i = 0; i < employee->subordinates_count; i++) {
        print_hierarchy(employee->subordinates[i], level + 1);
    }
}

void free_employee_hierarchy(Employee* employee) {
    if (employee == NULL) {
        return;
    }
    for (unsigned int i = 0; i < employee->subordinates_count; i++) {
        free_employee_hierarchy(employee->subordinates[i]);
    }
    free(employee->subordinates);
    free(employee);
}

int main() {
    FILE* file = fopen("employees.bin", "rb");
    assert_file_opening(file);

    Employee* director = read_employee_from_file(file);
    fclose(file);

    printf("Employee Hierarchy\n");
    print_hierarchy(director, 0);

    free_employee_hierarchy(director);

    return 0;
} 