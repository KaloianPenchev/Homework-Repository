#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../linked_list/linkedlist.h"

void save_changes(LinkedList * list){
    FILE * file = fopen("main/books_library.txt", "w");
    check_file_opening(file);

    Node * currentNode = list->head;

    for(sint i = 0; i < (sint)list->size; i++){
        fprintf(file, "%s %s %s %d %s", currentNode->data.name, 
                                        currentNode->data.author, 
                                        currentNode->data.genre, 
                                        currentNode->data.year_of_publication, 
                                        currentNode->data.isbn);
        fprintf(file, "\n");
        currentNode = currentNode->next;
    }

    printf("Changes saved successfuly!");

    fclose(file);
}

void print_books(LinkedList * list){

    Node * currentNode = list->head;

    for(sint i = 0; i < (short int)list->size; ++i){
        printf("\n");

        printf("Book #%hd\n", i + 1);
        printf(" -> Name : %s\n", currentNode->data.name);
        printf(" -> Author : %s\n", currentNode->data.author);
        printf(" -> Genre : %s\n", currentNode->data.genre);
        printf(" -> Year of publication : %lu\n", currentNode->data.year_of_publication);
        printf(" -> ISBN : %s\n", currentNode->data.isbn);

        printf("\n");

        currentNode = currentNode->next;
    }
}

ListDataType * initialize_data(){
    ListDataType * newData = malloc(sizeof(ListDataType));
    check_memory_allocation(newData);
    return newData;
}


void extract_and_push_to_list(LinkedList * list){

    FILE * file = fopen("main/books_library.txt", "r");
    check_file_opening(file);
    
    while (true) {
        ListDataType * newData = initialize_data();

        int items_read = fscanf(file, "%s %s %s %d %s", newData->name, newData->author, newData->genre, &newData->year_of_publication, newData->isbn);
        
        if (items_read == EOF) {
            free(newData);
            break; 
        }
        
        pushFront(list, newData);
    }

    fclose(file);
}

void print_menu(){
    printf("1. Print all books\n");
    printf("2. Add new book\n");
    printf("3. Delete a book\n");
    printf("4. Save changes and exit\n");
}

int main(){
    LinkedList books = initialize();

    extract_and_push_to_list(&books);

    bool flag = true;

    while(flag){
        print_menu();

        int option;

        printf("Enter your choice (1 - 4): ");
        scanf("%d", &option);

        switch (option)
        {
        
        case 1: {
            print_books(&books);
            break;
        }
        
        case 2: {

            ListDataType * newData = initialize_data();

            printf(" -> Name : ");
            scanf("%s", newData->name);

            printf(" -> Author : ");
            scanf("%s", newData->author);

            printf(" -> Genre : ");
            scanf("%s", newData->genre);

            printf(" -> Year : ");
            scanf("%d", &newData->year_of_publication);

            printf(" -> ISBN : ");
            scanf("%s", newData->isbn);

            pushBack(&books, newData);
            
            printf("Added successfuly!\n");

            break;
        }
        
        case 3: {

            char isbn_to_be_deleted[MAX_ISBN_LENGTH + 1];

            printf(" -> Enter isbn : ");
            scanf("%s", &isbn_to_be_deleted);

            int index = find(&books, isbn_to_be_deleted);

            if(index == -1) {
                printf("No book found with this isbn!\n");
                break;
            }

            pop(&books, index);

            printf("Deleted successfuly!\n");

            break;
        }
        
        case 4: {
            save_changes(&books);
            flag = false;
            break;
        }

        default:
            printf("Invalid option!");
            break;
        }
    }

    release(&books);

    return 0;
}