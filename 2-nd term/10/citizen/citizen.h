#ifndef CITIZEN_H
#define CITIZEN_H

#define MAX_ID_LENGTH 10
#define MAX_NAME_LENGTH 255


typedef enum {
    EDUCATION_NONE,       
    EDUCATION_PRIMARY,    
    EDUCATION_SECONDARY,  
    EDUCATION_HIGHER      
} EducationLevel;


typedef enum {
    WORK_UNEMPLOYED,      
    WORK_EMPLOYED         
} WorkStatus;


typedef enum {
    MARITAL_SINGLE,       
    MARITAL_MARRIED      
} MaritalStatus;


typedef struct {
    char id[MAX_ID_LENGTH + 1];
    struct {
        char firstname[MAX_NAME_LENGTH + 1];
        char surname[MAX_NAME_LENGTH + 1];
        char lastname[MAX_NAME_LENGTH + 1];
    } name;
    EducationLevel education_level;
    WorkStatus work_status;
    MaritalStatus marital_status;
} Citizen;


#endif