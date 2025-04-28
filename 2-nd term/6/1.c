#include<stdio.h>
#include<string.h>

#define MAX_TITLE_LENGHT 100
#define MAX_DESCRIPTION_LENGHT 500
#define MAX_COMMENTS_LENGHT 100
#define MAX_NAME_LENGHT 100
#define MAX_EMAIL_LENGHT 500
#define MAX_PHONE_NUMBER_LENGHT 20

typedef enum{
    true,
    false
} Bool;

typedef struct {
    char firstname[MAX_NAME_LENGHT + 1];
    char lastname[MAX_NAME_LENGHT + 1];
    char surname[MAX_NAME_LENGHT + 1];
    char email[MAX_EMAIL_LENGHT + 1];
    char phone_number[MAX_PHONE_NUMBER_LENGHT + 1];
} Student;

typedef struct {
    Student *student;
    Bool isEngaged;
} StudentComment;

typedef struct {
    char title[MAX_TITLE_LENGHT + 1];
    char description[MAX_DESCRIPTION_LENGHT + 1];
    struct {
        struct {
            int hour;
            int minutes;
        } hour;
        int day;
        int month;
        int year;
    } date;
    int comments_count;
    StudentComment *comments[MAX_COMMENTS_LENGHT];
} Cause;

void print_student(Student *student){
    printf("\n");
    printf("Student Details\n");
    printf("Firstname: %s\n", student->firstname);
    printf("Lastname: %s\n", student->lastname);
    printf("Surname: %s\n", student->surname);
    printf("Email: %s\n", student->email);
    printf("Phone number: %s\n", student->phone_number);
}

void print_comment(StudentComment *comment){
    print_student(comment->student);
    printf("Participant: %s\n", comment->isEngaged ? "true" : "false");
}

void print_date(Cause *cause){
    printf("Hour: %d:%d\n", cause->date.hour.hour, cause->date.hour.minutes);
    printf("Date: %d/%d/%d\n", cause->date.day, cause->date.month, cause->date.year);
}

void print_header(Cause *cause){
    printf("Title: %s\n", cause->title);
    printf("Description: %s\n", cause->description);
}

void print_structs(int causes_count, Cause causes[]){
    printf("\n");
    
    for(int i = 0; i < causes_count; i++){
        printf("||Cause #%d||\n", i + 1);
        print_header(&causes[i]);
        print_date(&causes[i]);
        
        for(int j = 0; j < causes[i].comments_count; j++){
            printf("\n");
            printf("|Comment #%d|", j + 1);
            print_comment(causes[i].comments[j]);
        }

        printf("\n");
    }
}

void create_and_print_structs(){
    
    Student ivo = {
        "Ivo",
        "Petrov",
        "Dimitrov",
        "ivo@gmail.com",
        "+359 34 996 534"
    };
    
    Student petar = {
        "Petar",
        "Nikolov",
        "Spasov",
        "petar@gmail.com",
        "+359 34 223 343"
    };

    StudentComment first_comment = {
        &ivo,
        true
    };
    
    StudentComment second_comment = {
        &ivo,
        false
    };

    StudentComment third_comment = {
        &petar,
        false
    };
    
    StudentComment fourth_comment = {
        &petar,
        true
    };

    Cause education = {
        "Education in Bulgaria",
        "This cause was created to help students from Bulgaria.",
        {
            {
                15,
                30
            },
            15,
            9,
            2025
        },
        2,
        {
            &first_comment, &third_comment
        }
        
    };
    
    Cause health = {
        "Health in Bulgaria",
        "This cause was created to raise money for people with disabilities.",
        {
            {
                17,
                45
            },
            21,
            11,
            2025
        },
        2,
        {
            &second_comment, &fourth_comment
        }
    };

    Cause causes[2] = {education, health};
    print_structs(2, causes);
}

int main(){
    create_and_print_structs();
}