#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee/employee.h"
#include "error/error.h"

void write_employee_to_file(FILE* file, Employee* employee) {
    if (employee == NULL) {
        return;
    }

    size_t name_len = strlen(employee->name) + 1;
    fwrite(&name_len, sizeof(size_t), 1, file);
    fwrite(employee->name, sizeof(char), name_len, file);
    fwrite(&employee->subordinates_count, sizeof(unsigned int), 1, file);

    for (unsigned int i = 0; i < employee->subordinates_count; i++) {
        write_employee_to_file(file, employee->subordinates[i]);
    }
}

Employee* create_employee(const char* name, unsigned int num_subordinates, Employee** subordinates) {
    Employee* new_employee = (Employee*)malloc(sizeof(Employee));
    assert_memory_allocation(new_employee);

    strncpy(new_employee->name, name, MAX_NAME_LEN);
    new_employee->subordinates_count = num_subordinates;
    new_employee->subordinates = subordinates;

    return new_employee;
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
    
    Employee* workers1[] = {
        create_employee("Worker 1", 0, NULL),
        create_employee("Worker 2", 0, NULL),
        create_employee("Worker 3", 0, NULL)
    };
    Employee* workers2[] = {
        create_employee("Worker 4", 0, NULL),
        create_employee("Worker 5", 0, NULL),
        create_employee("Worker 6", 0, NULL)
    };

    
    Employee** manager1_subs = malloc(sizeof(Employee*) * 3);
    memcpy(manager1_subs, workers1, sizeof(Employee*) * 3);
    Employee* manager1 = create_employee("Manager 1", 3, manager1_subs);

    Employee** manager2_subs = malloc(sizeof(Employee*) * 3);
    memcpy(manager2_subs, workers2, sizeof(Employee*) * 3);
    Employee* manager2 = create_employee("Manager 2", 3, manager2_subs);

    
    Employee** director_subs = malloc(sizeof(Employee*) * 2);
    director_subs[0] = manager1;
    director_subs[1] = manager2;
    Employee* director = create_employee("Director", 2, director_subs);

    
    FILE* file = fopen("employees.bin", "wb");
    assert_file_opening(file);
    write_employee_to_file(file, director);
    fclose(file);
    
    
    free_employee_hierarchy(director);

    printf("Employee hierarchy serialized successfully to employees.bin\n");

    return 0;
} 