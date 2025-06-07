#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

typedef enum{
    false,
    true
} Bool;

void printLinkedList(LinkedList * linkedList) {
  if (linkedList->size == 0) {
    printf("No tasks in the list.\n");
    return;
  }

  Node * currentNode = linkedList->head;
       
  while (currentNode != NULL) {
    printf("Priority: %d | ", currentNode->value.priority);
    printf("Task: %s | ", currentNode->value.task);
    printf("Status: ");
    switch(currentNode->value.status) {
      case NEW:
        printf("New");
        break;
      case STARTED:
        printf("Started");
        break;
      case FINISHED:
        printf("Finished");
        break;
      default:
        printf("Unknown");
    }
    printf("\n");
    currentNode = currentNode->next;
  }
  printf("\n");
}

void print_menu(){
    printf("1. Add new task\n");
    printf("2. Change task status\n");
    printf("3. Print all tasks\n");
    printf("4. Delete task\n");
    printf("5. Exit\n");
}

void updatePriorities(LinkedList * list) {
    Node * current = list->head;
    int priority = 1;
    
    while (current != NULL) {
        current->value.priority = priority++;
        current = current->next;
    }
}

int main(){
    LinkedList linkedList = init();
    Bool flag = true;

    while(flag){
        print_menu();
        
        int option;
        printf("Enter your choice(1, 2, 3, 4, 5): ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:{
            char new_task[MAX_TASK_LENGHT];
            printf("Enter the new task name: ");
            getchar();
            fgets(new_task, MAX_TASK_LENGHT, stdin);
            new_task[strcspn(new_task, "\n")] = 0;
            
            uint priority;
            printf("Enter the task priority: ");
            scanf("%d", &priority);

            ListType task;
            strncpy(task.task, new_task, MAX_TASK_LENGHT);
            task.status = NEW;
            task.priority = priority;

            if (priority > linkedList.size) {
                task.priority = linkedList.size + 1;
                pushBack(&linkedList, task);
            } else if (priority <= 0) {
                task.priority = 1;
                pushFront(&linkedList, task);
            } else {
                push(&linkedList, priority - 1, task);
            }
            
            updatePriorities(&linkedList);
            printf("Task added successfully!\n");

            break;
        }
        
        case 2:{
            if (linkedList.size == 0) {
                printf("No tasks available to change status.\n");
                break;
            }
            
            uint priority_to_be_changed;
            printf("Enter the priority of the task: ");
            scanf("%d", &priority_to_be_changed);

            if (priority_to_be_changed <= 0 || priority_to_be_changed > linkedList.size) {
                printf("Invalid priority! Must be between 1 and %d.\n", linkedList.size);
                break;
            }

            uint new_status;
            printf("Enter new status (0-New, 1-Started, 2-Finished): ");
            scanf("%d", &new_status);
            
            if (new_status > 2) {
                printf("Invalid status! Must be 0, 1, or 2.\n");
                break;
            }

            ListType task = get(&linkedList, priority_to_be_changed - 1);
            task.status = new_status;
            set(&linkedList, priority_to_be_changed - 1, task);

            printf("Status changed successfully!\n");
            
            break;
        }
        
        case 3:{
            printLinkedList(&linkedList);
            break;
        }
        
        case 4:{
            if (linkedList.size == 0) {
                printf("No tasks available to delete.\n");
                break;
            }
            
            uint priority_to_be_deleted;
            printf("Enter the priority of the task to delete: ");
            scanf("%d", &priority_to_be_deleted);

            if (priority_to_be_deleted <= 0 || priority_to_be_deleted > linkedList.size) {
                printf("Invalid priority! Must be between 1 and %d.\n", linkedList.size);
                break;
            }

            pop(&linkedList, priority_to_be_deleted - 1);
            updatePriorities(&linkedList);

            printf("Task deleted successfully!\n");

            break;
        }
        case 5:{
            flag = false;
            printf("Exiting...\n");
            break;
        }
        default:
            printf("Invalid option!\n");
            break;
        }
    }

    release(&linkedList);
    return 0;
}