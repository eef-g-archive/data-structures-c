#ifndef LIST_H

#define LIST_H
#include "node.h"
#include <stdlib.h>

typedef struct List
{
    /* data */
    Nodeptr head;
    Nodeptr tail;
    int len;
} List;

typedef List * Listptr;

Listptr List_new();
void List_init(Listptr l);
void List_addValue(Listptr self, void* val, dataType type);
void List_printList(Listptr self);
Nodeptr List_walkToIndex(Listptr self, int index);
Nodeptr List_findNodebyValue(Listptr self, void* val);
void List_insert(Listptr self, int index, void* val, dataType type);
void List_removeAt(Listptr self, int index);
void List_clear(Listptr self);
void List_destroy(Listptr self);

#endif