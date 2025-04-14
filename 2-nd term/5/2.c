#include<stdio.h>

enum week{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main(){
    int input_day;

    do{
        printf("Enter a number(1 - 7): ");
        scanf("%d", &input_day);
    }while(input_day < 1 || input_day > 7);

    enum week current_day;
    current_day = input_day;

    switch (input_day)
    {
    case MONDAY:
        printf("It is Monday!");
        break;
    case TUESDAY:
        printf("It is TUESday!");
        break;
    case WEDNESDAY:
        printf("It is Wednesay!");
        break;
    case THURSDAY:
        printf("It is Thursday!");
        break;
    case FRIDAY:
        printf("It is Friday!");
        break;
    case SATURDAY:
        printf("It is Saturday!");
        break;
    case SUNDAY:
        printf("It is Sunday!");
        break;
    default:
        printf("Invalid input!");
        break;
    }

    return 0;
}