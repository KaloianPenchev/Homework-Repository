#include<stdio.h>
#include "DynamicArray.h"

typedef enum{
    false,
    true
} Bool;

void print_array(DynamicArray * array){
    for(int i = 0; i < array->size; i++){
        printf("# %d : %lu\n", i + 1, array->buffer[i]);
    }
}

void print_menu(){
    printf("1. Enter new donator\n");
    printf("2. Remove a donator\n");
    printf("3. Print all donators\n");
    printf("4. Exit\n");
}

int main(){

    DynamicArray dynArr = init(0);
    
    Bool flag = true;

    print_menu();

    while(flag){
        
        int option;

        printf("Enter your choice(1, 2, 3, 4): ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:{

            ul id_to_be_added;
            printf("Enter id: ");
            scanf("%lu", &id_to_be_added);
            pushBack(&dynArr, id_to_be_added);
            printf("Added successfuly!\n");
            break;
        }
        case 2:{
            ul id_to_be_deleted;
            printf("Enter id: ");
            scanf("%lu", &id_to_be_deleted);
            ul idx = find(&dynArr, id_to_be_deleted);

            if(idx == -1){
                printf("No donator found with ID of %lu!\n", id_to_be_deleted);
                break;
            }

            pop(&dynArr, idx);
            printf("Deleted successfuly!\n");
            break;
        }
        case 3:{
            print_array(&dynArr);
            break;
        }
        case 4:{
            flag = false;
            printf("Exiting...");
            break;
        }
        default:
            printf("Invalid option!");
            break;
        }
    }

    release(&dynArr);
}