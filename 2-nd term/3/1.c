#include <stdio.h>
#include <stdlib.h>

void check_memory(void *ptr) {
    if (ptr == NULL) {
        printf("Error allocating memory!\n");
        free(ptr);
        exit(1);
    }
}

int main() {
    int grades_count;

    printf("Enter your grades count: ");
    scanf("%d", &grades_count);

    while (grades_count <= 0) {
        printf("Enter valid grades count: ");
        scanf("%d", &grades_count);
    }

    float *grades = (float *)malloc(grades_count * sizeof(float));
    check_memory(grades);

    for (int i = 0; i < grades_count; i++) {
        do {
            printf("Enter grade № %d: ", i + 1);
            scanf("%f", &grades[i]);
        } while (grades[i] < 2.00 || grades[i] > 6.00);
    }

    int option, flag = 1;

    do {
        printf("\nChoose an option:\n");
        printf("1. Calculate Average Grade\n");
        printf("2. Add a New Grade\n");
        printf("3. Delete Last Grade\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {

                float sum = 0;
                for (int i = 0; i < grades_count; i++) {
                    sum += grades[i];
                }
                float avrg = sum / grades_count;
                printf("Average grade: %.2f\n", avrg);
                break;
            }

            case 2: {
                grades_count++;
                grades = (float *)realloc(grades, grades_count * sizeof(float));
                check_memory(grades);

                do {
                    printf("Enter new grade: ");
                    scanf("%f", &grades[grades_count - 1]);
                } while (grades[grades_count - 1] < 2.00 || grades[grades_count - 1] > 6.00);

                break;
            }

            case 3:
                if (grades_count <= 0) {
                    printf("Error! You cannot delete a grade!\n");
                } else {
                    grades_count--;
                    if (grades_count > 0) {
                        grades = (float *)realloc(grades, grades_count * sizeof(float));
                        check_memory(grades);
                    } else {
                        free(grades);
                        grades = NULL;
                    }
                    printf("Successfully deleted the last grade!\n");
                }
                break;

            case 4:
                flag = 0;
                break;

            default:
                printf("Invalid option!\n");
                break;
        }

    } while (flag);

    free(grades);  
    return 0;
}
