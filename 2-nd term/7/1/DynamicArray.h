#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef int DynArrType;
typedef unsigned long ul;

typedef struct {
  DynArrType * buffer;
  ul size;
  ul capacity;
} DynamicArray;

DynamicArray init(ul capacity);

void pushBack(DynamicArray * dynArr, DynArrType value);
void pushFront(DynamicArray * dynArr, DynArrType value);
void push(DynamicArray * dynArr, ul index, DynArrType value);

DynArrType popBack(DynamicArray * dynArr);
DynArrType popFront(DynamicArray * dynArr);
DynArrType pop(DynamicArray * dynArr, ul index);

DynArrType get(DynamicArray * dynArr, ul index);
void set(DynamicArray * dynArr, ul index, DynArrType value);

void release(DynamicArray * dynArr);

ul find(DynamicArray * dynArr, DynArrType value);

#endif