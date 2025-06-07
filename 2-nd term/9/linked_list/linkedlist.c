#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

LinkedList initialize(){
    LinkedList newList = {
        .head = NULL,
        .size = 0
    };

    return newList;
}

static Node * createNode(ListDataType * data){
    Node * newNode = malloc(sizeof(Node));
    check_memory_allocation(newNode);

    newNode->data = * data;
    newNode->next = NULL;

    return newNode;
}

static Node * getNode(LinkedList * list, uint index){
    check_index_bounds(list->size, index);

    Node * currentNode = list->head;

    for(int i = 0; i < index; i++){
        currentNode = currentNode->next;
    }

    return currentNode;
}

void pushFront(LinkedList * list, ListDataType * data){
    Node * newNode = createNode(data);
    
    newNode->next = list->head;
    list->head = newNode;

    ++list->size;
}

void push(LinkedList * list, uint index, ListDataType * data){
    check_index_bounds(list->size, index);

    if(index == 0){
        pushFront(list, data);
        return;
    }

    Node * newNode = createNode(data);
    Node * prevNode = getNode(list, index - 1);

    newNode->next = prevNode->next;
    prevNode->next = newNode;

    ++list->size;
}

void pushBack(LinkedList * list, ListDataType * data){
    push(list, list->size, data);
}

int find(LinkedList * list, char isbn[]){
    Node * currentNode = list->head;

    for(int i = 0; i < list->size; i++){
        
        if(strcmp(currentNode->data.isbn, isbn) == 0){
            return i;
        }
        
        currentNode = currentNode->next;
    }

    return -1;
}

void popFront(LinkedList * list){
    Node * nodeToDelete = getNode(list, 0);

    list->head = nodeToDelete->next;
    
    free(nodeToDelete);

    --list->size;

}

void pop(LinkedList * list, uint index){
    check_index_bounds(list->size, index);

    if(index == 0){
        popFront(list);
        return;
    }

    Node * prevNode = getNode(list, index - 1);
    Node * nodeToDelete = prevNode->next;

    prevNode->next = nodeToDelete->next;

    free(nodeToDelete);

    --list->size;
}

void popBack(LinkedList * list){
    if (list->size == 0) {
        return;
    }
    
    pop(list, list->size - 1);
}

void release(LinkedList * list){
    while(list->size){
        popFront(list);
    }

    list->head = NULL;
}