#ifndef NODE_H

#define NODE_H
#include <stdlib.h>

typedef struct Node
{
    /* data */
    int val;
    struct Node* next;
} Node;



typedef Node * Nodeptr;


/* functions */
Nodeptr Node_new(int val);
void Node_init(Nodeptr n, int val);
int Node_getValue(Nodeptr n);
void Node_setValue(Nodeptr n, int value);
void Node_setNext(Nodeptr self, Nodeptr next);
void Node_reset(Nodeptr n);
void Node_destroy(Nodeptr n);



/*

    OLD NODE CODE
    - Uses previous way of object oriented coding

*/
// // NOTE: This header file is just the declaration of the class sstruct, the 'object' creation definition, and nothing else.

// // This struct can be seen as the Class Definition w/ all of it's variables and methods being DECLARED here
// struct Node
// {
//     // Class Variables
//     int val;
//     struct Node* next; 

//     // Class Methods
//     int (*checkValue)(struct Node *this);
//     void (*setNext)(struct Node *this, struct Node* n);
//     void (*toString)(struct Node *this);
// };

// // This struct can be seen as the struct that is used to help CREATE the actual class that we want
// extern const struct NodeClass
// {
//     struct Node (*new)(int value, int id);
//     // For a constructor that doesn't require any arguments, it would look like this:
//     // struct <CLASS_NAME> (*new)(void);
// } Node;

#endif