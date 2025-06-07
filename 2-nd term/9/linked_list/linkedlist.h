#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "../book/book.h"
#include "../util/util.h"

typedef Book ListDataType;
typedef unsigned int uint;
typedef short int sint;

typedef struct node {
    ListDataType data;
    struct node * next;
} Node;

typedef struct {
    Node * head;
    uint size;
} LinkedList;

LinkedList initialize();

void pushBack(LinkedList * list, ListDataType * data);
void pushFront(LinkedList * list, ListDataType * data);
void push(LinkedList * list, uint index, ListDataType * data);

int find(LinkedList * list, char isbn[]);

void popBack(LinkedList * list);
void popFront(LinkedList * list);
void pop(LinkedList * list, uint index);

void release(LinkedList * list);

#endif