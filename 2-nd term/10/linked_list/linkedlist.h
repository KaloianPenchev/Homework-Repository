#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../citizen/citizen.h"

typedef Citizen ListDataType;
typedef unsigned int uint;

typedef struct node{
    ListDataType value;
    struct node * next;
} Node;

typedef struct {
    Node * head;
    uint size;
} LinkedList;

LinkedList init();

void push(LinkedList * list, uint index, ListDataType * value);
void pushBack(LinkedList * list, ListDataType * value);
void pushFront(LinkedList * list, ListDataType * value);

void pop(LinkedList * list, uint index);
void popBack(LinkedList * list);
void popFront(LinkedList * list);

typedef void (* Callback)(uint, ListDataType * value);

void forEach(LinkedList * list, Callback operation);

void release(LinkedList * list);

#endif