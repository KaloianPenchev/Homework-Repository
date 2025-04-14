#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 15

void check_memory(void *ptr) {
    if (ptr == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }
}

void clear_buffer() {
    while (getchar() != '\n');
}

int main() {
    int subjects_count;

    printf("Enter your subjects count: ");
    scanf("%d", &subjects_count);
    clear_buffer();

    if (subjects_count <= 0) {
        printf("Invalid number of subjects!\n");
        return 1;
    }

  
    char **subjects = malloc(sizeof(char *) * subjects_count);
    check_memory(subjects);

    for (int i = 0; i < subjects_count; i++) {
        char subject[SIZE];

        printf("Enter the name of subject № %d: ", i + 1);
        fgets(subject, SIZE, stdin);
        
        int lenght = strlen(subject);
        subject[lenght - 1] = '\0'; 

        subjects[i] = malloc(lenght * sizeof(char));
        check_memory(subjects[i]);
        strcpy(subjects[i], subject);
    }

    int option, flag = 1, students_count = 0;
    
    char **students = NULL;
    int **diary = NULL;

    do {
        printf("\nChoose an option:\n");
        printf("1. Add a student\n");
        printf("2. Print diary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        clear_buffer(); 

        switch (option) {
            case 1: {
                students_count++;
                students = realloc(students, students_count * sizeof(char *));
                check_memory(students);

                char student[SIZE];

                printf("Enter the name of the student: ");
                fgets(student, SIZE, stdin);

                int ln = strlen(student);

                student[ln - 1] = '\0';

                int idx = students_count - 1;

                students[idx] = malloc((strlen(student) + 1) * sizeof(char));
                check_memory(students[idx]);
                strcpy(students[idx], student);

                
                diary = realloc(diary, students_count * sizeof(int *));
                check_memory(diary);
                diary[idx] = malloc(subjects_count * sizeof(int));
                check_memory(diary[idx]);

                for (int i = 0; i < subjects_count; i++) {
                    printf("Enter %s's grade for %s: ", students[idx], subjects[i]);
                    scanf("%d", &diary[idx][i]);
                }

                printf("Student saved successfully!\n");
                clear_buffer();
                break;
            }

            case 2: {
                if (students_count == 0) {
                    printf("No students have been added yet.\n");
                    break;
                }

                printf("\n%-15s", "Name");
                for (int i = 0; i < subjects_count; i++) {
                    printf("%-15s", subjects[i]);
                }
                printf("\n");

                for (int i = 0; i < students_count; i++) {
                    printf("%-15s", students[i]);
                    for (int j = 0; j < subjects_count; j++) {
                        printf("%-15d", diary[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            case 3:
                flag = 0;
                break;

            default:
                printf("Invalid option!\n");
                break;
        }
    } while (flag);

    
    for (int i = 0; i < subjects_count; i++) {
        free(subjects[i]);
    }
    free(subjects);

    for (int i = 0; i < students_count; i++) {
        free(students[i]);
        free(diary[i]);
    }
    free(students);
    free(diary);

    return 0;
}
