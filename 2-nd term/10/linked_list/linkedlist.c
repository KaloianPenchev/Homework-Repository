#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "../error/error.h"

LinkedList init(){
    LinkedList new_list = {
        .head = NULL,
        .size = 0
    };

    return new_list;
}

static Node * createNode(ListDataType * value){
    Node * newNode = malloc(sizeof(Node));
    assert_memory_allocation(newNode);

    newNode->next = NULL;
    newNode->value = *value;

    return newNode;
}

static Node * getNode(LinkedList * list, uint index){
    Node * currentNode = list->head;

    for(int i = 0; i < index; ++i){
        currentNode = currentNode->next;
    }

    return currentNode;
}

void pushFront(LinkedList * list, ListDataType * value){
    Node * node_to_be_added = createNode(value);

    node_to_be_added->next = list->head;
    list->head = node_to_be_added;

    list->size++;
}

void push(LinkedList * list, uint index, ListDataType * value){
    assert_index(list->size, index);

    if(index == 0){
        pushFront(list, value);
    }
    else{
        Node * node_to_be_added = createNode(value);
        Node * prev_node = getNode(list, index - 1);

        node_to_be_added->next = prev_node->next;
        prev_node->next = node_to_be_added;

        list->size++;
    }
}
void pushBack(LinkedList * list, ListDataType * value){
    push(list, list->size, value);
}

void popFront(LinkedList * list){
    Node * node_to_be_deleted = getNode(list, 0);

    list->head = node_to_be_deleted->next;
    
    free(node_to_be_deleted);
    node_to_be_deleted->next = NULL;

    list->size--;

}

void pop(LinkedList * list, uint index){
    assert_index(list->size, index);

    if(index == 0){
        popFront(list);
    }
    else{
        Node * node_to_be_deleted = getNode(list, index);
        Node * prev_node = getNode(list, index - 1);

        prev_node->next = node_to_be_deleted->next;

        free(node_to_be_deleted);
        node_to_be_deleted->next = NULL;

        list->size--;
    }
}

void popBack(LinkedList * list){
    if (list->size == 0) {
        return;
    }

    pop(list, list->size - 1);
}


void forEach(LinkedList * list, Callback operation){
    Node * currentNode = list->head;

    for(int i = 0; i < list->size; i++){
        operation(i, &currentNode->value);
        currentNode = currentNode->next;
    }
}

void release(LinkedList * list){
    while(list->size){
        popFront(list);
    }
    list->head = NULL;
}