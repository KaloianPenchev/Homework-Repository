#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../linked_list/linkedlist.h"
#include "../error/error.h"
#include "../compress_util/compress_util.h"

void eacher(unsigned int idx, ListDataType * value){
    printf("#%d\n", idx);
    printf("ID: %s\n", value->id);
    printf("Firstname: %s\n", value->name.firstname);
    printf("Surname: %s\n", value->name.surname);
    printf("Lastname: %s\n", value->name.lastname);
    
    printf("Education: ");
    switch (value->education_level) {
        case EDUCATION_NONE: printf("None\n"); break;
        case EDUCATION_PRIMARY: printf("Primary\n"); break;
        case EDUCATION_SECONDARY: printf("Secondary\n"); break;
        case EDUCATION_HIGHER: printf("Higher\n"); break;
        default: printf("Unknown\n"); break;
    }

    printf("Work Status: ");
    switch (value->work_status) {
        case WORK_UNEMPLOYED: printf("Unemployed\n"); break;
        case WORK_EMPLOYED: printf("Employed\n"); break;
        default: printf("Unknown\n"); break;
    }

    printf("Marital Status: ");
    switch (value->marital_status) {
        case MARITAL_SINGLE: printf("Single\n"); break;
        case MARITAL_MARRIED: printf("Married\n"); break;
        default: printf("Unknown\n"); break;
    }

    printf("\n");
}

void save_data_to_file(const char* filename, LinkedList* list) {
    FILE* file = fopen(filename, "wb");
    assert_file_opening(file);

    Node* current = list->head;
    int index = 0;
    while (current != NULL) {
        Citizen* citizen = &current->value;
        fwrite(&index, sizeof(int), 1, file);
        fwrite(citizen->id, sizeof(char), MAX_ID_LENGTH, file);

        size_t len = strlen(citizen->name.firstname);
        fwrite(&len, sizeof(size_t), 1, file);
        fwrite(citizen->name.firstname, sizeof(char), len, file);

        len = strlen(citizen->name.surname);
        fwrite(&len, sizeof(size_t), 1, file);
        fwrite(citizen->name.surname, sizeof(char), len, file);

        len = strlen(citizen->name.lastname);
        fwrite(&len, sizeof(size_t), 1, file);
        fwrite(citizen->name.lastname, sizeof(char), len, file);

        char compressed_info;
        compress_info(&compressed_info, citizen->education_level, citizen->work_status, citizen->marital_status);
        fwrite(&compressed_info, sizeof(char), 1, file);
        
        current = current->next;
        index++;
    }

    fclose(file);
}

void load_data_from_file(const char* filename, LinkedList* list) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return;
    }

    release(list);
    *list = init();

    int index;
    
    while(fread(&index, sizeof(int), 1, file)) {
        Citizen citizen;
        
        fread(citizen.id, sizeof(char), MAX_ID_LENGTH, file);
        citizen.id[MAX_ID_LENGTH] = '\0';

        size_t len;
        
        fread(&len, sizeof(size_t), 1, file);
        fread(citizen.name.firstname, sizeof(char), len, file);
        citizen.name.firstname[len] = '\0';
        
        fread(&len, sizeof(size_t), 1, file);
        fread(citizen.name.surname, sizeof(char), len, file);
        citizen.name.surname[len] = '\0';

        fread(&len, sizeof(size_t), 1, file);
        fread(citizen.name.lastname, sizeof(char), len, file);
        citizen.name.lastname[len] = '\0';

        char compressed_info;
        fread(&compressed_info, sizeof(char), 1, file);

        citizen.education_level = (EducationLevel)((compressed_info >> 0) & 0x03);
        citizen.work_status = (WorkStatus)((compressed_info >> 2) & 0x01);
        citizen.marital_status = (MaritalStatus)((compressed_info >> 3) & 0x01);
        
        pushBack(list, &citizen);
    }

    fclose(file);
}

void add_new_citizen(LinkedList* list) {
    Citizen new_citizen;
    int choice;

    printf("Enter ID (10 characters): ");
    scanf("%10s", new_citizen.id);

    printf("Enter First Name: ");
    scanf("%s", new_citizen.name.firstname);

    printf("Enter Surname: ");
    scanf("%s", new_citizen.name.surname);

    printf("Enter Last Name: ");
    scanf("%s", new_citizen.name.lastname);

    printf("Select Education Level (0: None, 1: Primary, 2: Secondary, 3: Higher): ");
    scanf("%d", &choice);
    new_citizen.education_level = (EducationLevel)choice;

    printf("Select Work Status (0: Unemployed, 1: Employed): ");
    scanf("%d", &choice);
    new_citizen.work_status = (WorkStatus)choice;

    printf("Select Marital Status (0: Single, 1: Married): ");
    scanf("%d", &choice);
    new_citizen.marital_status = (MaritalStatus)choice;

    pushBack(list, &new_citizen);
    printf("New record added.\n");
}

void delete_citizen_by_id(LinkedList* list) {
    char id_to_delete[MAX_ID_LENGTH + 1];
    printf("Enter ID of the citizen to delete: ");
    scanf("%10s", id_to_delete);

    Node* current = list->head;
    Node* prev = NULL;
    bool found = false;

    while (current != NULL) {
        if (strcmp(current->value.id, id_to_delete) == 0) {
            found = true;
            if (prev == NULL) { 
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            list->size--;
            printf("Record with ID %s deleted.\n", id_to_delete);
            break;
        }
        prev = current;
        current = current->next;
    }

    if (!found) {
        printf("No record found with ID %s.\n", id_to_delete);
    }
}

int main(){
    char filename[100];
    printf("Enter filename to open or create: ");
    scanf("%s", filename);

    LinkedList citizens = init();
    load_data_from_file(filename, &citizens);

    int choice = 0;
    do {
        printf("1. Print all records\n");
        printf("2. Add a new record\n");
        printf("3. Delete a record by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                forEach(&citizens, eacher);
                break;
            case 2:
                add_new_citizen(&citizens);
                save_data_to_file(filename, &citizens);
                break;
            case 3:
                delete_citizen_by_id(&citizens);
                save_data_to_file(filename, &citizens);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    release(&citizens);
    return 0;
}