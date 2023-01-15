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
void List_addValue(Listptr self, int val);
void List_printList(Listptr self);
void List_removeIndex(Listptr self, int index);



/*
    OLD LIST CODE
    - Uses old OOP method
*/

// // NOTE: This header file is just the declaration of the class sstruct, the 'object' creation definition, and nothing else.

// // This struct can be seen as the Class Definition w/ all of it's variables and methods being DECLARED here
// struct List
// {
//     // Class Variables
//     struct Node* head;
//     struct Node* tail; 
//     int len;

//     // Class Methods
//     void (*addValue)(struct List *this, int val);
//     void (*printList)(struct List *this);
// };

// // This struct can be seen as the struct that is used to help CREATE the actual class that we want
// extern const struct ListClass
// {
//     struct List (*new)(void);
//     // For a constructor that doesn't require any arguments, it would look like this:
//     // struct <CLASS_NAME> (*new)(void);
// } List;

#endif