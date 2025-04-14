#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSZ 15

void check_memory(void *ptr) {
    if (ptr == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }
}

void clean_buffer() {
    while (getchar() != '\n');
}

int main() {

    int subjects_count;
    printf("Enter subjects count: ");
    scanf("%d", &subjects_count);
    clean_buffer();

    
    char **subjects = malloc(subjects_count * sizeof(char *));
    check_memory(subjects);


    for (int i = 0; i < subjects_count; i++) {
        char subject[MAXSZ];

        printf("Enter subject: ");
        fgets(subject, sizeof(subject), stdin);

        int length = strlen(subject);
        subject[length - 1] = '\0';

        subjects[i] = malloc((length) * sizeof(char));
        check_memory(subjects[i]);
        strcpy(subjects[i], subject);
    }

    int students_count = 0; 

    char **students = NULL;
    int **diary = NULL;

    int flag = 1;

    while (flag) {
        printf("1. Add a student\n");
        printf("2. Delete last student\n");
        printf("3. Print diary\n");
        printf("4. Exit\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clean_buffer();

        switch (choice) {
        case 1:
            students_count++;
            students = realloc(students, students_count * sizeof(char *));
            check_memory(students);

            diary = realloc(diary, students_count * sizeof(int *));
            check_memory(diary);

            char student[MAXSZ];

            printf("Enter student name: ");
            fgets(student, sizeof(student), stdin);

            int len = strlen(student);
            student[len - 1] = '\0';

            int idx = students_count - 1;

            students[idx] = malloc(len * sizeof(char));
            check_memory(students[idx]);
            strcpy(students[idx], student);

            diary[idx] = malloc(subjects_count * sizeof(int));
            check_memory(diary[idx]);

            for (int i = 0; i < subjects_count; i++) {
                printf("Enter %s's grade for %s: ", students[idx], subjects[i]);
                scanf("%d", &diary[idx][i]);
            }

            printf("Student added successfully!\n");
            break;

        case 2:
            if (students_count == 0) {
                printf("No students to delete!\n");
                break;
            }

            students_count--;

            students = realloc(students, students_count * sizeof(char *));
            check_memory(students);

            diary = realloc(diary, students_count * sizeof(int *));
            check_memory(diary);

            printf("Last student deleted successfully!\n");
            break;

        case 3:
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
            printf("\n");
            break;

        case 4:
            flag = 0;
            break;

        default:
            printf("Invalid option!\n");
            break;
        }
    }

    for (int i = 0; i < students_count; i++) {
        free(diary[i]);
        free(students[i]);
    }

    free(diary);
    free(students);

    for (int i = 0; i < subjects_count; i++) {
        free(subjects[i]);
    }

    free(subjects);

    return 0;
}
