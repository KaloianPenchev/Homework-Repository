#include <stdio.h>
#include <string.h>
#include "../linked_list/linkedlist.h"
#include "../compress_util/compress_util.h"
#include "../error/error.h"

void fill(){
    FILE * file = fopen("citizens.bin", "wb");
    assert_file_opening(file);

    // We will fill the file with 10 citizens (even thought they are the same)

    Citizen citizen = {
        .id = "1234567899",
        .name.firstname = "Jone     ",
        .name.surname = "Smith     ",
        .name.lastname = "Doe      ",
        .education_level = EDUCATION_PRIMARY,
        .work_status = WORK_EMPLOYED,
        .marital_status = MARITAL_MARRIED
    };

    for(int i = 0; i < 10; ++i){
        fwrite(&i, sizeof(int), 1, file);
        fwrite(citizen.id, sizeof(char), MAX_ID_LENGTH, file);
        
        remove_spaces(citizen.name.firstname);
        size_t len = strlen(citizen.name.firstname);
        fwrite(&len, sizeof(size_t), 1, file);
        fwrite(citizen.name.firstname, sizeof(char), len, file);
        
        remove_spaces(citizen.name.surname);
        len = strlen(citizen.name.surname);
        fwrite(&len, sizeof(size_t), 1, file);
        fwrite(citizen.name.surname, sizeof(char), len, file);
        
        remove_spaces(citizen.name.lastname);
        len = strlen(citizen.name.lastname);
        fwrite(&len, sizeof(size_t), 1, file);
        fwrite(citizen.name.lastname, sizeof(char), len, file);

        char compressed_info;

        compress_info(&compressed_info, (int)citizen.education_level, (int)citizen.work_status, (int)citizen.marital_status);

        fwrite(&compressed_info, sizeof(char), 1, file);
    }
    
    fclose(file);
}

int main(){
    //LinkedList citizens = init();
    //extract_and_push_to_list(&citizens);

    /*
    
    Serialize data format:
    
    1 - index of the node - int
    2 - id of the patient - string
    3 - firstname - string
    4 - surname - strig
    5 - lastname - string
    
    ! The id won't be compressed, because it has a fixed lenght of 10 chars
    ! The 3 names will be compressed, because they don't have fixed size. They can be up to 255 chars (by default).

    6 - education_level ; work_status ; marital_status - char

    The sixth one (6) is stored in a char to save memory.
    Additionally, we won't use the whole char size 8(bits), instead we will use
    only 4 bits (2 + 1 + 1):
    
    1) Education level has 4 options, i.e we need 2 bits 
        * 00 - EDUCATION_NONE
        * 01 - EDUCATION_PRIMARY
        * 10 - EDUCATION_SECONDARY
        * 11 - EDUCATION_HIGHER 
    2) Work status has 2 options, i.e. we need 1 bit
        * 0 - WORK_UNEMPLOYED
        * 1 - WORK_EMPLOYED
    3) Maritial status has 2 options, i.e. we need 1 bit
        * 0 - MARITAL_SINGLE
        * 1 - MARITAL_MARRIED
    
    The order of the bits (from right to left): 
    1) Education Level (2 bits)
    2) Work Status (1 bit)
    3) Maritial Statues (1 bit)
    
    For example, let's say we want to store person who has:
    - education level -> Secondary
    - work status -> Employed
    - marital status -> Single

    Our char will be : 0000 0(Single) 1(Employed) 10(Secondary) -> 0000 0110

    ! The first 4 bits are always 0s , since we don't need them.
    

    */


    fill();

    return 0;
}