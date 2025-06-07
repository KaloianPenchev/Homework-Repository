#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../util/util.h"
#include "../linked_list/linkedlist.h"

void print(uint index, ListDataType * value) {
    printf("\nCitizen #%u:\n", index + 1);
    printf("  ID: %s\n", value->id);
    printf("  Name: %s %s %s\n", value->name.firstname, value->name.surname, value->name.lastname);
    printf("  Education: %s\n", education_level_to_string(value->education_level));
    printf("  Work Status: %s\n", work_status_to_string(value->work_status));
    printf("  Marital Status: %s\n", marital_status_to_string(value->marital_status));
    printf("\n");
}

ListDataType * initialize_data(){
    ListDataType * newData = malloc(sizeof(ListDataType));
    assert_memory_allocation(newData);
    return newData;
}

void extract_and_push_to_list(LinkedList * list){
    FILE * file = fopen("main/citizens.bin", "wb+");
    assert_file_opening(file);

    while(true){
        ListDataType * newData = initialize_data();

        if(
            fread(newData->id, sizeof(char), MAX_ID_LENGTH, file) &&
            fread(newData->name.firstname, sizeof(char), MAX_NAME_LENGTH, file) &&
            fread(newData->name.surname, sizeof(char), MAX_NAME_LENGTH, file) &&
            fread(newData->name.lastname, sizeof(char), MAX_NAME_LENGTH, file) &&
            fread(&newData->education_level, sizeof(int), 1, file) &&
            fread(&newData->work_status, sizeof(int), 1, file) &&
            fread(&newData->marital_status, sizeof(int), 1, file)
        ){
            pushFront(list, newData);
        }
        else{
            free(newData);
            break;
        }
        
    }

    fclose(file);
}

void test(){
    FILE * file = fopen("main/citizens.bin", "wb+");
    assert_file_opening(file);

    Citizen new_citizen = {
        .id = "123",
        .name = {
            .firstname = "po",
            .surname = "wo",
            .lastname = "wp"
        },
        .education_level = 0,
        .marital_status = 0,
        .work_status = 0
    };

    fwrite(&new_citizen, sizeof(Citizen), 1, file);

    fclose(file);
}

int main(){

    LinkedList citizens = init();

    //test();

    extract_and_push_to_list(&citizens);

    forEach(&citizens, print);

    /*bool flag = true;

    while(flag){
        
    }*/


    return 0;
}