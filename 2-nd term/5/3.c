#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char name[16];
    int class_number;
    double average_grade;
}student;

void check_memory(void *ptr){
    if(ptr == NULL){
        printf("Error allocating memory!\n");
        exit(1);
    }
}

void print_menu(){
    printf("1. Add new student\n");
    printf("2. List all students\n");
    printf("3. Exit\n");
}

int main(){
    int students_count = 0;
    
    int option, flag = 1;

    student * students;

    print_menu();

    do{
        printf("Enter your choice(1 - 3): ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            students_count++;

            students = realloc(students, students_count * sizeof(student));
            check_memory(students);

            student new_student;

            printf("Enter the name of the student: ");
            scanf("%s", &new_student.name);

            printf("Enter the class number of the student: ");
            scanf("%d", &new_student.class_number);

            printf("Enter the average grade of the student: ");
            scanf("%lf", &new_student.average_grade);

            int idx = students_count - 1;
            students[idx] = new_student;

            break;
        
        case 2:
            
            for(int i = 0; i < students_count; i++){
                printf("\n");
                printf("Student # %d\n", i + 1);
                printf("%s\n", students[i].name);
                printf("%d\n", students[i].class_number);
                printf("%lf\n", students[i].average_grade);
            }

            break;
        
        case 3:
            printf("Exiting...\n");
            flag = 0;
            break; 
        }

    }while(flag);

    free(students);

    return 0;
}